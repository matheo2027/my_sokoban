/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** check if map is valid or not
*/

#include <stdlib.h>
#include "../include/libmy.h"
#include "../include/sokoban.h"

void map_check(game_t game)
{
    game.storage_number = 0;
    game.case_number = 0;
    int player = 0;

    for (int i = 0; i < game.lines; i++) {
        for (int j = 0; game.map_save[i][j] != '\0'; j++) {
            game.storage_number += count_storage_zone(i, j, game);
            game.case_number += count_case_number(i, j, game);
            check_tile(i, j, game);
            player += count_player(i, j, game);
        }
    }
    if (game.storage_number == 0 || game.case_number == 0 ||
    game.case_number != game.storage_number || player != 1)
        exit (84);
}

int check_tile(int y, int x, game_t game)
{
    if (game.map_save[y][x] != 'P' && game.map_save[y][x] != 'X'
    && game.map_save[y][x] != '#' && game.map_save[y][x] != ' '
    && game.map_save[y][x] != '\n' && game.map_save[y][x] != 'O')
        exit (84);
    return (0);
}

int count_case_number(int y, int x, game_t game)
{
    int i = 0;

    if (game.map_save[y][x] == 'X') {
        i++;
    }
    return (i);
}

int count_player(int y, int x, game_t game)
{
    int i = 0;

    if (game.map_save[y][x] == 'P') {
        i++;
    }
    return (i);
}
