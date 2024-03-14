/*
** EPITECH PROJECT, 2022
** my_sokoban_bonus
** File description:
** BOT_mouvements
*/

#include <ncurses.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/coords.h"
#include "../include/my.h"
#include "../include/maps.h"
#include <sys/types.h>

int bot_move(int win_lose, maps_t *maps, map_dims_t *dims)
{
    map_state_t state;
    get_state_map(maps, dims, &state);
    int playtbox = abs(state.Px - state.Xx) + abs(state.Py - state.Xy);
    int boxtstox = abs(state.Xx - state.Ox) + abs(state.Xy - state.Oy);
    int playtstox = abs(state.Px - state.Ox) + abs(state.Py - state.Oy);

    if (playtbox == 1 && boxtstox > 1)
        return (push_box_to_stox(state));
    else if (boxtstox == 1)
        return (move_box_to_O(state));
    else if (playtbox > 1 && boxtstox > 1)
        return (move_play_to_box(state));
    else
        return (114);
}
