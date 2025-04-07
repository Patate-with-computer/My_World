/*
** EPITECH PROJECT, 2025
** interact.h
** File description:
** interact.h
*/

#ifndef INTERACT_H
    #define INTERACT_H
    #include <SFML/Graphics.h>
    #define MOUSE_CIRCLE sfRed
    #define CIRCLE_OUTLINE 5.0
    #define GET_CENTER 3
    #define POINT_FOUND 0
    #define POINT_NOT_FOUND 1

// other struct
typedef struct window_s window_t;

typedef struct interact_s {
    sfVector2f pos;
    int x_map;
    int y_map;
} interact_t;

void create_circle(sfRenderWindow *window, sfVector2f pos);
interact_t *init_mouse(void);
void check_interact(window_t *window, int difference);
void follow_mouse(window_t *window);

#endif
