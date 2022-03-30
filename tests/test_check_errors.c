/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-alex.aubry
** File description:
** test_check_errors
*/

#include "test.h"

Test(check_errors, normal)
{
    char *argv[] = {"Hello", "World", NULL};

    cr_assert_eq(check_errors(2, argv), 0);
}

Test(check_errors, zero_argc)
{
    char *argv[] = {"Hello", "World", NULL};

    cr_assert_eq(check_errors(0, argv), 84);
}

Test(check_errors, argv_NULL)
{
    char **argv = NULL;

    cr_assert_eq(check_errors(3, argv), 84);
}

Test(check_errors_map, normal)
{
    char *map[] = {"#####",
                 "# P #",
                 "# X #",
                 "# O #",
                 "#####",
                 NULL};

    cr_assert_eq(check_errors_map(map), 0);
}

Test(check_errors_map, normal)
{
    char *map[] = {"#####",
                 "# P #",
                 "# X #",
                 "# O #",
                 "#####",
                 NULL};

    cr_assert_eq(check_errors_map(map), 0);
}

Test(check_errors_map, invalid_map)
{
    char *map[] = {"#####",
                 "# P #",
                 "# X #",
                 "# ! #",
                 "#####",
                 NULL};

    cr_assert_eq(check_errors_map(map), 84);
}

Test(check_errors_map, map_NULL)
{
    char **map = NULL;

    cr_assert_eq(check_errors_map(map), 84);
}
