/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/


#ifndef MY_H_
    #define MY_H_
    #include "map_dims.h"
    #include "coords.h"
    #include "maps.h"
    void my_putchar(char c);
    int my_isneg(int nb);
    int my_put_nbr(int nb);
    void my_swap(int *a, int *b);
    int my_putstr(char const *str);
    int my_strlen(char const *str);
    int my_getnbr(char const *str);
    void my_sort_int_array(int *tab, int size);
    int my_compute_power_rec(int nb, int power);
    int my_compute_square_root(int nb);
    int my_is_prime(int nb);
    int my_find_prime_sup(int nb);
    char *my_strcpy(char *dest, char const *src);
    char *my_revstr(char *str);
    char *my_strstr(char *str, char const *to_find);
    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strupcase(char *str);
    char *my_strlowcase(char *str);
    char *my_strcapitalize(char *str);
    int my_str_isalpha(char const *str);
    int my_str_isnum(char const *str);
    int my_str_islower(char const *str);
    int my_str_isupper(char const *str);
    int my_str_isprintable(char const *str);
    int my_showstr(char const *str);
    int my_showmem(char const *str, int size);
    char *my_strcat(char *dest, char const *src);
    char *my_strncat(char *dest, char const *src, int nb);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strdup(char const *src);
    char **my_str_to_word_array(char const *str);
    int my_show_word_array(char * const *tab);
    int my_intlen(int n);
    int mini_printf(const char *format, ...);
    maps_t load_2d_arr_from_file(char const *filepath, int nb_row, int nb_cols);
    map_dims_t get_map_dims(char *map);
    player_coords_t get_p(char **map, map_dims_t *dims);
    void go_up(maps_t *maps, player_coords_t *player);
    void go_down(maps_t *maps, player_coords_t *player);
    void go_left(maps_t *maps, player_coords_t *player);
    void go_right(maps_t *maps, player_coords_t *player);
    int map_error(char **map, map_dims_t *dims, int err);
    int error_handeling(char *file);
    void box_up(char** map, player_coords_t *play);
    void box_down(char** map, player_coords_t *play);
    void box_left(char** map, player_coords_t *play);
    void box_right(char** map, player_coords_t *play);
    int test_args(char *av, int error);
    void print_map(maps_t *maps, map_dims_t dims, int i);
    int win_or_lose(maps_t *maps, map_dims_t *dims);
    void lose_screen(void);

    int bot_move(int win_lose, maps_t *maps, map_dims_t *dims);
    map_state_t get_state_map(maps_t *maps, map_dims_t *dims, map_state_t *state);
    int push_box_to_stox(map_state_t state);
    int move_box_to_O(map_state_t state);
    int move_play_to_box(map_state_t state);

#endif /* MY_H_ */
