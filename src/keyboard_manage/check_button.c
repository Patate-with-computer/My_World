/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include <SFML/Graphics.h>
#include "button.h"

static void check_button(check_button_t *btn)
{
    sfBool key = sfKeyboard_isKeyPressed(btn->key);

    btn->state = 0;
    if (key && !btn->previous_state) {
        btn->previous_state = 1;
        btn->state = 1;
    }
    if (!key && btn->previous_state)
        btn->previous_state = 0;
}

int get_state(check_button_t **all_btn, sfKeyCode key)
{
    for (int i = 0; i < NBR_BTN; ++i) {
        if (all_btn[i]->key == key)
            return all_btn[i]->state;
    }
    return -1;
}

void check_all_button(check_button_t **all_btn)
{
    for (int i = 0; i < NBR_BTN; ++i)
        check_button(all_btn[i]);
}
