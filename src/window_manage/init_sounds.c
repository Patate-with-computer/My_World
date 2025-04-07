/*
** EPITECH PROJECT, 2025
** init sounds
** File description:
** init sounds
*/

#include "window.h"
#include "lib.h"

void destroy_sounds(sounds_t *sounds)
{
    sfMusic_destroy(sounds->size);
    sfMusic_destroy(sounds->close);
    sfMusic_destroy(sounds->shaders);
    sfMusic_destroy(sounds->perlin);
    sfMusic_destroy(sounds->zoom);
    sfMusic_destroy(sounds->save);
    sfMusic_destroy(sounds->background);
    sfMusic_destroy(sounds->click);
    MY_FREE(sounds);
}

void music_launch(sfMusic *music)
{
    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, VOL);
}

sounds_t *init_sounds(void)
{
    sounds_t *sounds = malloc(sizeof(sounds_t));

    if (sounds == NULL)
        return NULL;
    sounds->size = sfMusic_createFromFile("ressources/change_size.ogg");
    sounds->click = sfMusic_createFromFile("ressources/click.ogg");
    sounds->close = sfMusic_createFromFile("ressources/close_window.ogg");
    sounds->shaders = sfMusic_createFromFile("ressources/hmm.ogg");
    sounds->perlin = sfMusic_createFromFile("ressources/perlin.ogg");
    sounds->zoom = sfMusic_createFromFile("ressources/zoom.ogg");
    sounds->save = sfMusic_createFromFile("ressources/save.ogg");
    sounds->background = sfMusic_createFromFile(BACKGROUND_MUSIC);
    if (sounds->size == NULL || sounds->click == NULL || sounds->close == NULL
        || sounds->shaders == NULL || sounds->perlin == NULL ||
        sounds->zoom == NULL || sounds->save == NULL ||
        sounds->background == NULL)
        return NULL;
    return sounds;
}
