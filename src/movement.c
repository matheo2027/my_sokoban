/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** player move
*/

#include "../include/libmy.h"
#include "../include/sokoban.h"

game_t move_left(game_t game)
{
    if (game.map[game.player_y][game.player_x - 1] != '#') {
        if (game.map[game.player_y][game.player_x - 1] == 'X') {
            game = move_box_left(game);
        } else {
            game.map[game.player_y][game.player_x - 1] = 'P';
            game.map[game.player_y][game.player_x] = ' ';
            game.player_x--;
        }
    }
    return (game);
}

game_t move_right(game_t game)
{
    if (game.map[game.player_y][game.player_x + 1] != '#') {
        if (game.map[game.player_y][game.player_x + 1] == 'X') {
            game = move_box_right(game);
        } else {
            game.map[game.player_y][game.player_x + 1] = 'P';
            game.map[game.player_y][game.player_x] = ' ';
            game.player_x++;
        }
    }
    return (game);
}

game_t move_up(game_t game)
{
    if (game.map[game.player_y - 1][game.player_x] != '#') {
        if (game.map[game.player_y - 1][game.player_x] == 'X') {
            game = move_box_up(game);
        } else {
            game.map[game.player_y - 1][game.player_x] = 'P';
            game.map[game.player_y][game.player_x] = ' ';
            game.player_y--;
        }
    }
    return (game);
}

game_t move_down(game_t game)
{
    if (game.map[game.player_y + 1][game.player_x] != '#') {
        if (game.map[game.player_y + 1][game.player_x] == 'X') {
            game = move_box_down(game);
        } else {
            game.map[game.player_y + 1][game.player_x] = 'P';
            game.map[game.player_y][game.player_x] = ' ';
            game.player_y++;
        }
    }
    return (game);
}
