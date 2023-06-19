/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** find player on map
*/

#include "../include/libmy.h"
#include "../include/sokoban.h"

game_t find_player(game_t game)
{
    game.player_x = 0;
    game.player_y = 0;
    for (int i = 0; i < game.lines; i++) {
        for (int j = 0; game.map[i][j] != '\0'; j++) {
            game = check_if_player(game, i, j);
        }
    }
    return (game);
}

game_t check_if_player(game_t game, int y, int x)
{
    if (game.map[y][x] == 'P') {
        game.player_x = x;
        game.player_y = y;
    }
    return (game);
}
