/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** Main
*/

#include "../include/libmy.h"
#include "../include/sokoban.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (84);
    if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0')
        return (helper());
    else if (argv[1][0] != '-')
        play(argv[1]);
    return (84);
}
