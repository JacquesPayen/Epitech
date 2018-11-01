//
// EPITECH PROJECT, 2018
// graphic.h
// File description:
// 
//

#ifndef GRAPHIC_H_
#define GRAPHIC_H_

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

typedef struct	s_graphic
{
	int	***map;
	TTF_Font	*police;
	SDL_Event	event;
	SDL_Surface	*ecran;
	SDL_Surface	*img;
	SDL_Surface	*stone1;
	SDL_Surface	*stone2;
	SDL_Surface	*stone3;
	SDL_Surface	*stone4;
	SDL_Surface	*stone5;
	SDL_Surface	*stone6;
	SDL_Surface	*stone7;
	SDL_Surface	*character;
	int	mousex;
	int	mousey;
	int	height;
	int	width;
	int	x;
	int	y;
}		t_graphic;

t_graphic	gestion_event_low(t_graphic graphic);
t_graphic	gestion_event(t_graphic graphic);
t_graphic	load_img(t_graphic graphic, int x, int y, int nb);
void	draw_quadrillage(SDL_Surface * ecran, int height, int width);
t_graphic	draw_map_sprite_full(t_graphic graphic);
t_graphic	draw_map_sprite(t_graphic graphic);
t_graphic	init_graphic(t_graphic graphic, int ***map, int height, int width);
t_graphic	draw_case_info_full(t_graphic graphic);
t_graphic	draw_case_info_low(t_graphic graphic);

#endif /* !GRAPHIC_H_*/
