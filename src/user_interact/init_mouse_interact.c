/*
** EPITECH PROJECT, 2025
** init mouse interact
** File description:
** init mouse interact
*/

#include "lib.h"
#include "interact.h"

interact_t *init_mouse(void)
{
    sfVector2f mouse_pos = {0.0, 0.0};
    interact_t *mouse = malloc(sizeof(interact_t));

    if (mouse == NULL)
        return NULL;
    mouse->pos = mouse_pos;
    mouse->x_map = -1;
    mouse->y_map = -1;
    return mouse;
}
