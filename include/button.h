/*
** EPITECH PROJECT, 2025
** include
** File description:
** include
*/

#ifndef BUTTON_H
    #define BUTTON_H
    #include <SFML/Graphics.h>
    #define NBR_BTN 8
    #define ANGLE_TO_ADD 1.0
    #define ZOOM_TO_ADD 0.01
    #define X_Y_TO_ADD 10.0
    #define RECT_BTNEVT_B 5
    #define SIZE_BTNEVT 50
    #define SP_BTNEVT 20
    #define NBR_BTNEVT 8
    #define MAX_ANGLE_Y 60.0
    #define MIN_ANGLE_X 0
    #define MAX_ANGLE_X 85

// other struct
typedef struct window_s window_t;

// button struct
typedef struct check_button_s {
    sfKeyCode key;
    int previous_state;
    int state;
} check_button_t;
enum ALL_BTN {
    BTN_KEY_P,
    BTN_KEY_1,
    BTN_KEY_2,
    BTN_KEY_3,
    BTN_KEY_4,
    BTN_KEY_G,
    BTN_KEY_R,
    BTN_KEY_SAVE
};

// button evt struct
typedef enum {
    ONE_CLICK,
    ALL_CLICK
} button_evt_mode_t;
typedef struct button_evt_s {
    sfRectangleShape *rect;
    sfTexture *text;
    sfSprite *sprite;
    sfVector2f init_win_size;
    sfVector2f pos;
    sfVector2f sc_pos;
    sfVector2f size;
    sfVector2f sc_size;
    sfBool hover;
    sfBool clicked;
    sfBool active;
    int previous_state;
    button_evt_mode_t md;
} button_evt_t;

enum BTN_EVENT {
    BTN_ERASE,
    BTN_GRASS,
    BTN_GROUND,
    BTN_WATER,
    BTN_EXTRUDE_UP,
    BTN_EXTRUDE_DOWN,
    BTN_SHADOW,
    BTN_SONG
};

enum COLOR_RECT {
    RECT_HOVER,
    RECT_ACTIVE
};

// buttun function
check_button_t **get_all_btn(void);
void check_all_button(check_button_t **all_btn);
int get_state(check_button_t **all_btn, sfKeyCode key);
void free_all_button(check_button_t **all_btn);
void change_angle(window_t *window);
void change_pos(window_t *window);
button_evt_t *init_button_evt(const char *, sfVector2f, sfVector2f);
void display_button_evt(sfRenderWindow *win, button_evt_t *btn, sfVector2f sc);
void get_button_event(button_evt_t *btn, sfVector2f mpos, sfVector2f sc);
void free_button_evt(button_evt_t *btn);
button_evt_t **init_all_btnevt(void);
void free_all_button_evt(button_evt_t **btn);
void display_all_btnevtt(sfRenderWindow *win, button_evt_t **b, sfVector2f sc);
void get_all_button_event(window_t *win, sfVector2f mpos, sfVector2f sc);
void put_one_active(button_evt_t **btn, int n_to_active);

#endif
