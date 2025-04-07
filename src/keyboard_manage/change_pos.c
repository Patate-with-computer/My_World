/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "window.h"
#include "button.h"
#include "world_map.h"

void change_pos(window_t *window)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) == 1)
        window->map->add_x_y.y += X_Y_TO_ADD;
    if (sfKeyboard_isKeyPressed(sfKeyS) == 1)
        window->map->add_x_y.y -= X_Y_TO_ADD;
    if (sfKeyboard_isKeyPressed(sfKeyD) == 1)
        window->map->add_x_y.x -= X_Y_TO_ADD;
    if (sfKeyboard_isKeyPressed(sfKeyQ) == 1)
        window->map->add_x_y.x += X_Y_TO_ADD;
}
