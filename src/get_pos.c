/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-alex.aubry
** File description:
** get_pos
*/

#include "sokoban.h"

int is_sign(char c)
{
    if (c == 'X')
        return 2;
    if (c == 'O')
        return 0;
    if (c == 'P')
        return 1;
    return 3;
}

static int set_player_pos(game_t *game, int x, int y)
{
    if (!game || x < 0 || y < 0)
        return 84;
    game->players.pos_x = x;
    game->players.pos_y = y;
    return 0;
}

int player_pos(game_t *game)
{
    int player = 0;

    if (!game)
        return 84;
    for (int x = 0; game->map[x] != NULL; x++) {
        for (int y = 0; game->map[x][y] != '\0'; y++) {
            (game->map[x][y] == 'P') ? (player = set_player_pos(game, x, y)) :
            (player = player);
        }
    }
    if (game->players.pos_x)
        return 0;
    return 84;
}

target_t *set_pos(char sign, int x, int y, target_t *targets)
{
    if (!targets || x < 0 || y < 0)
        return NULL;
    if (is_sign(sign) == 0) {
        targets->pos_x = x;
        targets->pos_y = y;
    }
    return targets;
}

int get_pos_objs(char **map, game_t *game)
{
    int count = 0;

    if (!map && !game)
        return 84;
    if (player_pos(game) == 84)
        return 84;
    game->prev = ' ';
    game->targets = malloc(sizeof(target_t *) * (game->count_target + 1));
    for (int i = 0; i < game->count_target; i++)
        game->targets[i] = malloc(sizeof(target_t));
    game->targets[game->count_target] = NULL;
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            game->targets[count] = set_pos(map[i][j], i, j,
            game->targets[count]);
            (map[i][j] == 'O') ? (count++) : (count = count);
        }
    }
    return 0;
}
