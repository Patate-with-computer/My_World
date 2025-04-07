/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "window.h"
#include "interact.h"
#include "world_map.h"
#include "button.h"

static int check_button_hover(button_evt_t **btn)
{
    for (int i = 0; i < NBR_BTNEVT; ++i) {
        if (!btn[i]->hover)
            continue;
        return 1;
    }
    return 0;
}

static void mouse_roll(window_t *window)
{
    if (window->event.type == sfEvtMouseWheelScrolled) {
        if (window->event.mouseWheelScroll.delta == sfMouseHorizontalWheel)
            window->map->zoom += ZOOM_TO_ADD * 2.0;
        if (window->event.mouseWheelScroll.delta != sfMouseHorizontalWheel &&
            window->map->zoom >= MIN_ZOOM)
            window->map->zoom -= ZOOM_TO_ADD * 2.0;
    }
}

static void set_text_btn(window_t *window)
{
    if (window->all_btn[BTN_KEY_1]->state)
        put_one_active(window->all_btnevt, BTN_ERASE);
    if (window->all_btn[BTN_KEY_2]->state)
        put_one_active(window->all_btnevt, BTN_GRASS);
    if (window->all_btn[BTN_KEY_3]->state)
        put_one_active(window->all_btnevt, BTN_GROUND);
    if (window->all_btn[BTN_KEY_4]->state)
        put_one_active(window->all_btnevt, BTN_WATER);
    if (window->all_btn[BTN_KEY_G]->state)
        window->map->display_grid = !window->map->display_grid;
}

static void set_btn_event(window_t *window)
{
    if (window->all_btn[BTN_KEY_P]->state) {
        random_perlin(window->map->map, window->map->size);
        play_thread_music(window->sounds->perlin, 1,
            window->all_btnevt[BTN_SONG]->active);
    }
    set_text_btn(window);
    if (window->all_btn[BTN_KEY_R]->state)
        auto_complete(window->map);
    if (window->all_btn[BTN_KEY_SAVE]->state &&
    sfKeyboard_isKeyPressed(sfKeyLControl)) {
        play_thread_music(window->sounds->save, 1,
            window->all_btnevt[BTN_SONG]->active);
        create_map_file(window->map);
    }
}

static void check_modif_map(window_t *window)
{
    if (window->event.type == sfEvtMouseButtonPressed &&
        window->event.mouseButton.button == sfMouseLeft &&
        !check_button_hover(window->all_btnevt))
        window->map->draw = 1;
    if (window->event.type == sfEvtMouseButtonReleased &&
        window->event.mouseButton.button == sfMouseLeft)
        window->map->draw = 0;
}

static void play_end_music(sfMusic *sound, int play)
{
    if (play) {
        sfMusic_play(sound);
        while (sfMusic_getStatus(sound) == sfPlaying);
    }
}

void event_manage(window_t *window)
{
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(window->win);

    while (sfRenderWindow_pollEvent(window->win, &window->event)) {
        if (window->event.type == sfEvtClosed) {
            play_end_music(window->sounds->close,
                window->all_btnevt[BTN_SONG]->active);
            sfRenderWindow_close(window->win);
        }
        check_modif_map(window);
        mouse_roll(window);
    }
    calc_scale(window);
    window->mouse->pos = (sfVector2f){m_pos.x * window->scale.x,
        m_pos.y * window->scale.y};
    get_all_button_event(window, window->mouse->pos,
        window->scale);
    check_all_button(window->all_btn);
    set_btn_event(window);
}
