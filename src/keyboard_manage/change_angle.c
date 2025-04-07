/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "window.h"
#include "button.h"
#include "world_map.h"

void change_angle(window_t *window)
{
    sfVector2f a = window->map->angle;

    if (sfKeyboard_isKeyPressed(sfKeyUp) == 1 && a.x <= MAX_ANGLE_X)
        window->map->angle.x += ANGLE_TO_ADD;
    if (sfKeyboard_isKeyPressed(sfKeyDown) == 1 && a.x >= MIN_ANGLE_X)
        window->map->angle.x -= ANGLE_TO_ADD;
    if (sfKeyboard_isKeyPressed(sfKeyI) == 1)
        window->map->zoom += ZOOM_TO_ADD;
    if (sfKeyboard_isKeyPressed(sfKeyO) == 1 &&
            window->map->zoom >= MIN_ZOOM)
        window->map->zoom -= ZOOM_TO_ADD;
    if (sfKeyboard_isKeyPressed(sfKeyRight) == 1 && a.y <= MAX_ANGLE_Y)
        window->map->angle.y += ANGLE_TO_ADD;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == 1 && a.y >= -1 * MAX_ANGLE_Y)
        window->map->angle.y -= ANGLE_TO_ADD;
}
