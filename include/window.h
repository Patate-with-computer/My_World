/*
** EPITECH PROJECT, 2025
** include
** File description:
** include
*/

#ifndef WINDOW_H
    #define WINDOW_H
    #include <SFML/Graphics.h>
    #define ERROR_EPITECH 84
    #include <SFML/Audio.h>
    #define BACKGROUND_MUSIC "ressources/background_music1.ogg"
    #define VOL 20.0

// window mode
enum WIN_MODE {
    WIN_WIDTH = 1080,
    WIN_HEIGTH = 960,
    BPP = 32
};

// other struct
typedef struct world_map_s world_map_t;
typedef struct interact_s interact_t;
typedef struct check_button_s check_button_t;
typedef struct button_evt_s button_evt_t;
// sound structure
typedef struct {
    sfMusic *size;
    sfMusic *click;
    sfMusic *close;
    sfMusic *shaders;
    sfMusic *perlin;
    sfMusic *zoom;
    sfMusic *save;
    sfMusic *background;
} sounds_t;

// window struct
typedef struct window_s {
    sfRenderWindow *win;
    sfEvent event;
    world_map_t *map;
    interact_t *mouse;
    check_button_t **all_btn;
    sfVector2f scale;
    button_evt_t **all_btnevt;
    sfClock *clock;
    sounds_t *sounds;
} window_t;

// create sounds
sounds_t *init_sounds(void);
void music_launch(sfMusic *music);
void destroy_sounds(sounds_t *sounds);

// window manage function
void event_manage(window_t *window);
window_t *init_window(int ac, char **argv);
void calc_scale(window_t *win);

// display the window
void window_loop(window_t *window);

// check a path
int path_exist(char const *path);
int is_file(char const *path);
sfInt64 get_millis(sfClock *clock);

void play_thread_music(sfMusic *sound, int diff, int play);

#endif
