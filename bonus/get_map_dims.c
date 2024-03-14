/*
** EPITECH PROJECT, 2022
** Algorithms IV
** File description:
** get map dims
*/

#include "../include/map_dims.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

map_dims_t get_map_dims2(char* buff)
{
    map_dims_t mapDims;
    int rows = 0;
    int cols = 0;
    int final_cols = 0;
    int s = 0;

    for (int i = s; buff[i] != '\0'; i++) {
        cols += 1;
        if (cols > final_cols)
            final_cols = cols;
        if (buff[i] == '\n') {
            rows += 1;
            cols = 0;
        }
    }
    mapDims.width = final_cols - 1;
    mapDims.height = rows;
    return (mapDims);

}

map_dims_t get_map_dims(char *map)
{
    int fd;
    char *buff;
    struct stat buffs;
    map_dims_t mapDims;

    fd = open(map, O_RDONLY);
    stat(map, &buffs);
    buff = malloc(buffs.st_size + 1);
    read(fd, buff, buffs.st_size);
    buff[buffs.st_size] = '\0';
    mapDims = get_map_dims2(buff);
    close(fd);
    free(buff);
    return (mapDims);
}
