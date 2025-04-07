/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include <math.h>
#include "world_map.h"

float get_distance(sfVector2f pt1, sfVector2f pt2)
{
    float x = pt1.x - pt2.x;
    float y = pt1.y - pt2.y;

    return sqrtf(x * x + y * y);
}

float calc_one_angle(sfVector2f pta, sfVector2f ptb, sfVector2f ptc)
{
    float ab = get_distance(pta, ptb);
    float bc = get_distance(ptb, ptc);
    float ca = get_distance(ptc, pta);
    float cos_abc = (ab * ab + bc * bc - ca * ca) / (2 * ab * bc);

    return acosf(cos_abc);
}

int calc_angle(world_map_t *map, int x, int y, sfVector2f pos)
{
    sfVector2f p1[4] = {get_pt(map, x, y), get_pt(map, x + 1, y),
                get_pt(map, x + 1, y + 1), get_pt(map, x, y + 1)};
    float angle = 0.0;

    for (int i = 0; i < 4; ++i)
        angle += calc_one_angle(p1[i], pos, p1[(i + 1) % 4]);
    angle -= 2 * PI;
    if (angle < 0)
        angle *= -1;
    return angle <= 0.01;
}
