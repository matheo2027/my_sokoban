/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** check if loose
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../include/libmy.h"
#include "../include/sokoban.h"

void loose_check(game_t game)
{
    for (int i = 0; i < game.lines; i++) {
        for (int j = 0; game.map_save[i][j] != '\0'; j++) {
            storage_loose_check(i, j, game);
        }
    }
}

void storage_loose_check(int y, int x, game_t game)
{
    if (game.map[y][x] == 'X') {
        if (((game.map[y][x + 1] == '#' && game.map[y + 1][x] == '#') ||
            (game.map[y + 1][x] == '#' && game.map[y][x - 1] == '#') ||
            (game.map[y][x - 1] == '#' && game.map[y - 1][x] == '#') ||
            (game.map[y - 1][x] == '#' && game.map[y][x + 1] == '#')) &&
            game.map_save[y][x] != 'O') {
            endwin();
            exit (1);
        }
    }
}
