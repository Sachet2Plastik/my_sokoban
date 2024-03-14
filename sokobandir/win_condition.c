/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** print_map
*/

#include <ncurses.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/coords.h"
#include "../include/my.h"
#include "../include/maps.h"
#include <sys/types.h>

nb_object_t count_objects2(nb_object_t *objects, maps_t *maps)
{
    if (maps->map_o[objects->i][objects->j] == 'X')
        objects->nb_x += 1;
    if (maps->map_o[objects->i][objects->j] == 'O')
        objects->nb_o += 1;
}

nb_object_t count_objects(nb_object_t *objects, maps_t *maps, map_dims_t *dims)
{
    for (objects->i = 0; objects->i < dims->height; objects->i++)
        for (objects->j = 0; objects->j < dims->width; objects->j++)
            count_objects2(objects, maps);
}

int check_locked(maps_t *m, nb_object_t *obj)
{
    int maybe_lock = 0;
    if ((m->map[obj->i + 1][obj->j] == '#' || m->map[obj->i + 1][obj->j] == 'X')
    && (m->map[obj->i][obj->j - 1] == '#' || m->map[obj->i][obj->j - 1] == 'X'))
        maybe_lock += 1;
    if ((m->map[obj->i + 1][obj->j] == '#' || m->map[obj->i + 1][obj->j] == 'X')
    && (m->map[obj->i][obj->j + 1] == '#' || m->map[obj->i][obj->j + 1] == 'X'))
        maybe_lock += 1;
    if ((m->map[obj->i - 1][obj->j] == '#' || m->map[obj->i - 1][obj->j] == 'X')
    && (m->map[obj->i][obj->j - 1] == '#' || m->map[obj->i][obj->j - 1] == 'X'))
        maybe_lock += 1;
    if ((m->map[obj->i - 1][obj->j] == '#' || m->map[obj->i - 1][obj->j] == 'X')
    && (m->map[obj->i][obj->j + 1] == '#' || m->map[obj->i][obj->j + 1] == 'X'))
        maybe_lock += 1;
    if (maybe_lock >= 1)
        return (1);
    else
        return (0);
}

nb_object_t win_or_lose2(maps_t *maps, map_dims_t *dims, nb_object_t *objects)
{
    int is_locked = 0;
    if (maps->map[objects->i][objects->j] == 'X' &&
    maps->map_o[objects->i][objects->j] == 'O')
        objects->stored_box += 1;
    if (maps->map[objects->i][objects->j] == 'X') {
        is_locked = check_locked(maps, objects);
        if (is_locked == 1)
            objects->locked_box += 1;
    }
}

int win_or_lose(maps_t *maps, map_dims_t *dims)
{
    int win_lose = 3;
    nb_object_t objects;

    objects.nb_o = objects.nb_x = objects.stored_box = objects.locked_box = 0;
    count_objects(&objects, maps, dims);
    for (objects.i = 0; objects.i < dims->height; objects.i++)
        for (objects.j = 0; objects.j < dims->width; objects.j++)
            win_or_lose2(maps, dims, &objects);
    if (objects.nb_x == objects.stored_box)
        return (0);
    if (objects.nb_x == objects.locked_box)
        return (1);
    return (win_lose);
}
