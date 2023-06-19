/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** moov box
*/

#include "../include/libmy.h"
#include "../include/sokoban.h"

game_t move_box_left(game_t game)
{
    if (game.map[game.player_y][game.player_x - 2] == 'X') {
        return (game);
    } else if (game.map[game.player_y][game.player_x - 2] == '#') {
        return (game);
    } else {
        game.map[game.player_y][game.player_x - 1] = 'P';
        game.map[game.player_y][game.player_x - 2] = 'X';
        game.map[game.player_y][game.player_x] = ' ';
        game.player_x--;
    }
    return (game);
}

game_t move_box_right(game_t game)
{
    if (game.map[game.player_y][game.player_x + 2] == 'X') {
        return (game);
    } else if (game.map[game.player_y][game.player_x + 2] == '#') {
        return (game);
    } else {
        game.map[game.player_y][game.player_x + 1] = 'P';
        game.map[game.player_y][game.player_x + 2] = 'X';
        game.map[game.player_y][game.player_x] = ' ';
        game.player_x++;
    }
    return (game);
}

game_t move_box_up(game_t game)
{
    if (game.map[game.player_y - 2][game.player_x] == 'X') {
        return (game);
    } else if (game.map[game.player_y - 2][game.player_x] == '#') {
        return (game);
    } else {
        game.map[game.player_y - 1][game.player_x] = 'P';
        game.map[game.player_y - 2][game.player_x] = 'X';
        game.map[game.player_y][game.player_x] = ' ';
        game.player_y--;
    }
    return (game);
}

game_t move_box_down(game_t game)
{
    if (game.map[game.player_y + 2][game.player_x] == 'X') {
        return (game);
    } else if (game.map[game.player_y + 2][game.player_x] == '#') {
        return (game);
    } else {
        game.map[game.player_y + 1][game.player_x] = 'P';
        game.map[game.player_y + 2][game.player_x] = 'X';
        game.map[game.player_y][game.player_x] = ' ';
        game.player_y++;
    }
    return (game);
}
