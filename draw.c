/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** draw
*/

#include "myrunner.h"

void draw_fr_yes(sfRenderWindow *window, struct_t *all)
{
    sfSprite_setPosition(all->obj->fr_yes->spr, all->vec->pffr);
    sfRenderWindow_drawSprite(window, all->obj->fr_yes->spr, NULL);
}

void draw_fr_no(sfRenderWindow *window, struct_t *all)
{
    sfSprite_setPosition(all->obj->fr_no->spr, all->vec->pffr);
    sfRenderWindow_drawSprite(window, all->obj->fr_no->spr, NULL);
}

void draw_lgbt_yes(sfRenderWindow *window, struct_t *all)
{
    sfSprite_setPosition(all->obj->lgbt_yes->spr, all->vec->pflgbt);
    sfRenderWindow_drawSprite(window, all->obj->lgbt_yes->spr, NULL);
}

void draw_lgbt_no(sfRenderWindow *window, struct_t *all)
{
    sfSprite_setPosition(all->obj->lgbt_no->spr, all->vec->pflgbt);
    sfRenderWindow_drawSprite(window, all->obj->lgbt_no->spr, NULL);
}

void draw_black_no(sfRenderWindow *window, struct_t *all)
{
    sfSprite_setPosition(all->obj->black_no->spr, all->vec->pfblack);
    sfRenderWindow_drawSprite(window, all->obj->black_no->spr, NULL);
}