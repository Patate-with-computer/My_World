/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include <math.h>
#include "world_map.h"

static sfVector2f conv_deg_to_rad(sfVector2f angle)
{
    sfVector2f to_return = {0, 0};

    to_return.x = angle.x * CONV;
    to_return.y = angle.y * CONV;
    return to_return;
}

sfVector2f project_point(sfVector3f pt, sfVector2f a)
{
    sfVector2f point = {0, 0};
    sfVector2f angle = conv_deg_to_rad(a);
    float sx = sinf(angle.x);
    float sy = sinf(angle.y);
    float cx = cosf(angle.x);
    float cy = cosf(angle.y);

    point.x = pt.x * cy + (pt.y * sx + pt.z * cx) * sy;
    point.y = pt.y * cx - pt.z * sx;
    return point;
}
