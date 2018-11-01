/*
** EPITECH PROJECT, 2018
** graphic_draw.c
** File description:
** 
*/

#include "../include/my.h"

t_graphic	draw_character_low(t_graphic graphic, player_t *player_list)
{
	SDL_Surface	*img;
	SDL_Rect	position;
	player_t	*pt = player_list;

	while (pt != NULL) {
		img = graphic.character;
		position.x = 13 + pt->x * 31;
		position.y = 10 + pt->y * 31;
		SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 182, 185, 184));
		SDL_BlitSurface(img, NULL, graphic.ecran, &position);
		pt = pt->next;
	}
	return graphic;
}

t_graphic	draw_character(t_graphic graphic, player_t *player_list)
{
	int	x = graphic.width;
	int	y = graphic.height;
	SDL_Surface	*img;
	SDL_Rect	position;
	player_t	*pt = player_list;

	if (x > 50)
		x = 50;
	if (y > 30)
		y = 30;
	while (pt != NULL) {
		img = graphic.character;
		position.x = 13 + pt->x * 31 - graphic.x * 31;
		position.y = 10 + pt->y * 31 - graphic.y * 31;
		if (position.x > 12 && position.y > 9 && graphic.x + x > pt->x && graphic.y + y > pt->y) {
			SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 182, 185, 184));
			SDL_BlitSurface(img, NULL, graphic.ecran, &position);
		}
		pt = pt->next;
	}
	return graphic;
}

t_graphic	draw_map_sprite_full(t_graphic graphic)
{
	int	x = 13;
	int	y = 10;
	int	h = graphic.y;
	int	w = graphic.x;

	while (h != graphic.y + 30) {
		w = graphic.x;
		x = 13;
		while (w != graphic.x + 50) {
			/*if (graphic.map[h][w] != 0)
			  load_img(graphic, x, y, graphic.map[h][w]);*/
			w++;
			x = x + 31;
		}
		h++;
		y = y + 31;
	}
	return graphic;
}

t_graphic	draw_map_sprite(t_graphic graphic)
{
	int	x = 13;
	int	y = 10;
	int	h = 0;
	int	w = 0;

	while (h != graphic.height) {
		w = 0;
		x = 13;
		while (w != graphic.width) {
			/*if (graphic.map[h][w] != 0)
			  load_img(graphic, x, y, graphic.map[h][w]);*/
			w++;
			x = x + 31;
		}
		h++;
		y = y + 31;
	}
	return graphic;
}
