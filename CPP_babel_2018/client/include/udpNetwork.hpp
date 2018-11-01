#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QMainWindow>
#include <thread>
#include "tcpNetwork.hpp"
#include "opus.hpp"

class udpNetwork : public QWidget
{
Q_OBJECT
public:
	udpNetwork();
	~udpNetwork();
	void setPort(const int&);
	void connectSocket() const;
	void writeSocket(char*) const;
	void setSenderAddress(const std::string&);
	void setSenderPort(const int&);
	bool	isInCall = false;

public slots:
	void	readSocket();

private:
	QUdpSocket* _socket = nullptr;
	QHostAddress _senderAddress;
	quint16 _senderPort = 0;
	quint16 _port = 0;
	std::thread	*_sdound = nullptr;
	Opus	_opus;
	Sound	_play;
};

void	soundThread(udpNetwork*);

#endif
