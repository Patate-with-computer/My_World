/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "lib.h"
#include "world_map.h"

static void free_map(int **map, sfVector2i size)
{
    for (int i = size.y - 1; i > -1; --i)
        MY_FREE(map[i]);
    MY_FREE(map);
}

void free_2d_map(world_map_t *map)
{
    destroy_all_texture(map->all_text);
    sfShader_destroy(map->shader);
    free_map(map->map, map->size);
    free_map(map->texture_map, (sfVector2i){map->size.x - 1, map->size.y - 1});
    MY_FREE(map);
}
