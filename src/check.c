/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-alex.aubry
** File description:
** check
*/

#include "sokoban.h"

int check_lose(game_t *game)
{
    int lost = 0;

    if (!game)
        return 84;
    for (int x = 0; game->map[x] != NULL; x++) {
        for (int y = 0; game->map[x][y] != '\0'; y++) {
            (game->map[x][y] == 'X') ? (lost += check_box(game, x, y)) :
            (lost = lost);
        }
    }
    if (lost == game->count_box)
        game->status = 1;
    return 0;
}

int check_box(game_t *game, int x, int y)
{
    if (!game)
        return 84;
    if (game->map[x - 1][y] == '#' && game->map[x][y + 1] == '#')
        return 1;
    if (game->map[x + 1][y] == '#' && game->map[x][y + 1] == '#')
        return 1;
    if (game->map[x + 1][y] == '#' && game->map[x][y - 1] == '#')
        return 1;
    if (game->map[x - 1][y] == '#' && game->map[x][y - 1] == '#')
        return 1;
    return 0;
}

int check_win(game_t *game)
{
    int target = 0;

    check_lose(game);
    if (!game)
        return 84;
    for (int x = 0; game->map[x] != NULL; x++) {
        for (int y = 0; game->map[x][y] != '\0'; y++) {
            (game->map[x][y] == 'O') ? (target++) : (target = target);
        }
    }
    if (target == 0 && game->prev != 'O')
        game->status = 0;
    return 0;
}
