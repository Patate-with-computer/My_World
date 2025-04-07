/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "window.h"
#include "world_map.h"

static void draw_line(window_t *window, int x)
{
    int px = 0;

    for (int y = 0; y < window->map->size.y - 1; ++y) {
        px = window->map->texture_map[y][x];
        if (px == CHANGE)
            continue;
        draw_square(window, (sfVector2i){x, y}, px);
    }
}

void draw_texture(window_t *window)
{
    if (window->map->angle.y <= 0) {
        for (int x = 0; x < window->map->size.x - 1; ++x)
            draw_line(window, x);
    } else {
        for (int x = window->map->size.x - 2; x != -1; --x)
            draw_line(window, x);
    }
}
