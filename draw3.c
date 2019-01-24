/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** draw3
*/

#include "myrunner.h"

void draw_fr(sfRenderWindow *window, struct_t *all)
{
    sfSprite_setTextureRect(all->obj->fr->spr, all->rect->rect);
    sfRenderWindow_drawSprite(window, all->obj->fr->spr, NULL);
}

void draw_lgbt(sfRenderWindow *window, struct_t *all)
{
    sfSprite_setTextureRect(all->obj->lgbt->spr, all->rect->rect);
    sfRenderWindow_drawSprite(window, all->obj->lgbt->spr, NULL);
}

void back_day(sfRenderWindow *window, struct_t *all)
{
    sfRenderWindow_drawSprite(window, all->obj->sky->spr, NULL);
    sfRenderWindow_drawSprite(window, all->obj->cloud->spr, NULL);
    all->vec->pclo.x -= (all->vec->pclo.x <= -1920) ? all->vec->pclo.x : 2;
    sfSprite_setPosition(all->obj->cloud->spr, all->vec->pclo);
    sfRenderWindow_drawSprite(window, all->obj->build->spr, NULL);
    all->vec->pbui.x = (all->vec->pbui.x <= -1920) ? 0 : all->vec->pbui.x - 4;
    sfSprite_setPosition(all->obj->build->spr, all->vec->pbui);
    sfRenderWindow_drawSprite(window, all->obj->bush->spr, NULL);
    all->vec->pbus.x -= (all->vec->pbus.x <= -1920) ? all->vec->pbus.x : 6;
    sfSprite_setPosition(all->obj->bush->spr, all->vec->pbus);
    sfRenderWindow_drawSprite(window, all->obj->base->spr, NULL);
    all->vec->pbas.x = (all->vec->pbas.x <= -1920) ? 0 : all->vec->pbas.x - 8;
    sfSprite_setPosition(all->obj->base->spr, all->vec->pbas);
}

void back_night(sfRenderWindow *window, struct_t *all)
{
    sfRenderWindow_drawSprite(window, all->obj->nsky->spr, NULL);
    sfRenderWindow_drawSprite(window, all->obj->ncloud->spr, NULL);
    all->vec->pclo.x -= (all->vec->pclo.x <= -1920) ? all->vec->pclo.x : 2;
    sfSprite_setPosition(all->obj->ncloud->spr, all->vec->pclo);
    sfRenderWindow_drawSprite(window, all->obj->nbuild->spr, NULL);
    all->vec->pbui.x = (all->vec->pbui.x <= -1920) ? 0 : all->vec->pbui.x - 4;
    sfSprite_setPosition(all->obj->nbuild->spr, all->vec->pbui);
    sfRenderWindow_drawSprite(window, all->obj->nbush->spr, NULL);
    all->vec->pbus.x -= (all->vec->pbus.x <= -1920) ? all->vec->pbus.x : 6;
    sfSprite_setPosition(all->obj->nbush->spr, all->vec->pbus);
    sfRenderWindow_drawSprite(window, all->obj->base->spr, NULL);
    all->vec->pbas.x = (all->vec->pbas.x <= -1920) ? 0 : all->vec->pbas.x - 8;
    sfSprite_setPosition(all->obj->base->spr, all->vec->pbas);
}

void back_no_bl(sfRenderWindow *window, struct_t *all)
{
    sfRenderWindow_drawSprite(window, all->obj->blsky->spr, NULL);
    sfRenderWindow_drawSprite(window, all->obj->blcloud->spr, NULL);
    all->vec->pclo.x -= (all->vec->pclo.x <= -1920) ? all->vec->pclo.x : 2;
    sfSprite_setPosition(all->obj->blcloud->spr, all->vec->pclo);
    sfRenderWindow_drawSprite(window, all->obj->blbuild->spr, NULL);
    all->vec->pbui.x = (all->vec->pbui.x <= -1920) ? 0 : all->vec->pbui.x - 4;
    sfSprite_setPosition(all->obj->blbuild->spr, all->vec->pbui);
    sfRenderWindow_drawSprite(window, all->obj->blbush->spr, NULL);
    all->vec->pbus.x -= (all->vec->pbus.x <= -1920) ? all->vec->pbus.x : 6;
    sfSprite_setPosition(all->obj->blbush->spr, all->vec->pbus);
    sfRenderWindow_drawSprite(window, all->obj->blbase->spr, NULL);
    sfSprite_setPosition(all->obj->blbase->spr, all->vec->pbas);
}