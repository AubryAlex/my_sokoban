/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-alex.aubry
** File description:
** alloc_array
*/

#include "lib.h"

int open_file(char const *filepath)
{
    int filedesc = open(filepath, O_RDONLY);

    return filedesc;
}

char **fillarray(char **array, char *buff, int size)
{
    int x = 0;
    int y = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n') {
            x = 0;
            y++;
        } else {
            array[y][x] = buff[i];
            x++;
        }
    }
    return array;
}

char **alloc_array(int nb_rows, int nb_cols)
{
    char **array = malloc(sizeof(char *) * (nb_rows + 1));

    for (int i = 0; i < nb_rows; i++) {
        array[i] = malloc(sizeof(char) * (nb_cols + 1));
        array[i][nb_cols] = '\0';
    }
    array[nb_rows] = NULL;
    return array;
}

char **create_array(char *filepath)
{
    struct stat st;
    stat(filepath, &st);
    int fd = open_file(filepath);
    int size = st.st_size;
    char *buff = malloc(sizeof(char) * size + 1);
    read(fd, buff, size);
    buff[size] = '\0';
    int column = count_column(buff);
    int line = count_line(buff);
    char **array = alloc_array(line, column);

    fillarray(array, buff, size);
    free(buff);
    return array;
}
