/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** settings
*/

#include "myrunner.h"

void settings(sfRenderWindow *window, struct_t *all, sfEvent event)
{
    sfSprite_setPosition(all->obj->bouton->spr, (sfVector2f){800, 380});
    sfRenderWindow_drawSprite(window, all->obj->bouton->spr, NULL);
    all->stat->flappy = flappy(all);
    if (all->stat->flappy == 1)
        draw_fr_yes(window, all);
    else
        draw_fr_no(window, all);
    if (all->stat->flappy == 2)
        draw_lgbt_yes(window, all);
    else
        draw_lgbt_no(window, all);
    if (all->stat->flappy == 3)
        draw_black_yes(window, all);
    else
        draw_black_no(window, all);
    if (all->stat->flappy == 4)
        draw_yellow_yes(window, all);
    else
        draw_yellow_no(window, all);
}

int flappy(struct_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyT))
        all->stat->flappy = 1;
    if (sfKeyboard_isKeyPressed(sfKeyG))
        all->stat->flappy = 2;
    if (sfKeyboard_isKeyPressed(sfKeyY))
        all->stat->flappy = 3;
    if (sfKeyboard_isKeyPressed(sfKeyH))
        all->stat->flappy = 4;
    return (all->stat->flappy);
}

void settings2(sfRenderWindow *w, struct_t *all, sfClock *clock, char **map)
{
    while (!(sfKeyboard_isKeyPressed(sfKeyNum1)) && sfRenderWindow_isOpen(w)) {
        all->stat->back = back(all);
        if (all->stat->back == 1)
            draw_day_yes(w, all);
        else
            draw_day_no(w, all);
        if (all->stat->back == 2)
            draw_night_yes(w, all);
        else
            draw_night_no(w, all);
        if (all->stat->back == 3)
            draw_bl_yes(w, all);
        else
            draw_bl_no(w, all);
        disp_clear(w, all);
        if (sfKeyboard_isKeyPressed(sfKeyEnter))
            game_loop(w, clock, all, map);
        back_loop(w, all);
    }
}

int back(struct_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyG))
        all->stat->back = 1;
    if (sfKeyboard_isKeyPressed(sfKeyH))
        all->stat->back = 2;
    if (sfKeyboard_isKeyPressed(sfKeyT))
        all->stat->back = 3;
    return (all->stat->back);
}

void disp_clear(sfRenderWindow *w, struct_t *all)
{
    sfSprite_setPosition(all->obj->bton2->spr, (sfVector2f){600, 25});
    sfRenderWindow_drawSprite(w, all->obj->bton2->spr, NULL);
    sfRenderWindow_display(w);
    sfRenderWindow_clear(w, sfBlack);
}