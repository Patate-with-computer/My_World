/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "window.h"
#include "world_map.h"

static void complete_line(world_map_t *map, int x)
{
    int z_map = 0;
    texture_t text = CHANGE;

    for (int y = 1; y < map->size.y - 1; ++y) {
        z_map = map->map[y][x];
        text = GROUND;
        if (z_map < -1)
            text = WATER;
        if (z_map >= -1 && z_map < MAX_PERLIN / 3)
            text = GRASS;
        map->texture_map[y][x] = text;
        map->texture_map[y][x - 1] = text;
        map->texture_map[y - 1][x - 1] = text;
        map->texture_map[y - 1][x] = text;
    }
}

void auto_complete(world_map_t *map)
{
    for (int x = 1; x < map->size.x - 1; ++x)
        complete_line(map, x);
}
