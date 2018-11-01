//
// EPITECH PROJECT, 2018
// graphic_gestion.cpp
// File description:
// 
//

#include "../include/my.h"

void	draw_line(SDL_Rect *line, int x, int y, int w, int h)
{
	line->x = x;
	line->y = y;
	line->w = w;
	line->h = h;
}

void draw_rect(SDL_Surface * surf,int X, int Y, int width, int length)
{
	SDL_Rect line;

	draw_line(&line, X-1, Y-1, length, 1);
	SDL_FillRect(surf, &line, SDL_MapRGB(surf->format, 0, 0, 0));
	draw_line(&line, X+length-1, Y-1, 1, width);
	SDL_FillRect(surf, &line, SDL_MapRGB(surf->format, 0, 0, 0));
 	draw_line(&line, X-1, Y-1, 1, width);
	SDL_FillRect(surf, &line, SDL_MapRGB(surf->format, 0, 0, 0));
	draw_line(&line, X-1, Y+width-1, length, 1);
	SDL_FillRect(surf, &line, SDL_MapRGB(surf->format, 0, 0, 0));
}

void	draw_quadrillage(SDL_Surface * ecran, int height, int width)
{
	int	w = 0;
	int	h = 0;
	int	x = 10;
	int	y = 10;

	while (h != height && h != 30) {
		x = 13;
		w = 0;
		while (w != width && w != 50) {
			draw_rect(ecran, x, y, 30, 30);
			x = x + 31;
			w++;
		}
		y = y + 31;
		h++;
	}
}

SDL_Surface	*choose_sprite(int nb, t_graphic graphic)
{
	SDL_Surface	*img = NULL;

	if (nb == 1)
		img = graphic.stone1;
	else if (nb == 2)
		img = graphic.stone2;
	else if (nb == 3)
		img = graphic.stone3;
	else if (nb == 4)
		img = graphic.stone4;
	else if (nb == 5)
		img = graphic.stone5;
	else if (nb == 6)
		img = graphic.stone6;
	else if (nb == 7)
		img = graphic.img;
	return img;
}

t_graphic	load_img(t_graphic graphic, int x, int y, int nb)
{
	SDL_Surface	*img;
	SDL_Rect	position;

	if ((img = choose_sprite(nb, graphic)) == NULL)
		return graphic;
	position.x = x;
	position.y = y;
	if (img != graphic.img)
		SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 182, 185, 184));
	else
		SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 255, 255, 255));	
	SDL_BlitSurface(img, NULL, graphic.ecran, &position);
	return graphic;
}
