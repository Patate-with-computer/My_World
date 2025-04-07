/*
** EPITECH PROJECT, 2025
** check error
** File description:
** check error
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lib.h"
#include "window.h"

static int is_nb(char *str)
{
    int pos = 0;

    while (str[pos] == '+')
        pos += 1;
    if (str[pos] == '\0')
        return ERROR_EPITECH;
    while (str[pos] != '\0') {
        if (str[pos] < '0' || str[pos] > '9')
            return ERROR_EPITECH;
        pos += 1;
    }
    return 0;
}

int check_define_size(int ac, char *const *av)
{
    if (ac != 3)
        return ERROR_EPITECH;
    if (is_nb(av[1]) == ERROR_EPITECH || is_nb(av[2]) == ERROR_EPITECH)
        return ERROR_EPITECH;
    if (atoi(av[1]) > 150 || atoi(av[2]) > 150 ||
    atoi(av[1]) < 1 || atoi(av[2]) < 1)
        return ERROR_EPITECH;
    return 0;
}

static void display_file_content(char *path)
{
    int fd = open(path, O_RDONLY);
    char buff[30000];
    int size = read(fd, buff, 29999);

    write(1, &buff, size);
    close(fd);
}

int check_error(int ac, char **av)
{
    if (getenv("DISPLAY") == NULL)
        exit(ERROR_EPITECH);
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        display_file_content("README.md");
        exit(0);
    }
    if (ac == 1)
        return 0;
    if (ac == 2 && path_exist(av[1]) == 0 && is_file(av[1]) == 1
    && strstr(av[1], ".legend\0") != NULL)
        return 0;
    if (check_define_size(ac, av) != ERROR_EPITECH)
        return 0;
    exit(ERROR_EPITECH);
}
