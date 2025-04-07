/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include <stdlib.h>
#include "world_map.h"
#include "window.h"
#include "lib.h"

static void set_add(world_map_t *map)
{
    map->angle.x = 63.2;
    map->angle.y = 41.5;
    map->add_x_y.x = (float)(WIN_WIDTH) / 2.0;
    map->add_x_y.y = (float)(WIN_HEIGTH) / 2.0;
    map->center.x = (float)(map->size.x * GRID_SIZE) / 2.0;
    map->center.y = (float)(map->size.y * GRID_SIZE) / 2.0;
    map->zoom = 0.66;
    map->scale = (sfVector2f){1.0, 1.0};
    map->draw = 0;
    map->display_grid = sfTrue;
    map->extrude = NO_EXTRUDE;
    map->show_shadow = sfTrue;
}

static int init_int_map(world_map_t *map, sfVector2i size, int ac, char **argv)
{
    if (ac == 3) {
        map->size.x = atoi(argv[1]);
        map->size.y = atoi(argv[2]);
        map->map = init_2d_map(map->size);
        map->texture_map = init_2d_map((sfVector2i){map->size.x - 1,
            map->size.y - 1});
        if (map->map == NULL || map->texture_map == NULL)
            return 84;
        return 0;
    }
    if (ac == 1) {
        map->map = init_2d_map(size);
        map->texture_map = init_2d_map((sfVector2i){size.x - 1, size.y - 1});
        if (map->map == NULL || map->texture_map == NULL)
            return 84;
        return 0;
    }
    return get_map_from_file(argv[1], map);
}

world_map_t *init_map(int ac, char **argv)
{
    sfVector2i size = {GRID_X, GRID_Y};
    world_map_t *map = malloc(sizeof(world_map_t));

    if (map == NULL)
        return NULL;
    map->all_text = init_texture();
    if (map->all_text == NULL)
        return NULL;
    map->size = size;
    map->to_print = GRASS;
    if (init_int_map(map, size, ac, argv) != 0)
        return NULL;
    map->shader = sfShader_createFromFile(NULL, NULL, FRAG_SHAD);
    if (map->shader == NULL)
        return NULL;
    set_add(map);
    return map;
}
