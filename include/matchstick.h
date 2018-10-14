/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** NULL
*/

#ifndef MATCHSTICK
#define MATCHSTICK

#include <time.h>

typedef struct sticks_s {
	int nb_lines;
	int max_matches;
	int *sticks;
} sticks_t;

typedef struct ai_choice_s {
	int line;
	int matches;
} ai_choice_t;

typedef struct ai_turn_s {
	int line;
	int nb_matches;
	int score;
	struct ai_turn_s *next;
} ai_turn_t;

int error_line_gesture(int, int);
int error_nb_matches_gesture(sticks_t *, int, int);
int error_str_gesture(char *);
void print_board(int, int *);
int error_args_gesture(char **, int);
void print_board(int, int *);
void artificial_intelligence(sticks_t *);
int game_loop(sticks_t *);
int player_turn(sticks_t *);
int number_of_lines(sticks_t *);
int remaining_sticks(sticks_t *);
void random_game(sticks_t, ai_turn_t *);

#endif /* MATCHSTICK */
