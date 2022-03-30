/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-alex.aubry
** File description:
** main
*/

#include "sokoban.h"

int main(int argc, char **argv)
{
    if (check_errors(argc, argv) == 84)
        return 84;
    return sokoban(argv[1]);
}
