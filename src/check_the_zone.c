/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** Check zone
*/

#include "../include/libmy.h"
#include "../include/sokoban.h"

game_t check_zone_reset(game_t game)
{
    for (int i = 0; i < game.lines; i++) {
        for (int j = 0; game.map_save[i][j] != '\0'; j++) {
            game = reset_zone(i, j, game);
        }
    }
    return (game);
}

game_t reset_zone(int y, int x, game_t game)
{
    if (game.map_save[y][x] == 'O' && game.map[y][x] == ' ') {
        game.map[y][x] = game.map_save[y][x];
        return (game);
    }
    return (game);
}
