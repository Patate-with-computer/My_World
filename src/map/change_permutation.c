/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include <stddef.h>
#include "world_map.h"

void change_permutation(int perm[NBR_PERM])
{
    int j = 0;
    int temp = 0;

    for (int i = 0; i < NBR_PERM; i++) {
        perm[i] = i;
    }
    for (int i = 0; i < NBR_PERM; i++) {
        j = rand() % NBR_PERM;
        temp = perm[i];
        perm[i] = perm[j];
        perm[j] = temp;
    }
}
