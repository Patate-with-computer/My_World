/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include <SFML/Graphics.h>
#include "lib.h"
#include "world_map.h"

int **init_2d_map(sfVector2i size)
{
    int **map = malloc(sizeof(int *) * size.y);

    if (map == NULL)
        return NULL;
    for (int i = 0; i < size.y; ++i) {
        map[i] = malloc(sizeof(int) * size.x);
        if (map[i] == NULL)
            return NULL;
        for (int j = 0; j < size.x; ++j)
            map[i][j] = 0;
    }
    return map;
}
