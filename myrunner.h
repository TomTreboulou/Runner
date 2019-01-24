/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** myrunner
*/

#ifndef MYRUNNER_H_
    #define MYRUNNER_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <string.h>
#include "myrunner.h"
#include <stdio.h>
#include <SFML/Window.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/Time.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct vector_s
{
    sfVector2f psky;
    sfVector2f pbus;
    sfVector2f pbas;
    sfVector2f pbui;
    sfVector2f pclo;
    sfVector2f pffr;
    sfVector2f pflgbt;
    sfVector2f pfblack;
    sfVector2f pfyellow;
    sfVector2f game;
    sfVector2f back_day;
    sfVector2f back_night;
    sfVector2f back_bl;
} vector_t;

typedef struct game_object
{
    sfTexture *tex;
    sfSprite *spr;
} game_object_t;

typedef struct rect_s
{
    sfIntRect rect;
} rect_t;

typedef struct object_s
{
    game_object_t *cloud;
    game_object_t *build;
    game_object_t *bush;
    game_object_t *sky;
    game_object_t *base;
    game_object_t *fr_yes;
    game_object_t *fr_no;
    game_object_t *lgbt_yes;
    game_object_t *lgbt_no;
    game_object_t *black_yes;
    game_object_t *black_no;
    game_object_t *yellow_yes;
    game_object_t *yellow_no;
    game_object_t *yellow;
    game_object_t *black;
    game_object_t *fr;
    game_object_t *lgbt;
    game_object_t *ncloud;
    game_object_t *nbuild;
    game_object_t *nbush;
    game_object_t *nsky;
    game_object_t *blcloud;
    game_object_t *blsky;
    game_object_t *blbuild;
    game_object_t *blbase;
    game_object_t *blbush;
    game_object_t *day_yes;
    game_object_t *day_no;
    game_object_t *night_yes;
    game_object_t *night_no;
    game_object_t *bl_yes;
    game_object_t *bl_no;
    game_object_t *pip_normal;
    game_object_t *pip_verlant;
    game_object_t *bouton;
    game_object_t *bton2;
    game_object_t *win;
    game_object_t *loose;
} object_t;

typedef struct statement_s
{
    sfMusic *music;
    sfSoundBuffer * sb;
    sfSound *jump;
    sfSoundBuffer * sb2;
    sfSound *p;
    sfText *t1;
    sfText *t2;
    int passed;
    int flappy;
    int grav;
    int back;
    int life;
} statement_t;

typedef struct struct_s
{
    vector_t *vec;
    object_t *obj;
    statement_t *stat;
    rect_t *rect;
} struct_t;

    void score(struct_t *, sfRenderWindow *, char **);
    int searching_one(char **);
    char *my_strcat(char *, char const *);
    char *int_to_str(int );
    void mooove(struct_t *, sfRenderWindow *);
    void disp_clear(sfRenderWindow *, struct_t *);
    void loose_screen(struct_t *, sfRenderWindow *, char **);
    void win(sfRenderWindow *, struct_t *, char **);
    int checking_one(char **);
    void colider(sfRenderWindow *, struct_t *, char **);
    void mapping(char **, struct_t *, sfRenderWindow *, sfClock *);
    void drawing(char **, struct_t *, sfRenderWindow *);
    char **preparation(char *, int);
    char **prepare_map(char *);
    void animation(struct_t *, sfRenderWindow *, sfClock *);
    sfSprite *checking(struct_t *);
    void fall(struct_t *, sfClock *, float);
    void check_space(struct_t *, sfClock *, sfRenderWindow *, float);
    void destroy(struct_t *, sfRenderWindow *);
    void draw_bl_no(sfRenderWindow *, struct_t *);
    void draw_day_yes(sfRenderWindow *, struct_t *);
    void draw_day_no(sfRenderWindow *, struct_t *);
    void draw_night_yes(sfRenderWindow *, struct_t *);
    void draw_night_no(sfRenderWindow *, struct_t *);
    void draw_bl_yes(sfRenderWindow *, struct_t *);
    void back_no_bl(sfRenderWindow *, struct_t *);
    void back_day(sfRenderWindow *, struct_t *);
    void back_night(sfRenderWindow *, struct_t *);
    int back(struct_t *);
    void settings2(sfRenderWindow *, struct_t *, sfClock *, char **);
    void object2(object_t *, vector_t *);
    void draw_lgbt(sfRenderWindow *, struct_t *);
    void draw_fr(sfRenderWindow *, struct_t *);
    void draw_game(sfRenderWindow *, struct_t *, char **);
    void draw_yellow(sfRenderWindow *, struct_t *);
    void draw_black(sfRenderWindow *, struct_t *);
    void rectangle(rect_t *);
    void move_rect(struct_t *, sfClock *, float);
    void wind(sfRenderWindow* );
    void statement(statement_t *);
    int flappy(struct_t *);
    void draw_yellow_no(sfRenderWindow *, struct_t *);
    void draw_yellow_yes(sfRenderWindow *, struct_t *);
    void draw_black_yes(sfRenderWindow *, struct_t *);
    void draw_lgbt_yes(sfRenderWindow *, struct_t *);
    void draw_fr_no(sfRenderWindow *, struct_t *);
    void draw_fr_yes(sfRenderWindow *, struct_t *);
    void draw_lgbt_no(sfRenderWindow *, struct_t *);
    void draw_black_no(sfRenderWindow *, struct_t *);
    void game_loop(sfRenderWindow *, sfClock *, struct_t *, char **);
    void init_struct(struct_t *);
    void object(object_t *, vector_t *);
    void vector(vector_t *);
    game_object_t *create_object(const char *, sfVector2f);
    void esc(sfRenderWindow *, sfEvent);
    void back_loop(sfRenderWindow *, struct_t *);
    void settings(sfRenderWindow *, struct_t *, sfEvent);
    void launch_game(size_t , sfRenderWindow *, char **);
    int dash_h(void);

#endif /* !MYRUNNER_H_ */
