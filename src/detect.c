/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-alex.aubry
** File description:
** detect
*/

#include "sokoban.h"

int detect_char(char detect, char **map)
{
    int count = 0;

    if ((detect != 'X' && detect != 'O' && detect != 'P') || !map)
        return -84;
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            (map[i][j] == detect) ? (count++) : (count = count);
        }
    }
    return count;
}

int detect_obj(char **map, game_t *game)
{
    if (!map)
        return 84;
    game->count_box = detect_char('X', map);
    game->count_target = detect_char('O', map);
    game->player = detect_char('P', map);
    if (game->count_box < game->count_target) {
        write(2, "There are not enough boxes", 26);
        return 84;
    }
    if (game->count_target == -84 || game->count_box == -84 ||
    game->player != 1)
        return 84;
    return 0;
}
