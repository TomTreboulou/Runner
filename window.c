/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** window
*/

#include "myrunner.h"
#include <sys/stat.h>
#include <fcntl.h>

void wind(sfRenderWindow* window)
{
    if (!window)
        return;
    sfRenderWindow_setMouseCursorVisible(window, 0);
    sfRenderWindow_setFramerateLimit(window, 40);
}

char **prepare_map(char *map)
{
    int fd = 0;
    struct stat stat_s;
    char *maper;

    fd = open(map, O_RDONLY);
    if (fd == -1)
        return (NULL);
    if (stat(map, &stat_s) == -1)
        return (NULL);
    maper = malloc(sizeof(char) * stat_s.st_size);
    read(fd, maper, stat_s.st_size);
    return (preparation(maper, stat_s.st_size));
}

char **preparation(char *str, int size)
{
    char **map = malloc(sizeof(char *) * 14);
    int k = 0;
    int back_n = 0;

    for (int i = 0; i < 14; i++) {
        map[i] = malloc(sizeof(char) * size + 1);
        for (int k = 0; k < size + 1; k++)
            map[i][k] = '\0';
    }
    for (int j = 0, n = 0; back_n < 13; j++) {
        map[n][k] = str[j];
        if (str[j] == '\n') {
            map[n][k] = '\0';
            k = 0;
            n++;
            back_n++;
        } else
            k++;
    }
    return (map);
}