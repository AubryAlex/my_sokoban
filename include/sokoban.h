/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-alex.aubry
** File description:
** sokoban
*/

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_

    #include <stdio.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <curses.h>

    #define UP 65
    #define DOWN 66
    #define LEFT 68
    #define RIGHT 67
    #define SPACE 32
    #define RESIZE 410

typedef struct target {
    int pos_x;
    int pos_y;
} target_t;

typedef struct player {
    int pos_x;
    int pos_y;
} player_t;

typedef struct game {
    int count_box;
    int count_target;
    int player;
    char prev;
    player_t players;
    target_t **targets;
    char **map;
    char **origin_map;
    char *origin;
    int status;
    int row;
    int col;
} game_t;

int sokoban(char *str);
char **create_array(char *filepath);
int my_strlen(char const *str);
int detect_obj(char **map, game_t *game);
int detect_char(char detect, char **map);
int get_pos_objs(char **map, game_t *game);
int is_sign(char c);
void print_map(game_t *game);
int check_errors(int argc, char **argv);
int get_key(game_t *game, int key);
int move_up(game_t *game);
int move_down(game_t *game);
int move_left(game_t *game);
int move_right(game_t *game);
int check_win(game_t *game);
int check_box(game_t *game, int x, int y);
int check_lose(game_t *game);
int str_with_str(char const *str, char const *str2);
int check_errors_map(char **map);

#endif /* !SOKOBAN_H_ */
