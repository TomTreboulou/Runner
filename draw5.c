/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** draw5
*/

#include "myrunner.h"

void draw_bl_no(sfRenderWindow *window, struct_t *all)
{
    sfSprite_setPosition(all->obj->bl_no->spr, all->vec->back_bl);
    sfRenderWindow_drawSprite(window, all->obj->bl_no->spr, NULL);
}

void score(struct_t *all, sfRenderWindow *window, char **map)
{
    int numb;
    char *numb_passed;
    char *nb;
    char *info1;
    char *rest = " pipe(s).";

    numb = searching_one(map);
    nb = int_to_str(numb);
    info1 = my_strcat("There is ", nb);
    info1 = my_strcat(info1, rest);
    sfText_setString(all->stat->t1, info1);
    sfRenderWindow_drawText(window, all->stat->t1, NULL);
}

int searching_one(char **map)
{
    int compteur = 0;

    for (int i = 0; i < 14; i++) {
        for (int j = 0; map[i][j] != '\0'; j++)
            compteur += (map[i][j] == '1');
    }
    return (compteur);
}

char *int_to_str(int nb)
{
    char *str = NULL;
    int count = 0;
    int i = 0;
    int numb = nb;

    for (; nb > 9; nb /= 10, count++);
    str = malloc(sizeof(count + 2));
    for (; numb > 9; numb /= 10, i++)
        str[i] = (numb % 10 + 48);
    str[i] = numb + 48;
    str[i + 1] = '\0';
    return (str);
}

char *my_strcat(char *dest, char const *src)
{
    char *st = NULL;
    int i = 0;

    for (; dest[i] != '\0'; i++);
    for (int j = 0; src[j] != '\0'; j++, i++);
    st = malloc(sizeof(char) * i + 1);
    if (!st)
        return (st);
    for (i = 0; dest[i] != '\0'; i++)
        st[i] = dest[i];
    for (int j = 0; src[j] != '\0'; j++, i++)
        st[i] = src[j];
    st[i] = '\0';
    return (st);
}