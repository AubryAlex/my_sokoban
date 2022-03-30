/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-alex.aubry
** File description:
** popup
*/

#include "sokoban.h"

int sokoban(char *str)
{
    game_t *game = malloc(sizeof(game_t));

    game->status = -1;
    if (!str)
        return 84;
    game->origin = str;
    game->map = create_array(str);
    game->origin_map = create_array(game->origin);
    if (!game->map || detect_obj(game->map, game) == 84 ||
    check_errors_map(game->map) == 84)
        return 84;
    get_pos_objs(game->map, game);
    initscr();
    print_map(game);
    while (game->status == -1) {
        print_map(game);
        get_key(game, getch());
        check_win(game);
    }
    usleep(3);
    endwin();
    return game->status;
}
