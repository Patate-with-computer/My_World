/*
** EPITECH PROJECT, 2025
** mouse_interact
** File description:
** interaction
*/

#include "lib.h"
#include <SFML/Audio.h>

void play_size_music(void *music)
{
    sfMusic_play(music);
}

void play_thread_music(sfMusic *sound, int diff, int play)
{
    sfThread *th = sfThread_create(play_size_music, sound);

    if (th == NULL)
        return;
    if (diff != 0 && play)
        sfThread_launch(th);
    sfThread_destroy(th);
}
