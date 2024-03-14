/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** struct with map and copies
*/

#ifndef MAPS_H_
    #define MAPS_H_

    typedef struct maps {
        char** map;
        char** map_o;
    }maps_t;

    typedef struct nb_object {
        int nb_p;
        int nb_x;
        int nb_o;
        int locked_box;
        int stored_box;
        int i;
        int j;
    }nb_object_t;

#endif /*MAPS_H_*/
