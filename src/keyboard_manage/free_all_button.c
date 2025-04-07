/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "button.h"
#include "lib.h"

void free_all_button(check_button_t **all_btn)
{
    for (int i = NBR_BTN - 1; i > -1; --i) {
        MY_FREE(all_btn[i]);
    }
    MY_FREE(all_btn);
}
