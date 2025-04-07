/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include <math.h>
#include "world_map.h"

static double perlin(double x, double y, int perm[NBR_PERM])
{
    int X = (int)floor(x) & 255;
    int Y = (int)floor(y) & 255;

    x -= floor(x);
    y -= floor(y);
    return lerp(
        fade(y),
        lerp(fade(x),
            grad(perm[perm[X] + Y], x, y),
            grad(perm[perm[X + 1] + Y], x - 1, y)),
        lerp(fade(x),
            grad(perm[perm[X] + Y + 1], x, y - 1),
            grad(perm[perm[X + 1] + Y + 1], x - 1, y - 1)));
}

void random_perlin(int **image, sfVector2i size)
{
    float xx = 0.0;
    float yy = 0.0;
    int perm[NBR_PERM] = {0};

    change_permutation(perm);
    for (int y = 0; y < size.y; y++) {
        for (int x = 0; x < size.x; x++) {
            xx = (float)x / size.x;
            yy = (float)y / size.y;
            image[y][x] = (int)(perlin(xx * FREQ_SOM,
                        yy * FREQ_SOM, perm) * MAX_PERLIN);
        }
    }
}
