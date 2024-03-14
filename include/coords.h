/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** struct with map dims
*/

#ifndef OBJ_COORDS_H_
    #define OBJ_COORDS_H_

    typedef struct player_coords {
        int x;
        int y;
    }player_coords_t;

    typedef struct goal_map {
        char** O_map;
    }goal_coords_t;

    typedef struct map_state {
        int Px;
        int Py;
        int Xx;
        int Xy;
        int Ox;
        int Oy;
    }map_state_t;
#endif /* OBJ_COORDS_H_ */
