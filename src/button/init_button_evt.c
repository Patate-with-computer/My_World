/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "button.h"
#include "lib.h"

const char *link[] = {"ressources/erase.png", "ressources/grass.png",
    "ressources/ground.png", "ressources/water.png",
    "ressources/extrude_up.png", "ressources/extrude_down.png",
    "ressources/shadow.png", "ressources/song.png"};

button_evt_t *init_button_evt(const char *name,
    sfVector2f pos, sfVector2f size)
{
    button_evt_t *button = malloc(sizeof(button_evt_t));

    if (button == NULL)
        return NULL;
    button->rect = sfRectangleShape_create();
    if (button->rect == NULL)
        return NULL;
    button->sprite = sfSprite_create();
    button->text = sfTexture_createFromFile(name, NULL);
    if (button->text == NULL || button->sprite == NULL)
        return NULL;
    sfRectangleShape_setSize(button->rect,
        (sfVector2f){size.x + 2 * RECT_BTNEVT_B, size.x + 2 * RECT_BTNEVT_B});
    sfSprite_setTexture(button->sprite, button->text, sfTrue);
    button->pos = pos;
    button->size = size;
    button->active = 0;
    button->previous_state = 0;
    button->md = ALL_CLICK;
    return button;
}

button_evt_t **init_all_btnevt(void)
{
    sfVector2f pos = {20, 20};
    sfVector2f size = (sfVector2f){SIZE_BTNEVT, SIZE_BTNEVT};
    button_evt_t **all_btn = malloc(sizeof(button_evt_t *) * (NBR_BTNEVT + 1));

    if (all_btn == NULL)
        return NULL;
    for (int i = 0; i < NBR_BTNEVT; ++i) {
        all_btn[i] = init_button_evt(link[i], pos, size);
        if (all_btn[i] == NULL)
            return NULL;
        pos.x += SIZE_BTNEVT + SP_BTNEVT;
    }
    all_btn[BTN_GRASS]->active = 1;
    all_btn[BTN_SHADOW]->active = 1;
    all_btn[BTN_SHADOW]->md = ONE_CLICK;
    all_btn[BTN_SONG]->md = ONE_CLICK;
    all_btn[BTN_SONG]->active = 0;
    return all_btn;
}
