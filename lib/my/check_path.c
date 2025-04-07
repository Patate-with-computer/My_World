/*
** EPITECH PROJECT, 2025
** check path
** File description:
** check path
*/

#include <stddef.h>
#include <sys/stat.h>
#include "window.h"

int path_exist(char const *path)
{
    struct stat buff;
    int exist = stat(path, &buff);

    if (exist == 0)
        return 0;
    return ERROR_EPITECH;
}

int is_file(char const *path)
{
    struct stat sb = {0};

    lstat(path, &sb);
    return (sb.st_mode & S_IFMT) == S_IFREG;
}
