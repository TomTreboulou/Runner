/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** draw2
*/

#include "myrunner.h"

void draw_black_yes(sfRenderWindow *window, struct_t *all)
{
    sfSprite_setPosition(all->obj->black_yes->spr, all->vec->pfblack);
    sfRenderWindow_drawSprite(window, all->obj->black_yes->spr, NULL);
}

void draw_yellow_yes(sfRenderWindow *window, struct_t *all)
{
    sfSprite_setPosition(all->obj->yellow_yes->spr, all->vec->pfyellow);
    sfRenderWindow_drawSprite(window, all->obj->yellow_yes->spr, NULL);
}

void draw_yellow_no(sfRenderWindow *window, struct_t *all)
{
    sfSprite_setPosition(all->obj->yellow_no->spr, all->vec->pfyellow);
    sfRenderWindow_drawSprite(window, all->obj->yellow_no->spr, NULL);
}

void draw_black(sfRenderWindow *window, struct_t *all)
{
    sfSprite_setTextureRect(all->obj->black->spr, all->rect->rect);
    sfRenderWindow_drawSprite(window, all->obj->black->spr, NULL);
}

void draw_yellow(sfRenderWindow *window, struct_t *all)
{
    sfSprite_setTextureRect(all->obj->yellow->spr, all->rect->rect);
    sfRenderWindow_drawSprite(window, all->obj->yellow->spr, NULL);
}