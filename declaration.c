/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** declaration
*/

#include "myrunner.h"

game_object_t *create_object(const char *path, sfVector2f pos)
{
    game_object_t *obj = malloc(sizeof(game_object_t));

    obj->tex = sfTexture_createFromFile(path, NULL);
    obj->spr = sfSprite_create();
    sfSprite_setTexture(obj->spr, obj->tex, sfTrue);
    return (obj);
}

void statement(statement_t *stat)
{
    stat->flappy = 1;
    stat->grav = 0;
    stat->back = 1;
    stat->life = 1;
    stat->passed = 0;
    stat->t1 = sfText_create();
    sfText_setFont(stat->t1, sfFont_createFromFile("font/flappy.otf"));
    sfText_setCharacterSize(stat->t1, 50);
    sfText_setPosition(stat->t1, (sfVector2f){10, 0});
    stat->music = sfMusic_createFromFile("leek-spin.ogg");
    sfMusic_setVolume(stat->music, 100.0);
    sfMusic_setLoop(stat->music, sfTrue);
    stat->sb = sfSoundBuffer_createFromFile("jump.ogg");
    stat->jump = sfSound_create();
    sfSound_setBuffer(stat->jump, stat->sb);
    stat->sb2 = sfSoundBuffer_createFromFile("impact.ogg");
    stat->p = sfSound_create();
    sfSound_setBuffer(stat->p, stat->sb2);
}

void vector(vector_t *vec)
{
    vec->psky = (sfVector2f){0, 0};
    vec->pbus = (sfVector2f){0, 0};
    vec->pbas = (sfVector2f){0, 0};
    vec->pbui = (sfVector2f){0, 0};
    vec->pclo = (sfVector2f){0, 0};
    vec->pffr = (sfVector2f){584, 216};
    vec->pflgbt = (sfVector2f){584, 648};
    vec->pfblack = (sfVector2f){1336, 216};
    vec->pfyellow = (sfVector2f){1336, 648};
    vec->game = (sfVector2f){850, 400};
    vec->back_bl = (sfVector2f){400, 280};
    vec->back_day = (sfVector2f){800, 280};
    vec->back_night = (sfVector2f){1200, 280};
}

void rectangle(rect_t *rect)
{
    rect->rect.top = 0;
    rect->rect.left = 0;
    rect->rect.width = 100;
    rect->rect.height = 100;
}