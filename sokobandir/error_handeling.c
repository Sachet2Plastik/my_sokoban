/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** error handeling
*/

#include <ncurses.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/coords.h"
#include "../include/my.h"
#include "../include/maps.h"
#include <sys/types.h>

nb_object_t objets;

int map_error2(char **map, int i, int j, int err)
{
    if (err == 84)
        return (84);
    if (map[i][j] != ' ' && map[i][j] != '#' && map[i][j] != 'P'
    && map[i][j] != 'X' && map[i][j] != 'O' && map[i][j] != 10
    && map[i][j] != '\0') {
        return (84);
    } else {
        if (map[i][j] == 'X')
            objets.nb_x += 1;
        if (map[i][j] == 'O')
            objets.nb_o += 1;
        if (map[i][j] == 'P')
            objets.nb_p += 1;
        return (0);
    }
}

int map_error(char **map, map_dims_t *dims, int err)
{
    objets.nb_p = objets.nb_o = objets.nb_x = 0;
    for (int i = 0; i < dims->height; i++)
        for (int j = 0; j < dims->width; j++)
            err = map_error2(map, i, j, err);
    if (objets.nb_o != objets.nb_x)
        err = 84;
    if (objets.nb_p != 1)
        err = 84;
    return (err);
}

int error_handeling(char *file)
{
    int fd;
    fd = open(file, O_RDONLY);
    if (fd == -1) {
        close(fd);
        return (1);
    }
    close(fd);
    return (0);
}

void lose_screen(void)
{
    int key = 0, x = 0, y = 0;
    while (key != 114) {
        clear();
        getmaxyx(stdscr, x, y);
        mvwprintw(stdscr, x / 2, y / 2 - 15,
        "All Boxes Were Stuck, You Lost\n");
        mvwprintw(stdscr, x / 2 + 1, y / 2 - 8,
        "Press 'r' to quit");
        key = getch();
    }
}
