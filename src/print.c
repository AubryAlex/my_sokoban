/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-alex.aubry
** File description:
** print
*/

#include "sokoban.h"

int count_cols(char **map)
{
    int count = 0;

    if (!map)
        return -84;
    count = my_strlen(map[0]);
    return count;
}

int count_rows(char **map)
{
    int count = 0;

    if (!map)
        return -84;
    for (; map[count] != NULL; count++);
    return count;
}

static void set_target(game_t *game, int i)
{
    if (!game || i < 0)
        return;
    for (int j = 0; game->map[i][j] != '\0'; j++) {
        if (game->map[i][j] == 'P' && game->origin_map[i][j] == 'O')
                game->prev = 'O';
    }
    return;
}

void print_map(game_t *game)
{
    char *str = "Terminal too small";

    if (!game)
        return;
    curs_set(0);
    noecho();
    getmaxyx(stdscr, game->row, game->col);
    if (count_rows(game->map) <= game->row &&
    count_cols(game->map) <= game->col) {
        for (int i = 0; game->map[i] != NULL; i++) {
            set_target(game, i);
            mvprintw((game->row + i * 2) / 2 - count_rows(game->map) / 2,
            game->col / 2 - my_strlen(game->map [i]) / 2, "%s", game->map[i]);
        }
    } else {
        wclear(stdscr);
        mvprintw(game->row / 2, game->col / 2 - my_strlen(str) / 2, "%s", str);
    }
    return;
}
