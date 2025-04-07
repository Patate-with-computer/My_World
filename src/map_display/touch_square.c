/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "window.h"
#include "world_map.h"
#include "interact.h"
#include "button.h"

static sfVector2i check_one_line(world_map_t *map, int y, sfVector2f m_pos)
{
    for (int x = 0; x < map->size.x - 1; ++x) {
        if (!calc_angle(map, x, y, m_pos))
            continue;
        return (sfVector2i){x, y};
    }
    return (sfVector2i) {-1, -1};
}

sfVector2i get_touch_square_pos(world_map_t *map, sfVector2f m_pos)
{
    sfVector2i find_pos = {-1, -1};
    sfVector2i return_pos = {-1, -1};

    for (int y = 0; y < map->size.y - 1; ++y) {
        find_pos = check_one_line(map, y, m_pos);
        if (find_pos.x == -1)
            continue;
        return_pos = find_pos;
    }
    return return_pos;
}

void find_touch_square(window_t *window)
{
    sfVector2i pos = {0, 0};

    if (window->map->to_print == NO_PRINT)
        return;
    pos = get_touch_square_pos(window->map, window->mouse->pos);
    if (pos.x == -1 || pos.y == -1)
        return;
    draw_square(window, pos, CHANGE);
    if (window->map->draw) {
        play_thread_music(window->sounds->click, window->map->draw,
            window->all_btnevt[BTN_SONG]->active);
        window->map->texture_map[pos.y][pos.x] = window->map->to_print;
    }
}
