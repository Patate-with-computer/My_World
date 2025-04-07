/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "lib.h"
#include "world_map.h"

void destroy_all_texture(sfTexture **all_text)
{
    for (int i = NBR_TEXTURE - 1; i != -1; --i)
        sfTexture_destroy(all_text[i]);
    MY_FREE(all_text);
}

sfTexture **init_texture(void)
{
    sfTexture **all_text = malloc(sizeof(sfTexture *) * (NBR_TEXTURE + 1));
    const char *texture_list[] = {"ressources/change.png",
        "ressources/grass.png", "ressources/ground.png",
        "ressources/water.png"};

    if (all_text == NULL)
        return NULL;
    for (int i = 0; i < NBR_TEXTURE; ++i) {
        all_text[i] = sfTexture_createFromFile(texture_list[i], NULL);
        if (all_text[i] == NULL)
            return NULL;
    }
    return all_text;
}
