/*
** EPITECH PROJECT, 2022
** bs BSQ
** File description:
** load 2d arr from file
*/

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include "../include/maps.h"
#include "../include/map_dims.h"
#include "../include/my.h"

maps_t buff_to_map(char *buff, maps_t *maps)
{
    int i = 0, x = 0;

    for (int j = 0; buff[i] != '\0'; i++) {
        x = 0;
        while (buff[i] != '\n') {
            maps->map[j][x] = buff[i];
            maps->map_o[j][x] = buff[i];
            i++;
            x++;
        }
        maps->map[j][x] = '\0';
        maps->map_o[j][x] = '\0';
        j++;
    }
}

maps_t load_2d_arr_from_file(char const *filepath, int nb_row, int nb_cols)
{
    int fd;
    char *buff;
    struct stat buffs;
    maps_t maps;
    fd = open(filepath, O_RDONLY);
    stat(filepath, &buffs);
    buff = malloc(buffs.st_size + 1);
    read(fd, buff, buffs.st_size);
    buff[buffs.st_size] = '\0';
    maps.map = malloc(nb_row * sizeof(char *));
    maps.map_o = malloc(nb_row * sizeof(char *));
    for (int i = 0; i < nb_row; i++) {
        maps.map[i] = malloc(nb_cols + 1);
        maps.map_o[i] = malloc(nb_cols + 1);
    }
    buff_to_map(buff, &maps);
    free(buff);
    close(fd);
    return (maps);
}
