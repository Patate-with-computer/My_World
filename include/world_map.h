/*
** EPITECH PROJECT, 2025
** include
** File description:
** include
*/

#ifndef WORLD_MAP_H
    #define WORLD_MAP_H
    #include <SFML/Graphics.h>
    #define PI 3.141592653589793
    #define MATH_E 2.718281828
    #define MIN_ZOOM 0.61
    #define CONV (float)(3.14 / 180.0)
    #define FREQ_SOM 4.0
    #define NBR_PERM 256
    #define MAX_PERLIN 400
    #define FRAG_SHAD "bonus/shader.frag"
    #include <time.h>

// extern function
//extern unsigned int time(int *clock);
extern int rand(void);
extern void srand(unsigned int seed);

// other struct
typedef struct window_s window_t;

// texture list
    #define NBR_TEXTURE 4
typedef enum texture_s {
    CHANGE,
    GRASS,
    GROUND,
    WATER,
    NO_PRINT
} texture_t;
sfTexture **init_texture(void);
void destroy_all_texture(sfTexture **all_text);
void draw_texture(window_t *window);

// define the grid of the world
enum WIN_GRID {
    GRID_X = 100,
    GRID_Y = 100,
    GRID_SIZE = 50
};

enum EXTRUDE {
    NO_EXTRUDE = 0,
    EXTRUDE_UP = 1,
    EXTRUDE_DOWN = -1
};

// struct for the map use
typedef struct world_map_s {
    int **map;
    int **texture_map;
    sfVector2f add_x_y;
    sfVector2i size;
    sfVector2f angle;
    sfVector2f center;
    sfTexture **all_text;
    sfVector2f scale;
    float zoom;
    int draw;
    int extrude;
    texture_t to_print;
    sfBool display_grid;
    sfShader *shader;
    sfBool show_shadow;
} world_map_t;

// function to modify the map
sfVector2f project_point(sfVector3f pt, sfVector2f angle);
void free_2d_map(world_map_t *map);
int **init_2d_map(sfVector2i size);
world_map_t *init_map(int ac, char **argv);
sfVector2f get_pt(world_map_t *map, int x, int y);
void draw_2d_map(world_map_t *map, window_t *window);
void random_perlin(int **image, sfVector2i size);
double grad(int hash, double x, double y);
double fade(double t);
double lerp(double t, double a, double b);
void change_permutation(int perm[NBR_PERM]);
int calc_angle(world_map_t *map, int x, int y, sfVector2f pos);
void draw_square(window_t *win, sfVector2i pos, texture_t texture);
void find_touch_square(window_t *window);
sfVector2i get_touch_square_pos(world_map_t *map, sfVector2f m_pos);
float get_distance(sfVector2f pt1, sfVector2f pt2);
void auto_complete(world_map_t *map);
void create_map_file(world_map_t *map);
int get_map_from_file(const char *filepath, world_map_t *map);

#endif
