/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include <stddef.h>
#include "button.h"

static void set_rect(button_evt_t *btn)
{
    const sfColor rect_color[] = {{116, 116, 116, 255}, {219, 161, 0, 255}};

    sfRectangleShape_setSize(btn->rect, btn->sc_size);
    sfRectangleShape_setPosition(btn->rect, btn->sc_pos);
    if (!btn->active && btn->hover)
        sfRectangleShape_setFillColor(btn->rect, rect_color[RECT_HOVER]);
    if (btn->active)
        sfRectangleShape_setFillColor(btn->rect, rect_color[RECT_ACTIVE]);
}

void display_button_evt(sfRenderWindow *win, button_evt_t *btn, sfVector2f sc)
{
    sfVector2f sp_pos = {btn->pos.x + RECT_BTNEVT_B,
        btn->pos.y + RECT_BTNEVT_B};

    sp_pos.x *= sc.x;
    sp_pos.y *= sc.y;
    sfSprite_setScale(btn->sprite, sc);
    sfSprite_setPosition(btn->sprite, sp_pos);
    if (btn->hover || btn->active) {
        set_rect(btn);
        sfRenderWindow_drawRectangleShape(win, btn->rect, NULL);
    }
    sfRenderWindow_drawSprite(win, btn->sprite, NULL);
}

void display_all_btnevtt(sfRenderWindow *win, button_evt_t **b, sfVector2f sc)
{
    for (int i = 0; i < NBR_BTNEVT; ++i)
        display_button_evt(win, b[i], sc);
}
