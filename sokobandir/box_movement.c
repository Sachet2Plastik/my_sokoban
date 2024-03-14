/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** box_movement
*/

#include "../include/coords.h"

void box_up(char** map, player_coords_t *play)
{
    if (map[play->x - 2][play->y] == '#' || map[play->x - 2][play->y] == 'X') {
        map[play->x - 1][play->y] = 'X';
        map[play->x][play->y] = 'P';
    } else {
        map[play->x][play->y] = ' ';
        map[play->x - 1][play->y] = 'P';
        map[play->x - 2][play->y] = 'X';
    }
}

void box_down(char** map, player_coords_t *play)
{
    if (map[play->x + 2][play->y] == '#' || map[play->x + 2][play->y] == 'X') {
        map[play->x + 1][play->y] = 'X';
        map[play->x][play->y] = 'P';
    } else {
        map[play->x][play->y] = ' ';
        map[play->x + 1][play->y] = 'P';
        map[play->x + 2][play->y] = 'X';
    }
}

void box_left(char** map, player_coords_t *play)
{
    if (map[play->x][play->y - 2] == '#' || map[play->x][play->y - 2] == 'X') {
        map[play->x][play->y - 1] = 'X';
        map[play->x][play->y] = 'P';
    } else {
        map[play->x][play->y] = ' ';
        map[play->x][play->y - 1] = 'P';
        map[play->x][play->y - 2] = 'X';
    }
}

void box_right(char** map, player_coords_t *play)
{
    if (map[play->x][play->y + 2] == '#' || map[play->x][play->y + 2] == 'X') {
        map[play->x][play->y + 1] = 'X';
        map[play->x][play->y] = 'P';
    } else {
        map[play->x][play->y] = ' ';
        map[play->x][play->y + 1] = 'P';
        map[play->x][play->y + 2] = 'X';
    }
}
