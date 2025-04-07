/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "button.h"
#include "lib.h"

check_button_t *add_one_button(sfKeyCode key)
{
    check_button_t *button = malloc(sizeof(check_button_t));

    if (button == NULL)
        return NULL;
    button->state = 0;
    button->previous_state = 0;
    button->key = key;
    return button;
}

check_button_t **get_all_btn(void)
{
    const sfKeyCode all_key[NBR_BTN] = {sfKeyP, sfKeyNumpad0, sfKeyNumpad1,
        sfKeyNumpad2, sfKeyNumpad3, sfKeyG, sfKeyR, sfKeyEnter};
    check_button_t **btn = malloc(sizeof(check_button_t *) * (NBR_BTN + 1));

    if (btn == NULL)
        return NULL;
    for (int i = 0; i < NBR_BTN; ++i) {
        btn[i] = add_one_button(all_key[i]);
        if (btn[i] == NULL)
            return NULL;
    }
    return btn;
}
