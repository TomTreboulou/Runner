/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** move
*/

#include "myrunner.h"

void move_rect(struct_t *all, sfClock *clock, float seconds)
{
    all->rect->rect.left += 100;
    if (all->rect->rect.left > 200)
        all->rect->rect.left = 0;
    sfClock_restart(clock);
}

void draw_game(sfRenderWindow *window, struct_t *all, char **map)
{
    if (all->stat->back == 1)
        back_day(window, all);
    else if (all->stat->back == 2)
        back_night(window, all);
    else
        back_no_bl(window, all);
    mooove(all, window);
    if (all->stat->flappy == 3)
        draw_black(window, all);
    else if (all->stat->flappy == 4 || all->stat->flappy == 2) {
        if (all->stat->flappy == 4)
            draw_yellow(window, all);
        else
            draw_lgbt(window, all);
    } else
        draw_fr(window, all);
    score(all, window, map);
}

void loose_screen(struct_t *all, sfRenderWindow *window, char **map)
{
    draw_game(window, all, map);
    sfSprite_setPosition(all->obj->loose->spr, (sfVector2f){600, 400});
    sfRenderWindow_drawSprite(window, all->obj->loose->spr, NULL);
}

void win(sfRenderWindow *window, struct_t *all, char **map)
{
    draw_game(window, all, map);
    sfSprite_setPosition(all->obj->win->spr, (sfVector2f){800, 450});
    sfRenderWindow_drawSprite(window, all->obj->win->spr, NULL);
}

void mooove(struct_t *all, sfRenderWindow *window)
{
    sfSprite_move(all->obj->pip_normal->spr, (sfVector2f){-10, 0});
    sfSprite_move(all->obj->pip_verlant->spr, (sfVector2f){-10, 0});
    sfRenderWindow_drawSprite(window, all->obj->pip_normal->spr, NULL);
    sfRenderWindow_drawSprite(window, all->obj->pip_verlant->spr, NULL);
}