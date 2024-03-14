/*
** EPITECH PROJECT, 2022
** bs_sokoban
** File description:
** my_popup
*/

#include <ncurses.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/coords.h"
#include "../include/my.h"
#include "../include/maps.h"
#include <sys/types.h>

char **player_move(int key, maps_t *maps, map_dims_t *dims)
{
    player_coords_t player;
    player = get_p(maps->map, dims);
    switch (key) {
        case KEY_UP:
            go_up(maps, &player);
            break;
        case KEY_DOWN:
            go_down(maps, &player);
            break;
        case KEY_LEFT:
            go_left(maps, &player);
            break;
        case KEY_RIGHT:
            go_right(maps, &player);
            break;
    }
}

int game_loop(maps_t *maps, map_dims_t *dims, char* av)
{
    int key = 0, i = 0, row, col, win_lose = 3;
    while (key != 114) {
        clear();
        player_move(key, maps, dims);
        for (i = 0; i < dims->height; i++)
            printw("%s\n", maps->map[i]);
        refresh();
        win_lose = win_or_lose(maps, dims);
        if (win_lose == 0 || win_lose == 1)
            return (win_lose);
        if (key == 32)
            return (2);
        key = getch();
    }
    return (0);
}

void print_usage(void)
{
    mini_printf("      <!> SOKOBAN <!>      ");
    mini_printf("\n\nUSAGE\n     ./my_sokoban map");
    mini_printf("\n\nThe Game is Very Simple:\n\n");
    mini_printf("     DESCRIPTION\n");
    mini_printf("map file representing the warehouse map\n\
containing '#' for walls,");
    mini_printf(" 'P' for the player, 'X' for boxes and 'O'\
for storage locations.\n\n");
    mini_printf("Your Goal Is To Push All The Box On The Storage Locations\n");
    mini_printf("Use Arrow Key To Move Around.\n");
    mini_printf("\nHave Fun Trying To Solve All Puzzle You Can !\n");
}

int test_args(char *av, int error)
{
    map_dims_t dims;
    maps_t maps;
    if (av[0] == '-' && av[1] == 'h') {
        print_usage();
        return (0);
    } else {
        error = error_handeling(av);
        if (error == 1)
            return (84);
        dims = get_map_dims(av);
        maps = load_2d_arr_from_file(av, dims.height, dims.width);
        error = map_error(maps.map, &dims, error);
        if (error == 84)
            return (84);
        error = game_loop(&maps, &dims, av);
        return (error);
    }
}

int main(int ac, char **av)
{
    int error = 0, key = 0, x = 0, y = 0;
    if (ac > 2 || ac == 1)
        return (84);
    if (ac == 2){
        initscr();
        keypad(stdscr, TRUE);
        noecho();
        error = test_args(av[1], error);
    }
    while (error == 2)
        error = test_args(av[1], error);
    endwin();
    return (error);
}
