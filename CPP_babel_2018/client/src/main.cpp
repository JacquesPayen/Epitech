//
// EPITECH PROJECT, 2018
// main.cpp
// File description:
// 
//

#include "../include/port_audio.hpp"
#include "../include/opus.hpp"
#include "protocol.hpp"
#include <thread>
#include <unistd.h>
#include "mainwindow.h"
#include <QApplication>

void	soundThread(udpNetwork *udpNet)
{
	char	*datas;
	float	*data;
	float	*res;
	Opus	opus;
	Sound	record;

	record.recordSound();
	data = record.getSound();
	while (udpNet->isInCall) {
        	data = record.getSound();
		datas = opus.encodeSound(data);
		udpNet->writeSocket(datas);
	}
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}