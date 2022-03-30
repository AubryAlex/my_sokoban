/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-alex.aubry
** File description:
** get_key
*/

#include "sokoban.h"

int handle_space(game_t *game)
{
    if (!game)
        return 84;
    game->map = create_array(game->origin);
    get_pos_objs(game->map, game);
    wclear(stdscr);
    return 0;
}

int handle_movement(game_t *game, int key)
{
    if (!game || key == -1)
        return 84;
    if (key == UP &&
    game->map[game->players.pos_x - 1][game->players.pos_y] != '#')
        move_up(game);
    if (key == DOWN &&
    game->map[game->players.pos_x + 1][game->players.pos_y] != '#')
        move_down(game);
    if (key == RIGHT &&
    game->map[game->players.pos_x][game->players.pos_y + 1] != '#')
        move_right(game);
    if (key == LEFT &&
    game->map[game->players.pos_x][game->players.pos_y - 1] != '#')
        move_left(game);
    return 0;
}

int get_key(game_t *game, int key)
{
    if (key == -1 || !game)
        return 84;
    handle_movement(game, key);
    if (key == SPACE)
        handle_space(game);
    if (key == RESIZE) {
        wclear(stdscr);
        getmaxyx(stdscr, game->row, game->col);
    }
    // check_win(game);
    return 0;
}
