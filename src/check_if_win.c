/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** check if win
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../include/libmy.h"
#include "../include/sokoban.h"

void win_check(game_t game)
{
    int storage_number = 0;
    int storage_won = 0;

    for (int i = 0; i < game.lines; i++) {
        for (int j = 0; game.map_save[i][j] != '\0'; j++) {
            storage_number += count_storage_zone(i, j, game);
        }
    }
    for (int i = 0; i < game.lines; i++) {
        for (int j = 0; game.map_save[i][j] != '\0'; j++) {
            storage_won += count_storage_won(i, j, game);
        }
    }
    if (storage_won == storage_number) {
        endwin();
        exit (0);
    }
}

int count_storage_zone(int y, int x, game_t game)
{
    int i = 0;

    if (game.map_save[y][x] == 'O') {
        i++;
    }
    return (i);
}

int count_storage_won(int y, int x, game_t game)
{
    int i = 0;

    if (game.map_save[y][x] == 'O' && game.map[y][x] == 'X') {
        i++;
    }
    return (i);
}
