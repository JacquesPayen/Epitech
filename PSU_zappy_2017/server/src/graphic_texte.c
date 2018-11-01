/*
** EPITECH PROJECT, 2018
** graphic_texte.c
** File description:
** 
*/

#include "../include/my.h"

t_graphic	draw_texte(t_graphic graphic, int pos, const char *texte, int nb)
{
	char	res[12];
	SDL_Surface	*surf;
	SDL_Color couleurNoire = {0, 0, 0};
	SDL_Rect	position;

	res[0] = '\0';
	position.x = 1570;
	position.y = 100 * pos;
	surf = TTF_RenderText_Blended(graphic.police, texte, couleurNoire);
	SDL_BlitSurface(surf, NULL, graphic.ecran, &position);
	sprintf(res, "%d", nb);
	position.y = position.y + 50;
	surf = TTF_RenderText_Blended(graphic.police, res, couleurNoire);
	SDL_BlitSurface(surf, NULL, graphic.ecran, &position);
	return graphic;
}

t_graphic	draw_case_info_low(t_graphic graphic)
{
	int	x = graphic.mousex;
	int	y = graphic.mousey;
	int	h = 0;
	int	w  = 0;
	int	i = 0;

	x = x - 13;
	y = y - 10;
	while (x > 31) {
		x = x - 31;
		w++;
	}
	while (y > 31) {
		y = y - 31;
		h++;
	}
	if (w > graphic.width - 1 || h > graphic.height - 1)
		return graphic;
	while (i != 7) {
		graphic = draw_texte(graphic, i, object[i], graphic.map[h][w][i]);
		i++;
	}
	return graphic;
}

t_graphic	draw_case_info_full(t_graphic graphic)
{
	int	x = graphic.mousex;
	int	y = graphic.mousey;
	int	h = 0;
	int	w  = 0;
	int	i = 0;

	x = x - 13;
	y = y - 10;
	while (x > 31) {
		x = x - 31;
		w++;
	}
	while (y > 31) {
		y = y - 31;
		h++;
	}
	if (graphic.width > 49) {
		if (w > 49)
			return graphic;
	}
	else {
		if (w > graphic.width - 1 )
			return graphic;
	}
	if (graphic.height > 28) {
		if (h > 29)
			return graphic;
	}
	else {
		if (h > graphic.height - 1 )
			return graphic;
	}
	while (i != 7) {
		graphic = draw_texte(graphic, i, object[i], graphic.map[graphic.y + h][graphic.x + w][i]);
		i++;
	}
	return graphic;
}

t_graphic	gestion_event_low(t_graphic graphic)
{
	SDL_PollEvent(&graphic.event);
	SDL_GetMouseState(&graphic.mousex, &graphic.mousey);
	return graphic;
}

void	leave_sdl(t_graphic graphic)
{
	TTF_CloseFont(graphic.police);
	TTF_Quit();
	SDL_FreeSurface(graphic.img);
	SDL_FreeSurface(graphic.stone1);
	SDL_FreeSurface(graphic.stone2);
	SDL_FreeSurface(graphic.stone3);
	SDL_FreeSurface(graphic.stone4);
	SDL_FreeSurface(graphic.stone5);
	SDL_FreeSurface(graphic.stone6);
	SDL_FreeSurface(graphic.stone7);
	SDL_FreeSurface(graphic.character);
	SDL_Quit();
}
