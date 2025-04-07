/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "world_map.h"
#include "window.h"

static void draw_vertext(window_t *window, sfVertexArray *quad)
{
    if (quad == NULL)
        return;
    sfVertexArray_setPrimitiveType(quad, sfLinesStrip);
    sfRenderWindow_drawVertexArray(window->win, quad, NULL);
    sfVertexArray_destroy(quad);
}

static void draw_vertical_line(world_map_t *map, window_t *window)
{
    sfVertexArray *quad = NULL;
    sfVertex vertex = {.color = sfWhite};

    for (int y = 0; y < map->size.y; ++y) {
        quad = sfVertexArray_create();
        if (quad == NULL)
            continue;
        for (int x = 0; x < map->size.x; ++x) {
            vertex.position = get_pt(map, x, y);
            sfVertexArray_append(quad, vertex);
        }
        draw_vertext(window, quad);
    }
}

static void draw_horizontal_line(world_map_t *map, window_t *window)
{
    sfVertexArray *quad = NULL;
    sfVertex vertex = {.color = sfWhite};

    for (int x = 0; x < map->size.x; ++x) {
        quad = sfVertexArray_create();
        if (quad == NULL)
            continue;
        for (int y = 0; y < map->size.y; ++y) {
            vertex.position = get_pt(map, x, y);
            sfVertexArray_append(quad, vertex);
        }
        draw_vertext(window, quad);
    }
}

void draw_2d_map(world_map_t *map, window_t *window)
{
    if (map->display_grid) {
        draw_vertical_line(map, window);
        draw_horizontal_line(map, window);
    }
}
