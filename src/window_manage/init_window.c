/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "interact.h"
#include "window.h"
#include "world_map.h"
#include "button.h"
#include "lib.h"

static int init_struct(window_t *win, int ac, char **argv)
{
    win->map = init_map(ac, argv);
    if (win->map == NULL)
        return -1;
    win->all_btnevt = init_all_btnevt();
    if (win->all_btnevt == NULL)
        return -1;
    win->mouse = init_mouse();
    if (win->mouse == NULL)
        return -1;
    win->all_btn = get_all_btn();
    if (win->all_btn == NULL)
        return -1;
    win->sounds = init_sounds();
    if (win->sounds == NULL)
        return -1;
    return 0;
}

window_t *init_window(int ac, char **argv)
{
    window_t *win = malloc(sizeof(window_t));
    sfVideoMode mode = {WIN_WIDTH, WIN_HEIGTH, BPP};
    sfWindowStyle win_mode = sfClose | sfResize;

    if (win == NULL)
        return NULL;
    if (init_struct(win, ac, argv) != 0)
        return NULL;
    win->win = sfRenderWindow_create(mode, "My_world", win_mode, NULL);
    if (win->win == NULL)
        return NULL;
    win->clock = sfClock_create();
    if (win->clock == NULL)
        return NULL;
    win->scale = (sfVector2f){1.0, 1.0};
    return win;
}
