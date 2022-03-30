/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-alex.aubry
** File description:
** str_with_str
*/

#include <stddef.h>
#include <stdio.h>
int my_strlen(char const *str);

static int in_str(char c, char const *str)
{
    if (str == NULL)
        return 84;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return 0;
    }
    return 1;
}

int str_with_str(char const *str, char const *str2)
{
    int count = 0;

    if (str == NULL || str2 == NULL)
        return 84;
    for (int i = 0; str[i] != '\0'; i++) {
        if (in_str(str[i], str2) == 0)
            count += 1;
    }
    if (count == my_strlen(str))
        return 0;
    return 1;
}
