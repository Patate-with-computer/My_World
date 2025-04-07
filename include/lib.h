/*
** EPITECH PROJECT, 2025
** include
** File description:
** include
*/

#ifndef LIB_H
    #define LIB_H
    #include <stddef.h>
    #define MY_FREE(ptr) ((ptr == NULL) ? (0) : (free(ptr)))

// externs functions
extern void *malloc(size_t size);
extern void free(void *ptr);

// lib functions
int randint(int a, int b);

//check_error
int check_error(int ac, char **argv);

#endif
