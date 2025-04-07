/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "window.h"
#include "world_map.h"

void calc_scale(window_t *win)
{
    sfVector2f iws = (sfVector2f){WIN_WIDTH, WIN_HEIGTH};
    sfVector2u win_size = sfRenderWindow_getSize(win->win);
    sfVector2f aws = (sfVector2f){win_size.x, win_size.y};

    win->scale = (sfVector2f){iws.x / aws.x, iws.y / aws.y};
    win->map->scale = win->scale;
}
