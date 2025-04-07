/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "window.h"
#include "world_map.h"
#include "button.h"
#include "interact.h"

void window_loop(window_t *window)
{
    float zoom_anc = window->map->zoom;

    event_manage(window);
    change_angle(window);
    change_pos(window);
    sfRenderWindow_clear(window->win, sfBlack);
    draw_texture(window);
    draw_2d_map(window->map, window);
    find_touch_square(window);
    check_interact(window, 10.0 * window->map->extrude);
    display_all_btnevtt(window->win, window->all_btnevt, window->scale);
    follow_mouse(window);
    sfRenderWindow_display(window->win);
    if (zoom_anc != window->map->zoom) {
        play_thread_music(window->sounds->zoom, sfTrue,
            window->all_btnevt[BTN_SONG]->active);
    }
}
