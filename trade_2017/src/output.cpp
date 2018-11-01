//
// EPITECH PROJECT, 2018
// output.cpp
// File description:
// 
//

#include "../include/output.hpp"
#include "../include/calcul.hpp"


/*Création de l'objet output avec remplissage des informations de celui-ci*/
Output::Output(Arg info, std::vector <float> list)
{
	this->Ma = my_mov_average(list, info.getIndex(), info.getPeriod());
	this->Sd = my_std_dev(list, info.getIndex(), info.getPeriod(), this->Ma);
	this->Bp = calcBp(this->Ma, this->Sd, info.getSD_Coef());
	this->Bm = calcBm(this->Ma, this->Sd, info.getSD_Coef());
}

/*Destruction de l'objet output*/
Output::~Output()
{
}

/*Récupération de la moyenne*/
float	Output::getMa()
{
	return this->Ma;
}

/*Récupération de SD*/
float	Output::getSd()
{
	return this->Sd;
}

/*Récupération de BP*/
float	Output::getBp()
{
	return this->Bp;
}

/*Récupération de BM*/
float	Output::getBm()
{
	return this->Bm;
}
