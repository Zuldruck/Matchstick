/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** CPE_matchstick_2017 made by Sanchez Lucas
*/

#include "my.h"

sticks_t my_struct_dup(sticks_t *sticks)
{
	int nb_lines = sticks->nb_lines;
	int max_matches = sticks->max_matches;
	int *board = malloc(sizeof(int) * sticks->nb_lines);
	sticks_t res;

	for (int i = 0; i < sticks->nb_lines; i++)
		board[i] = sticks->sticks[i];
	res.nb_lines = nb_lines;
	res.max_matches = max_matches;
	res.sticks = board;
	return (res);
}

void free_list(ai_turn_t *list)
{
	ai_turn_t *tmp = NULL;

	while (list) {
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

ai_choice_t find_greater_score(ai_turn_t *list)
{
	ai_choice_t choice;
	int score;

	list = list->next;
	score = list->score;
	while (list != NULL) {
		if (list->score >= score) {
			choice.line = list->line;
			choice.matches = list->nb_matches;
			score = list->score;
		}
		list = list->next;
	}
	return (choice);
}

void artificial_intelligence(sticks_t *sticks)
{
	sticks_t struct_dup;
	ai_turn_t *list = malloc(sizeof(*list));
	ai_choice_t choice;

	list->line = 0;
	list->nb_matches = 0;
	list->score = 0;
	list->next = NULL;
	for (int i = 0; i < 50000; i++) {
		struct_dup = my_struct_dup(sticks);
		random_game(struct_dup, list);
		free(struct_dup.sticks);
	}
	choice = find_greater_score(list);
	sticks->sticks[choice.line - 1] -= choice.matches;
	my_printf("AI removed %d match(es) from line %d\n",
						choice.matches, choice.line);
	free_list(list);
}
