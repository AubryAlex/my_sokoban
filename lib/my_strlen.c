/*
** EPITECH PROJECT, 2021
** my strlen
** File description:
** counts and returns the nb of characters found in string
*/

int my_strlen(char const *str)
{
    int i = 0;
    int t = 0;

    while (str[i] != '\0') {
        t = t + 1;
        i = i + 1;
    }
    return (t);
}
