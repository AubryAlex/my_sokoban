/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-alex.aubry
** File description:
** move
*/

#include "sokoban.h"

int move_up(game_t *game)
{
    if (!game)
        return 84;
    if (game->map[game->players.pos_x - 1][game->players.pos_y] == 'X' &&
    (game->map[game->players.pos_x - 2][game->players.pos_y] == 'X' ||
    game->map[game->players.pos_x - 2][game->players.pos_y] == '#'))
        return 0;
    game->map[game->players.pos_x][game->players.pos_y] = game->prev;
    game->prev = game->map[game->players.pos_x - 1][game->players.pos_y];
    game->map[game->players.pos_x - 1][game->players.pos_y] = 'P';
    game->players.pos_x = game->players.pos_x - 1;
    if (game->prev == 'X') {
        game->map[game->players.pos_x - 1][game->players.pos_y] = game->prev;
        game->prev = ' ';
    }
    return 0;
}

int move_down(game_t *game)
{
    if (!game)
        return 84;
    if (game->map[game->players.pos_x + 1][game->players.pos_y] == 'X' &&
    (game->map[game->players.pos_x + 2][game->players.pos_y] == 'X' ||
    game->map[game->players.pos_x + 2][game->players.pos_y] == '#'))
        return 0;
    game->map[game->players.pos_x][game->players.pos_y] = game->prev;
    game->prev = game->map[game->players.pos_x + 1][game->players.pos_y];
    game->map[game->players.pos_x + 1][game->players.pos_y] = 'P';
    game->players.pos_x = game->players.pos_x + 1;
    if (game->prev == 'X') {
        game->map[game->players.pos_x + 1][game->players.pos_y] = game->prev;
        game->prev = ' ';
    }
    return 0;
}

int move_left(game_t *game)
{
    if (!game)
        return 84;
    if (game->map[game->players.pos_x][game->players.pos_y - 1] == 'X' &&
    (game->map[game->players.pos_x][game->players.pos_y - 2] == 'X' ||
    game->map[game->players.pos_x][game->players.pos_y - 2] == '#'))
        return 0;
    game->map[game->players.pos_x][game->players.pos_y] = game->prev;
    game->prev = game->map[game->players.pos_x][game->players.pos_y - 1];
    game->map[game->players.pos_x][game->players.pos_y - 1] = 'P';
    game->players.pos_y = game->players.pos_y - 1;
    if (game->prev == 'X') {
        game->map[game->players.pos_x][game->players.pos_y - 1] = game->prev;
        game->prev = ' ';
    }
    return 0;
}

int move_right(game_t *game)
{
    if (!game)
        return 84;
    if (game->map[game->players.pos_x][game->players.pos_y + 1] == 'X' &&
    (game->map[game->players.pos_x][game->players.pos_y + 2] == 'X' ||
    game->map[game->players.pos_x][game->players.pos_y + 2] == '#'))
        return 0;
    game->map[game->players.pos_x][game->players.pos_y] = game->prev;
    game->prev = game->map[game->players.pos_x][game->players.pos_y + 1];
    game->map[game->players.pos_x][game->players.pos_y + 1] = 'P';
    game->players.pos_y = game->players.pos_y + 1;
    if (game->prev == 'X') {
        game->map[game->players.pos_x][game->players.pos_y + 1] = game->prev;
        game->prev = ' ';
    }
    return 0;
}
