/*
** EPITECH PROJECT, 2025
** create map file
** File description:
** create map file
*/

#include "world_map.h"
#include <stdio.h>
#include <stddef.h>

static void create_filename(char *filename, size_t size)
{
    time_t date = time(NULL);
    struct tm *tm = localtime(&date);

    snprintf(filename, size,
    "saved_maps/map_%02d_%02d_%d_%02dh_%02dm_%02ds.legend", tm->tm_mday,
    tm->tm_mon + 1, tm->tm_year + 1900, tm->tm_hour, tm->tm_min, tm->tm_sec);
}

void create_map_file(world_map_t *map)
{
    char filename[BUFSIZ];
    FILE *file;

    create_filename(filename, sizeof(filename));
    file = fopen(filename, "w");
    if (!file)
        return;
    fprintf(file, "%d %d\n", map->size.x, map->size.y);
    for (int y = 0; y < map->size.y; y++) {
        for (int x = 0; x < map->size.x; x++)
            fprintf(file, "%d ", map->map[y][x]);
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
    for (int y = 0; y < map->size.y - 1; y++) {
        for (int x = 0; x < map->size.x - 1; x++)
            fprintf(file, "%d ", map->texture_map[y][x]);
        fprintf(file, "\n");
    }
    fclose(file);
}

static void set_map(int **map, int x, int y, FILE *file)
{
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++)
            fscanf(file, "%d", &map[i][j]);
    }
}

int get_map_from_file(char const *filepath, world_map_t *map)
{
    FILE *file = fopen(filepath, "r");

    if (file == NULL)
        return 84;
    fscanf(file, "%d", &map->size.x);
    fscanf(file, "%d", &map->size.y);
    map->map = init_2d_map(map->size);
    map->texture_map = init_2d_map((sfVector2i){map->size.x - 1,
        map->size.y - 1});
    set_map(map->map, map->size.x, map->size.y, file);
    fgetc(file);
    set_map(map->texture_map, map->size.x - 1, map->size.y - 1, file);
    fclose(file);
    return 0;
}
