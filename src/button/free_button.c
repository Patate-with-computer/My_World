/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "lib.h"
#include "button.h"

void free_button_evt(button_evt_t *btn)
{
    if (btn == NULL)
        return;
    sfTexture_destroy(btn->text);
    sfSprite_destroy(btn->sprite);
    sfRectangleShape_destroy(btn->rect);
    MY_FREE(btn);
}

void free_all_button_evt(button_evt_t **btn)
{
    for (int i = NBR_BTNEVT - 1; i != -1; --i)
        free_button_evt(btn[i]);
    MY_FREE(btn);
}
