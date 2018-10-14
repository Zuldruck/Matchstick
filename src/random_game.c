/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** CPE_matchstick_2017 made by Sanchez Lucas
*/

#include "my.h"

void add_to_list(ai_turn_t *list, ai_choice_t choice, int score)
{
	ai_turn_t *new_elem = malloc(sizeof(*new_elem));

	new_elem->line = choice.line;
	new_elem->nb_matches = choice.matches;
	new_elem->score = score;
	new_elem->next = NULL;
	for (; list->next != NULL; list = list->next) {
		if (list->line == choice.line
		&& list->nb_matches == choice.matches) {
			free(new_elem);
			list->score += score;
			return;
		}
	}
	if (list->line == choice.line && list->nb_matches == choice.matches) {
		free(new_elem);
		list->score += score;
		return;
	}
	list->next = new_elem;
}

void ai_turn(sticks_t *sticks)
{
	int line = 0;
	int nb_matches = 0;

	line = (random() % sticks->nb_lines) + 1;
	while (sticks->sticks[line - 1] == 0)
		line = (random() % sticks->nb_lines) + 1;
	nb_matches = (random() % sticks->sticks[line - 1]) + 1;
	while (nb_matches > sticks->max_matches)
		nb_matches = (random() % sticks->sticks[line - 1]) + 1;
	sticks->sticks[line - 1] -= nb_matches;
}

ai_choice_t first_ai_turn(sticks_t *sticks)
{
	ai_choice_t choice;

	choice.line = (random() % sticks->nb_lines) + 1;
	while (sticks->sticks[choice.line - 1] == 0)
		choice.line = (random() % sticks->nb_lines) + 1;
	choice.matches = (random() % sticks->sticks[choice.line - 1]) + 1;
	while (choice.matches > sticks->max_matches)
		choice.matches = (random() % sticks->sticks[choice.line - 1])
									+ 1;
	sticks->sticks[choice.line - 1] -= choice.matches;
	return (choice);
}

int verif_remaining_sticks(sticks_t sticks, int score,
					ai_choice_t choice, ai_turn_t *list)
{
	if (remaining_sticks(&sticks) == 0) {
		add_to_list(list, choice, score);
		return (1);
	}
	return (0);
}

void random_game(sticks_t sticks, ai_turn_t *list)
{
	ai_choice_t choice = first_ai_turn(&sticks);

	if (verif_remaining_sticks(sticks, -1, choice, list) == 1)
		return;
	ai_turn(&sticks);
	if (verif_remaining_sticks(sticks, 1, choice, list) == 1)
		return;
	while (1) {
		ai_turn(&sticks);
		if (verif_remaining_sticks(sticks, -1, choice, list) == 1)
			return;
		ai_turn(&sticks);
		if (verif_remaining_sticks(sticks, 1, choice, list) == 1)
			return;
	}
}
