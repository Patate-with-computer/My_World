/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "window.h"
#include "lib.h"
#include "world_map.h"
#include "button.h"

static void all_free(window_t *window)
{
    sfRenderWindow_destroy(window->win);
    sfClock_destroy(window->clock);
    free_2d_map(window->map);
    free_all_button(window->all_btn);
    free_all_button_evt(window->all_btnevt);
    destroy_sounds(window->sounds);
    MY_FREE(window->mouse);
    MY_FREE(window);
}

int main(int ac, char **argv)
{
    int nb = check_error(ac, argv);
    window_t *window = init_window(ac, argv);

    if (window == NULL || nb == 84)
        return ERROR_EPITECH;
    sfRenderWindow_setFramerateLimit(window->win, 60);
    sfRenderWindow_setActive(window->win, sfTrue);
    srand(time(NULL));
    music_launch(window->sounds->background);
    while (sfRenderWindow_isOpen(window->win))
        window_loop(window);
    all_free(window);
    return 0;
}
