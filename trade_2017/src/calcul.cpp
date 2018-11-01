/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

/*Calcule de la moyenne mobile*/
float   my_mov_average(std::vector <float> list, int indexe, int periode)
{
    float   total = 0;

    if (indexe - periode < 0)
        return 0;
    for (int i = 0; i < periode; i += 1) {
        total += list[i];
    }
    total = total / periode;
    return total;
}

/*Calcule de l'écart type*/ 
float   my_std_dev(std::vector <float> list, int i, int p, float ma)
{
    float   total = 0;

    if (i - p < 0)
        return 0;
    for (int j = 0; j < p; j += 1) {
        total += pow(list[i - j] - ma, 2);
    }
    total = sqrt(total / p);
    return total;
}

/*calcule de la bande superieur*/
float	calcBp(float ma, float sd, float sd_coef)
{
	return ma + (sd * sd_coef);
}

/*calcule de la bande inferieur*/
float	calcBm(float ma, float sd, float sd_coef)
{
	return ma - (sd * sd_coef);
}
