/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** game
*/

#include "myrunner.h"

void game_loop(sfRenderWindow *w, sfClock *clock, struct_t *all, char **map)
{
    float seconds;
    sfTime timer;
    sfClock *clock2 = sfClock_create();
    sfClock *clock3 = sfClock_create();

    sfSprite_setPosition(checking(all), all->vec->back_day);
    sfClock_restart(clock);
    while (sfRenderWindow_isOpen(w)) {
        sfRenderWindow_setFramerateLimit(w, 35);
        timer = sfClock_getElapsedTime(clock);
        seconds = timer.microseconds / 1000000.0;
        draw_game(w, all, map);
        mapping(map, all, w, clock3);
        animation(all, w, clock2);
        fall(all, clock, seconds);
        check_space(all, clock, w, seconds);
        sfRenderWindow_display(w);
        sfRenderWindow_clear(w, sfBlack);
        back_loop(w, all);
    }
}

void check_space(struct_t *all, sfClock *clock, sfRenderWindow *w, float s)
{
    float angle = sfSprite_getRotation(checking(all));

    if (sfKeyboard_isKeyPressed(sfKeySpace) && all->stat->grav != 1 &&
    all->stat->life != 0) {
        sfSound_play(all->stat->jump);
        all->stat->grav = 1;
        sfClock_restart(clock);
    }
    if (all->stat->grav == 1 && s <= 0.5) {
        sfSprite_move(checking(all), (sfVector2f){0, -10 + s * 15});
        if (angle >= 360 || angle <= 90)
            sfSprite_rotate(checking(all), -3);
    }
    else if (all->stat->grav == 1)
        all->stat->grav = 2;
}

void fall(struct_t *all, sfClock *clock, float seconds)
{
    float angle = sfSprite_getRotation(checking(all));

    if (all->stat->grav == 2) {
        all->stat->grav = 0;
        sfClock_restart(clock);
    }
    if (all->stat->grav == 0) {
        sfSprite_move(checking(all), (sfVector2f){0, seconds * 20});
        if (angle < 88 || angle >= 268)
            sfSprite_rotate(checking(all), 1.7);
    }
}

sfSprite *checking(struct_t *all)
{
    if (all->stat->flappy == 1)
        return (all->obj->fr->spr);
    else if (all->stat->flappy == 2 || all->stat->flappy == 3) {
        if (all->stat->flappy == 2)
            return (all->obj->lgbt->spr);
        else
            return (all->obj->black->spr);
    } else
        return (all->obj->yellow->spr);
}

void animation(struct_t *all, sfRenderWindow *window, sfClock *clock2)
{
    sfTime time2;
    float second;

    time2 = sfClock_getElapsedTime(clock2);
    second = time2.microseconds / 1000000.0;
    if (second > 0.09)
        move_rect(all, clock2, second);
}