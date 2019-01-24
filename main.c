/*
** EPITECH PROJECT, 2018
** main
** File description:
** csfml
*/

#include "myrunner.h"

int main(int ac, char **av)
{
    size_t count;
    const sfVideoMode *tab = sfVideoMode_getFullscreenModes(&count);
    sfVideoMode mode = tab[0];
    sfRenderWindow* window = sfRenderWindow_create(mode, "SFML window",
    sfResize | sfClose, NULL);

    wind(window);
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            dash_h();
            return (0);
        }
        if (prepare_map(av[1]) == NULL)
            return (0);
        launch_game(count, window, prepare_map(av[1]));
    } else {
        return (0);
    }
    return (0);
}

void launch_game(size_t count, sfRenderWindow *window, char** map)
{
    sfClock* clock = sfClock_create();
    struct_t *all = malloc(sizeof(struct_t));
    sfEvent event;

    init_struct(all);
    sfMusic_play(all->stat->music);
    while (sfRenderWindow_isOpen(window)) {
        back_loop(window,  all);
        if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
            while(sfKeyboard_isKeyPressed(sfKeyEnter));
            settings2(window, all, clock, map);
        }
        else
            settings(window, all, event);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
    destroy(all, window);
}

void init_struct(struct_t *all)
{
    all->vec = malloc(sizeof(vector_t));
    all->obj = malloc(sizeof(object_t) * 2);
    all->stat = malloc(sizeof(statement_t));
    all->rect = malloc(sizeof(rect_t));

    object2(all->obj, all->vec);
    vector(all->vec);
    object(all->obj, all->vec);
    statement(all->stat);
    rectangle(all->rect);
}

void destroy(struct_t *all, sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    sfMusic_stop(all->stat->music);
    sfMusic_destroy(all->stat->music);
    sfSound_destroy(all->stat->jump);
    sfSoundBuffer_destroy(all->stat->sb);
    sfSound_destroy(all->stat->p);
    sfSoundBuffer_destroy(all->stat->sb2);
}