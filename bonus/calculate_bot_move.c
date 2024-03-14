/*
** EPITECH PROJECT, 2022
** my_sokoban_bonus
** File description:
** BOT_mouvements_V.2.0
*/

#include <ncurses.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/coords.h"
#include "../include/my.h"
#include "../include/maps.h"
#include <sys/types.h>

int push_box_to_stox(map_state_t state)
{
    if (state.Xx < state.Ox)
        return (KEY_RIGHT);
    if (state.Xx > state.Ox)
        return (KEY_LEFT);
    if (state.Xy < state.Oy)
        return (KEY_DOWN);
    if (state.Xy > state.Oy)
        return (KEY_UP);
}

int move_box_to_O(map_state_t state)
{
    if (state.Px < state.Xx)
        return (KEY_RIGHT);
    if (state.Px > state.Xx)
        return (KEY_LEFT);
    if (state.Py < state.Xy)
        return (KEY_DOWN);
    if (state.Py > state.Xy)
        return (KEY_UP);
}

int move_play_to_box(map_state_t state)
{
    if (state.Px < state.Xx)
        return (KEY_RIGHT);
    if (state.Px > state.Xx)
        return (KEY_LEFT);
    if (state.Py < state.Xy)
        return (KEY_DOWN);
    if (state.Py > state.Xy)
        return (KEY_UP);
}