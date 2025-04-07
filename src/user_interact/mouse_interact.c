/*
** EPITECH PROJECT, 2025
** mouse_interact
** File description:
** interaction
*/

#include "interact.h"
#include "world_map.h"
#include "window.h"
#include "lib.h"
#include "button.h"

void follow_mouse(window_t *window)
{
    if (window->mouse->pos.x == -1 || window->mouse->pos.y == -1)
        return;
    window->mouse->pos.x -= GRID_SIZE / 3;
    window->mouse->pos.y -= GRID_SIZE / 3;
    create_circle(window->win, window->mouse->pos);
    return;
}

static int change_hight(window_t *window, int x, int difference)
{
    sfVector2f point = {0.0, 0.0};
    float dist = 0.0;

    for (int y = 0; y < window->map->size.y; y++) {
        point = get_pt(window->map, x, y);
        dist = get_distance(point, window->mouse->pos);
        if (dist <= 20.0 * window->map->zoom) {
            point.x -= GRID_SIZE / 3;
            point.y -= GRID_SIZE / 3;
            create_circle(window->win, point);
            window->map->map[y][x] += (window->map->draw) * difference;
            play_thread_music(window->sounds->size, window->map->draw,
                window->all_btnevt[BTN_SONG]->active);
            return POINT_FOUND;
        }
    }
    return POINT_NOT_FOUND;
}

void check_interact(window_t *window, int difference)
{
    int found = POINT_NOT_FOUND;

    if (window->map->extrude == NO_EXTRUDE)
        return;
    for (int x = 0; x < window->map->size.x; x++) {
        found = change_hight(window, x, difference);
        if (found == POINT_FOUND)
            return;
    }
}
