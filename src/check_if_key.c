/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** Function manage key press
*/

#include <ncurses.h>
#include "../include/libmy.h"
#include "../include/sokoban.h"

game_t key_check(game_t game, int key)
{
    if (key == KEY_LEFT) {
        game = move_left(game);
    }
    if (key == KEY_RIGHT) {
        game = move_right(game);
    }
    if (key == KEY_UP) {
        game = move_up(game);
    }
    if (key == KEY_DOWN) {
        game = move_down(game);
    }
    if (key == ' ') {
        play(game.base_path);
    }
    return (game);
}
