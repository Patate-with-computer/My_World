/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "window.h"
#include "world_map.h"
#include "interact.h"
#include "button.h"

int set_vertex(window_t *win, sfVector2i pos,
    sfVertexArray *quad, sfTexture *texture)
{
    sfVector2u size = sfTexture_getSize(texture);
    sfVertex vertex[4] = {
        {get_pt(win->map, pos.x, pos.y), sfWhite, {0, 0}},
        {get_pt(win->map, pos.x + 1, pos.y), sfWhite, {size.x, 0}},
        {get_pt(win->map, pos.x + 1, pos.y + 1), sfWhite, {size.x, size.y}},
        {get_pt(win->map, pos.x, pos.y + 1), sfWhite, {0, size.y}}};
    sfVector2u win_size = sfRenderWindow_getSize(win->win);
    sfVector2f pos1 = vertex[0].position;
    int mult = (int)(win->map->zoom * 3);

    if (pos1.x >= win_size.x + win->map->size.x ||
        pos1.x <= -1 * mult * win->map->size.x)
        return -1;
    if (pos1.y >= win_size.y + win->map->size.y ||
        pos1.y <= -1 * mult * win->map->size.y)
        return -1;
    for (int i = 0; i < 4; ++i)
        sfVertexArray_append(quad, vertex[i]);
    sfVertexArray_setPrimitiveType(quad, sfQuads);
    return 0;
}

static void set_shader_value(window_t *win, sfRenderStates *st,
    sfVector2i pos, texture_t texture)
{
    sfShader_setVec3Uniform(win->map->shader, "som",
        (sfGlslVec3){win->map->map[pos.y][pos.x],
                    win->map->map[pos.y][pos.x + 1],
                    GRID_SIZE});
    sfShader_setFloatUniform(win->map->shader, "time",
        (float)(get_millis(win->clock)));
    sfShader_setIntUniform(win->map->shader, "is_water", texture == WATER);
    st->shader = win->map->shader;
}

void draw_square(window_t *win, sfVector2i pos, texture_t texture)
{
    sfVertexArray *quad = sfVertexArray_create();
    sfTexture *text = win->map->all_text[texture];
    sfRenderStates st = {sfBlendAlpha, sfTransform_Identity, text, NULL};

    if (quad == NULL)
        return;
    if (set_vertex(win, pos, quad, text) != -1) {
        if (win->all_btnevt[BTN_SHADOW]->active)
            set_shader_value(win, &st, pos, texture);
        sfRenderWindow_drawVertexArray(win->win, quad, &st);
    }
    sfVertexArray_destroy(quad);
}
