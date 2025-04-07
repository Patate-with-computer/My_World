/*
** EPITECH PROJECT, 2024
** opne
** File description:
** open
*/

#include <SFML/Graphics.h>

sfInt64 get_millis(sfClock *clock)
{
    return sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
}
