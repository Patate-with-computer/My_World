/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "button.h"
#include "window.h"
#include "world_map.h"

static void check_evt_btn(button_evt_t *btn)
{
    sfBool click = btn->clicked;

    if (click && !btn->previous_state) {
        btn->previous_state = 1;
        btn->active = 1 - btn->active;
    }
    if (!click && btn->previous_state)
        btn->previous_state = 0;
}

void get_button_event(button_evt_t *btn, sfVector2f mpos, sfVector2f sc)
{
    btn->sc_pos = (sfVector2f){btn->pos.x * sc.x, btn->pos.y * sc.y};
    btn->sc_size = (sfVector2f){(btn->size.x + 2 * RECT_BTNEVT_B) * sc.x,
        (btn->size.y + 2 * RECT_BTNEVT_B) * sc.y};
    btn->hover = 0;
    btn->clicked = 0;
    if ((mpos.x >= btn->sc_pos.x && mpos.x <= btn->sc_pos.x + btn->sc_size.x)
    && (mpos.y >= btn->sc_pos.y && mpos.y <= btn->sc_pos.y + btn->sc_size.y))
        btn->hover = 1;
    if (btn->hover && sfMouse_isButtonPressed(sfMouseLeft)) {
        btn->clicked = 1;
        if (btn->md != ONE_CLICK)
            btn->active = 1;
    }
    if (btn->md == ONE_CLICK)
        check_evt_btn(btn);
}

void put_one_active(button_evt_t **btn, int n_to_active)
{
    for (int i = 0; i < NBR_BTNEVT; ++i) {
        if (btn[i]->md == ONE_CLICK)
            continue;
        btn[i]->active = 0;
    }
    btn[n_to_active]->active = 1;
}

static void set_mode(window_t *win)
{
    int act = -1;

    for (int i = 0; i < NBR_BTNEVT; ++i) {
        if (!win->all_btnevt[i]->active)
            continue;
        act = i;
        break;
    }
    win->map->to_print = NO_PRINT;
    win->map->extrude = NO_EXTRUDE;
    if (act >= BTN_ERASE && act <= BTN_WATER)
        win->map->to_print = act;
    if (act == BTN_EXTRUDE_DOWN)
        win->map->extrude = EXTRUDE_DOWN;
    if (act == BTN_EXTRUDE_UP)
        win->map->extrude = EXTRUDE_UP;
}

void get_all_button_event(window_t *win, sfVector2f mpos, sfVector2f sc)
{
    for (int i = 0; i < NBR_BTNEVT; ++i) {
        get_button_event(win->all_btnevt[i], mpos, sc);
        if (win->all_btnevt[i]->clicked &&
            win->all_btnevt[i]->md != ONE_CLICK) {
            put_one_active(win->all_btnevt, i);
        }
    }
    set_mode(win);
    if (win->all_btnevt[BTN_SHADOW]->clicked)
        play_thread_music(win->sounds->shaders, 1,
            win->all_btnevt[BTN_SONG]->active);
    if (win->all_btnevt[BTN_SONG]->active &&
        sfMusic_getStatus(win->sounds->background) == sfPaused)
        sfMusic_play(win->sounds->background);
    if (!win->all_btnevt[BTN_SONG]->active &&
        sfMusic_getStatus(win->sounds->background) == sfPlaying)
        sfMusic_pause(win->sounds->background);
}
