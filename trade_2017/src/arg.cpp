//
// EPITECH PROJECT, 2018
// arg.cpp
// File description:
// 
//

#include <stdlib.h>
#include "../include/arg.hpp"

/*Création de l'objet contenant les arguments puis remplissage*/
Arg::Arg(int period, float sd_coef, char *str, int index)
{
	this->Period = period;
	this->SD_Coef = sd_coef;
	this->Fname = str;
	this->Index = index;
}

/*Destruction de l'objet contenant les arguments*/
Arg::~Arg()
{
}

/*Récupération de la periode*/
int	Arg::getPeriod()
{
	return this->Period;
}

/*Récupération du sd coef*/
float	Arg::getSD_Coef()
{
	return this->SD_Coef;
}

/*Récupération du nom du ficher*/
char	*Arg::getFname()
{
	return this->Fname;
}

/*Récupération de l'Index*/
int	Arg::getIndex()
{
	return this->Index;
}

