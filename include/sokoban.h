/*
** EPITECH PROJECT, 20122
** sokoban.h
** File description:
** sokoban
*/

#ifndef SOKOBAN_H
    #define SOKOBAN_H
    typedef struct game {
        char *buffer;
        char **map;
        char **map_save;
        int lines;
        int player_x;
        int player_y;
        char const *base_path;
        int win;
        int storage_number;
        int storage_won;
        int case_number;
    } game_t;

    int helper(void);
    char *read_map(int reading);
    char *open_map(char const *path);
    game_t make_map(char const *path, game_t game);
    int play(char const *path);
    game_t count_lines(game_t game);
    int count_columns(game_t game, int position);
    game_t check_if_player(game_t game, int y, int x);
    game_t find_player(game_t game);
    game_t key_check(game_t game, int key);
    game_t move_right(game_t game);
    game_t move_left(game_t game);
    game_t move_up(game_t game);
    game_t move_down(game_t game);
    game_t move_box_left(game_t game);
    game_t move_box_right(game_t game);
    game_t move_box_up(game_t game);
    game_t move_box_down(game_t game);
    void win_check(game_t game);
    int count_storage_zone(int y, int x, game_t game);
    int count_storage_won(int y, int x, game_t game);
    game_t check_zone_reset(game_t game);
    game_t reset_zone(int y, int x, game_t game);
    void loose_check(game_t game);
    void storage_loose_check(int y, int x, game_t game);
    void map_check(game_t game);
    int count_case_number(int y, int x, game_t game);
    int count_player(int y, int x, game_t game);
    game_t game_management(game_t game);
    int check_tile(int y, int x, game_t game);

#endif
