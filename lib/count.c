/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-alex.aubry
** File description:
** count
*/

#include "lib.h"

int count_column(char *buff)
{
    int column = 0;
    struct stat st;

    if (!buff)
        return 84;
    for (int i = 0; buff[i] != '\n'; i++)
        column += 1;
    return column;
}

int count_line(char *buff)
{
    int line = 0;
    struct stat st;

    if (!buff)
        return 84;
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n')
            line += 1;
    }
    return line;
}
