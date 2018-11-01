/*
** EPITECH PROJECT, 2018
** graphic.c
** File description:
** 
*/

#include "../include/my.h"

t_graphic	run_graphic_low(t_graphic graphic, player_t *list_player)
{
    SDL_Rect	position;

    SDL_FillRect(graphic.ecran, NULL, SDL_MapRGB(graphic.ecran->format, 255, 255, 255));
    graphic = gestion_event_low(graphic);
    draw_quadrillage(graphic.ecran, graphic.height, graphic.width);
    graphic = draw_map_sprite(graphic);
    graphic = draw_character_low(graphic, list_player);
    graphic = draw_case_info_low(graphic);
    SDL_Flip(graphic.ecran);
    return graphic;
}

t_graphic	run_graphic_full(t_graphic graphic, player_t *list_player)
{
	SDL_FillRect(graphic.ecran, NULL, SDL_MapRGB(graphic.ecran->format, 255, 255, 255));
	graphic = gestion_event(graphic);
	draw_quadrillage(graphic.ecran, graphic.height, graphic.width);
	graphic = draw_map_sprite_full(graphic);
	graphic = draw_character(graphic, list_player);
	graphic = draw_case_info_full(graphic);
	SDL_Flip(graphic.ecran);
	return graphic;
}

t_graphic	gestion_event(t_graphic graphic)
{
	int	x = graphic.width;
	int	y = graphic.height;

	if (graphic.width > 50)
		x = 50;
	if (graphic.height > 30)
		y = 30;
	SDL_PollEvent(&graphic.event);
	SDL_GetMouseState(&graphic.mousex, &graphic.mousey);
	switch(graphic.event.type) {
	case SDL_KEYDOWN:
		switch(graphic.event.key.keysym.sym) {
		case SDLK_UP:
			if (graphic.y != 0)
				graphic.y = graphic.y - 1;
			break;
		case SDLK_DOWN:
			if (graphic.y < graphic.height - y)
				graphic.y = graphic.y + 1;
			break;
		case SDLK_LEFT:
			if (graphic.x != 0)
				graphic.x = graphic.x - 1;
			break;
		case SDLK_RIGHT:
			if (graphic.x < graphic.width - x)
				graphic.x = graphic.x + 1;
			break;
		}
	}
	return graphic;
}

t_graphic	run_graphic(t_graphic graphic, player_t *list_player)
{
	if (graphic.width <= 50 && graphic.height <= 30)
		graphic = run_graphic_low(graphic, list_player);
	else
		graphic = run_graphic_full(graphic, list_player);
	return graphic;
}

t_graphic	init_graphic(t_graphic graphic, int ***map, int height, int width)
{
	graphic.map = map;
	graphic.ecran = NULL;
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	graphic.police = TTF_OpenFont("server/img/angelina.TTF", 30);
	graphic.img = SDL_LoadBMP("server/img/food.bmp");
	graphic.stone1 = SDL_LoadBMP("server/img/stone1.bmp");
	graphic.stone2 = SDL_LoadBMP("server/img/stone2.bmp");
	graphic.stone3 = SDL_LoadBMP("server/img/stone3.bmp");
	graphic.stone4 = SDL_LoadBMP("server/img/stone4.bmp");
	graphic.stone5 = SDL_LoadBMP("server/img/stone5.bmp");
	graphic.stone6 = SDL_LoadBMP("server/img/stone6.bmp");
	graphic.stone7 = SDL_LoadBMP("server/img/stone7.bmp");
	graphic.character = SDL_LoadBMP("server/img/link.bmp");
	graphic.height = height;
	graphic.width = width;
	graphic.x = 0;
	graphic.y = 0;
	graphic.ecran = SDL_SetVideoMode(1728, 972, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("Zappy", NULL);
	return graphic;
}
