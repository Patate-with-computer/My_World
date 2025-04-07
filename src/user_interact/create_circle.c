/*
** EPITECH PROJECT, 2025
** create_circle
** File description:
** create_circle
*/

#include "interact.h"
#include "world_map.h"
#include "lib.h"

void create_circle(sfRenderWindow *window, sfVector2f pos)
{
    sfVector2f position = pos;
    sfCircleShape *circle = sfCircleShape_create();

    if (circle == NULL)
        return;
    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setRadius(circle, GRID_SIZE / GET_CENTER);
    sfCircleShape_setOutlineThickness(circle, CIRCLE_OUTLINE);
    sfCircleShape_setOutlineColor(circle, MOUSE_CIRCLE);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfRenderWindow_drawCircleShape(window, circle, NULL);
    sfCircleShape_destroy(circle);
}
