/*
** EPITECH PROJECT, 2022
** okoban
** File description:
** manage the game
*/

#include <ncurses.h>
#include "../include/libmy.h"
#include "../include/sokoban.h"

int play(char const *path)
{
    game_t game = make_map(path, game);
    map_check(game);
    game = find_player(game);
    game.base_path = path;

    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    clear();
    refresh();
    while (1) {
        refresh();
        for (int i = 0; i < game.lines; i++)
            mvprintw(i, 0, game.map[i]);
        move(game.player_y, game.player_x);
        game = game_management(game);
    }
}

game_t game_management(game_t game)
{
    int key_pressed = 0;

    key_pressed = getch();
    game = key_check(game, key_pressed);
    game = check_zone_reset(game);
    loose_check(game);
    win_check(game);
    return (game);
}
