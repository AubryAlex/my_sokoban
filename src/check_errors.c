/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-alex.aubry
** File description:
** check_errors
*/

#include "sokoban.h"

int check_errors(int argc, char **argv)
{
    if (!argv[1] || argc != 2)
        return 84;
    return 0;
}

int check_errors_map(char **map)
{
    if (!map)
        return 84;
    for (int i = 0; map[i] != NULL; i++) {
        if (str_with_str(map[i], "#POX \n") == 1)
            return 84;
    }
    return 0;
}
