/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include <math.h>
#include "world_map.h"

static sfVector3f get_3d_point(world_map_t *map, int x, int y)
{
    sfVector3f to_return = {0};

    to_return.x = x * GRID_SIZE - map->center.x;
    to_return.y = y * GRID_SIZE - map->center.y;
    to_return.z = map->map[y][x];
    return to_return;
}

static float get_zoom(float zoom)
{
    return powf(MATH_E, zoom) - (MATH_E - 1);
}

sfVector2f get_pt(world_map_t *map, int x, int y)
{
    sfVector3f pt_3d = get_3d_point(map, x, y);
    sfVector2f to_return = project_point(pt_3d, map->angle);
    float zoom = get_zoom(map->zoom);

    to_return.x += map->add_x_y.x / zoom;
    to_return.x *= zoom;
    to_return.x *= map->scale.x;
    to_return.y += map->add_x_y.y / zoom;
    to_return.y *= zoom;
    to_return.y *= map->scale.y;
    return to_return;
}
