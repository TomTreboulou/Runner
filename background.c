/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Bg
*/

#include "myrunner.h"

void back_loop(sfRenderWindow *window, struct_t *all)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event))
        esc(window, event);
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

void object(object_t *obj, vector_t *vec)
{
    obj->sky = create_object("Pic/Bg/Day/sky.png", vec->psky);
    obj->bush = create_object("Pic/Bg/Day/bush.png", vec->pbus);
    obj->base = create_object("Pic/Bg/base.png", vec->pbas);
    obj->build = create_object("Pic/Bg/Day/build.png", vec->pbui);
    obj->cloud = create_object("Pic/Bg/Day/cloud.png", vec->pclo);
    obj->fr_yes = create_object("Pic/Set/fr_yes.png", vec->pffr);
    obj->fr_no = create_object("Pic/Set/fr_no.png", vec->pffr);
    obj->lgbt_yes = create_object("Pic/Set/lgbt_yes.png", vec->pflgbt);
    obj->lgbt_no = create_object("Pic/Set/lgbt_no.png", vec->pflgbt);
    obj->black_yes = create_object("Pic/Set/black_yes.png", vec->pfblack);
    obj->black_no = create_object("Pic/Set/black_no.png", vec->pfblack);
    obj->yellow_yes = create_object("Pic/Set/yellow_yes.png", vec->pfyellow);
    obj->yellow_no = create_object("Pic/Set/yellow_no.png", vec->pfyellow);
    obj->yellow = create_object("Pic/Flappy/Yellow/yellow.png", vec->game);
    obj->black = create_object("Pic/Flappy/black.png", vec->game);
    obj->fr = create_object("Pic/Flappy/fr.png", vec->game);
    obj->lgbt = create_object("Pic/Flappy/lgbt.png", vec->game);
    obj->nsky = create_object("Pic/Bg/Night/sky.png", vec->psky);
    obj->ncloud = create_object("Pic/Bg/Night/cloud.png", vec->pclo);
    obj->nbush = create_object("Pic/Bg/Night/bush.png", vec->pbus);
}

void object2(object_t *obj, vector_t *vec)
{
    obj->nbuild = create_object("Pic/Bg/Night/build.png", vec->pbui);
    obj->blbase = create_object("Pic/Bg/Black/base.png", vec->pbas);
    obj->blbuild = create_object("Pic/Bg/Black/build.png", vec->pbui);
    obj->blcloud = create_object("Pic/Bg/Black/cloud.png", vec->pclo);
    obj->blsky = create_object("Pic/Bg/Black/sky.png", vec->psky);
    obj->blbush = create_object("Pic/Bg/Black/bush.png", vec->pbus);
    obj->day_yes = create_object("Pic/Set/day_yes.png", vec->back_day);
    obj->day_no = create_object("Pic/Set/day_no.png", vec->back_day);
    obj->night_yes = create_object("Pic/Set/night_yes.png", vec->back_night);
    obj->night_no = create_object("Pic/Set/night_no.png", vec->back_night);
    obj->bl_yes = create_object("Pic/Set/back_black_yes.png", vec->back_bl);
    obj->bl_no = create_object("Pic/Set/back_black_no.png", vec->back_bl);
    obj->pip_normal = create_object("Pic/pipe-green.png",
    (sfVector2f){500, 0});
    obj->pip_verlant = create_object("Pic/pipe-green_verlant.png",
    (sfVector2f){500, 0});
    obj->bouton = create_object("Pic/button.png", vec->back_day);
    obj->bton2 = create_object("Pic/button2.png", vec->back_day);
    obj->loose = create_object("Pic/loose.png", vec->back_day);
    obj->win = create_object("Pic/win.png", vec->back_day);
}

void esc(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
    }
}