/*
** EPITECH PROJECT, 2018
** map.h
** File description:
** 
*/

#ifndef MAP_H_
#define MAP_H_

void	draw_map(int ***map, int height, int width);
int	***generation_map(int height, int width);
void	place_ressource(int ***map, int y, int x);

#endif /* !MAP_H_*/
