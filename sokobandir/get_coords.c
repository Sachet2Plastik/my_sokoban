/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** get coords of P,X and O
*/

#include "../include/coords.h"
#include "../include/my.h"
#include <stdio.h>

player_coords_t get_p2(char **map, player_coords_t *player, int i, int j)
{
    if (map[i][j] == 'P') {
        player->x = i;
        player->y = j;
    }
}

player_coords_t get_p(char **map, map_dims_t *dims)
{
    player_coords_t player;

    for (int i = 0; i < dims->height; i++)
        for (int j = 0; j < dims->width; j++)
            get_p2(map, &player, i, j);
    return (player);
}
