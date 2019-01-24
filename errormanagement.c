/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** errormanagement
*/

#include "myrunner.h"

int dash_h(void)
{
    write(1, "USAGE\n  ./my_runner map.txt\n  -The map have to be a 14 x "
    "(37 minimum) rectangle of '#'.\n  -There is a example file called 'map'"
    " you can change it to play another map or play with it.\n  -You must"
    "create"" columns of '1' wh"
    "ich will define the height of the pipe.\n  -For win you have to go betw"
    "een all pipe and don't touch them if you hit\n   the top of the game, a"
    " pipe or the ground you loose.\nOPTION\n  -h\tprint the u"
    "sage and quit.\n\nUSER INTERACTIONS\n  -First menu\t-Use 'T' to lock"
    " the top left character.\n\t\t-Use 'G' to lock the bottom left chara"
    "cter.\n\t\t-Use 'H' to lock the bottom right character.\n\t\t-Use 'Y'"
    " to lock the top right character.\n\t\t-Use 'ENTER' to lock your choi"
    "ce.\n\n  -Second menu\t-Use 'T' to lock the left background.\n\t\t-Us"
    "e 'G' to lock the center background.\n\t\t-Use 'H' to lock the right "
    "background.\n\t\t-Use 'ENTER' to lock your choice.\n\n  -Game\t\t-Use "
    "'SPACE' to jump.\n\t\t-Use 'ESCAPE' to quit.\n", 905);
    return (0);
}

void mapping(char **map, struct_t *all, sfRenderWindow *windw, sfClock *cloc3)
{
    float second;
    sfTime timing;

    timing = sfClock_getElapsedTime(cloc3);
    second = timing.microseconds / 1000000.0;
    colider(windw, all, map);
    if (second > 7) {
        drawing(map, all, windw);
        for (int i = 0; i < 14; i++)
            map[i]++;
        sfClock_restart(cloc3);
    }
}

void drawing(char **map, struct_t *all, sfRenderWindow *win)
{
    for (int i = 0; i < 14; i++) {
        if (map[i][1] == '1') {
            sfSprite_setPosition(all->obj->pip_normal->spr,
            (sfVector2f){1980, (i + 2) * 90});
            sfRenderWindow_drawSprite(win, all->obj->pip_normal->spr, NULL);
            sfSprite_setPosition(all->obj->pip_verlant->spr,
            (sfVector2f){1980, (i + 2) * 90 - 1300});
            sfRenderWindow_drawSprite(win, all->obj->pip_verlant->spr, NULL);
            break;
        }
    }
}

void colider(sfRenderWindow *window, struct_t *a, char **map)
{
    sfVector2f pos_bird = sfSprite_getPosition(checking(a));
    sfVector2f pos_pipe = sfSprite_getPosition(a->obj->pip_normal->spr);

    if (checking_one(map) != 0 || a->stat->life == 0) {
        if (pos_bird.y < 5 || (pos_bird.x <= pos_pipe.x + 170 && pos_bird.x
        >= pos_pipe.x - 80 && pos_bird.y >= pos_pipe.y) || (pos_bird.x <=
        pos_pipe.x + 170 && pos_bird.x >= pos_pipe.x - 80 && pos_bird.y <=
        pos_pipe.y - 400)) {
                (sfSound_getStatus(a->stat->p) != sfPlaying) ?
                sfSound_play(a->stat->p) : 0;
            a->stat->life = 0;
        } else if (pos_bird.y > 1050) {
            a->stat->life = 0;
            sfSprite_setPosition(checking(a), (sfVector2f){800, 1090});
            sfRenderWindow_drawSprite(window, checking(a), NULL);
            loose_screen(a, window, map);
        }
    } else if (a->stat->life != 0)
        win(window, a, map);
}

int checking_one(char **map)
{
    int count = 0;

    for (int i = 0; i < 14; i++) {
        for (int j = 0; map[i][j] != '\0'; j++)
            count += (map[i][j] == '1') ? 1 : 0;
    }
    return (count);
}