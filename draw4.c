/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** draw4
*/

#include "myrunner.h"

void draw_day_yes(sfRenderWindow *window, struct_t *all)
{
    sfSprite_setPosition(all->obj->day_yes->spr, all->vec->back_day);
    sfRenderWindow_drawSprite(window, all->obj->day_yes->spr, NULL);
}

void draw_day_no(sfRenderWindow *window, struct_t *all)
{
    sfSprite_setPosition(all->obj->day_no->spr, all->vec->back_day);
    sfRenderWindow_drawSprite(window, all->obj->day_no->spr, NULL);
}

void draw_night_yes(sfRenderWindow *window, struct_t *all)
{
    sfSprite_setPosition(all->obj->night_yes->spr, all->vec->back_night);
    sfRenderWindow_drawSprite(window, all->obj->night_yes->spr, NULL);
}

void draw_night_no(sfRenderWindow *window, struct_t *all)
{
    sfSprite_setPosition(all->obj->night_no->spr, all->vec->back_night);
    sfRenderWindow_drawSprite(window, all->obj->night_no->spr, NULL);
}

void draw_bl_yes(sfRenderWindow *window, struct_t *all)
{
    sfSprite_setPosition(all->obj->bl_yes->spr, all->vec->back_bl);
    sfRenderWindow_drawSprite(window, all->obj->bl_yes->spr, NULL);
}