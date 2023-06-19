/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** map
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/libmy.h"
#include "../include/sokoban.h"

char *open_map(char const *path)
{
    int reading;
    char *buffer;

    reading = open(path, O_RDONLY);
    if (reading == -1) {
        write(2, "No such file or directory\n", 26);
        exit (84);
    }
    buffer = read_map(reading);
    close(reading);
    return (buffer);
}

char *read_map(int reading)
{
    char *buffer = malloc(sizeof(char) * 10000);
    int size = 32;

    size = read(reading, buffer, 10000);
    if (size == -1)
        exit(84);
    return (buffer);
}

int count_columns(game_t game, int position)
{
    int columns = 0;

    for (; game.buffer[position] != '\n'; position++) {
        columns++;
    }
    return (columns);
}

game_t count_lines(game_t game)
{
    game.lines = 0;

    for (int i = 0; game.buffer[i] != '\0'; i++) {
        if (game.buffer[i] == '\n' || game.buffer[i] == '\0')
            game.lines++;
    }
    return (game);
}

game_t make_map(char const *path, game_t game)
{
    game.buffer = open_map(path);
    game = count_lines(game);
    int k = 0;
    int columns = 0;
    game.map = malloc(sizeof (char *) * game.lines);
    game.map_save = malloc(sizeof (char *) * game.lines);
    for (int j = 0; j < game.lines; j++) {
        columns = count_columns(game, k);
        game.map[j] = malloc(sizeof(char) * columns + 1);
        game.map_save[j] = malloc(sizeof(char) * columns + 1);
        for (int i = 0; i < columns; i++) {
            game.map[j][i] = game.buffer[k];
            game.map_save[j][i] = game.buffer[k];
            game.map[j][i + 1] = '\0';
            game.map_save[j][i + 1] = '\0';
            k++;
        }
        k++;
    }
    return (game);
}
