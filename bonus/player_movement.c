/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** player_movement
*/

#include <ncurses.h>
#include "../include/coords.h"
#include "../include/my.h"

void go_up(maps_t *maps, player_coords_t *player)
{
    if (maps->map[player->x - 1][player->y] == 'X') {
        box_up(maps->map, player);
    } else if (maps->map_o[player->x - 1][player->y] == '#')
        maps->map[player->x][player->y] = 'P';
    else {
        maps->map[player->x][player->y] = ' ';
        maps->map[player->x - 1][player->y] = 'P';
    }
    if (maps->map_o[player->x][player->y] == 'O' &&
    maps->map_o[player->x - 1][player->y] != '#' &&
    maps->map[player->x - 1][player->y] != 'X'){
        maps->map[player->x][player->y] = 'O';
        maps->map[player->x - 1][player->y] = 'P';
    }
}

void go_down(maps_t *maps, player_coords_t *player)
{
    if (maps->map[player->x + 1][player->y] == 'X') {
        box_down(maps->map, player);
    } else if (maps->map_o[player->x + 1][player->y] == '#')
        maps->map[player->x][player->y] = 'P';
    else {
        maps->map[player->x][player->y] = ' ';
        maps->map[player->x + 1][player->y] = 'P';
    }
    if (maps->map_o[player->x][player->y] == 'O' &&
    maps->map_o[player->x + 1][player->y] != '#' &&
    maps->map[player->x + 1][player->y] != 'X') {
        maps->map[player->x][player->y] = 'O';
        maps->map[player->x + 1][player->y] = 'P';
    }
}

void go_left(maps_t *maps, player_coords_t *player)
{
    if (maps->map[player->x][player->y - 1] == 'X') {
        box_left(maps->map, player);
    } else if (maps->map_o[player->x][player->y - 1] == '#')
        maps->map[player->x][player->y] = 'P';
    else {
        maps->map[player->x][player->y] = ' ';
        maps->map[player->x][player->y - 1] = 'P';
    }
    if (maps->map_o[player->x][player->y] == 'O' &&
    maps->map_o[player->x][player->y - 1] != '#' &&
    maps->map[player->x][player->y - 1] != 'X') {
        maps->map[player->x][player->y] = 'O';
        maps->map[player->x][player->y - 1] = 'P';
    }
}

void go_right(maps_t *maps, player_coords_t *player)
{
    if (maps->map[player->x][player->y + 1] == 'X') {
        box_right(maps->map, player);
    } else if (maps->map_o[player->x][player->y + 1] == '#')
        maps->map[player->x][player->y] = 'P';
    else {
        maps->map[player->x][player->y] = ' ';
        maps->map[player->x][player->y + 1] = 'P';
    }
    if (maps->map_o[player->x][player->y] == 'O' &&
    maps->map_o[player->x][player->y + 1] != '#' &&
    maps->map[player->x][player->y + 1] != 'X') {
        maps->map[player->x][player->y] = 'O';
        maps->map[player->x][player->y + 1] = 'P';
    }
}
