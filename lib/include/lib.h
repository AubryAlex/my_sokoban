/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-alex.aubry
** File description:
** lib
*/

#ifndef LIB_H_
    #define LIB_H_

    #include <stdio.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <curses.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #include <sys/stat.h>

int count_column(char *buff);
int count_line(char *buff);
char **create_array(char *filepath);
int open_file(char const *filepath);
int my_strlen(char const *str);

#endif /* !LIB_H_ */
