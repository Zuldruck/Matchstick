/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** CPE_matchstick_2017 made by Sanchez Lucas
*/

#include "my.h"

int line_input(sticks_t *sticks)
{
	char *str = NULL;
	int line = 0;
	int a = 0;

	my_printf("Line: ");
	str = get_next_line(0);
	a = error_str_gesture(str);
	if (a == 84)
		return (0);
	else if (a == 1)
		return (-1);
	line = my_getnbr(str);
	free(str);
	if (error_line_gesture(line, sticks->nb_lines) == 84)
		return (0);
	return (line);
}

int matches_input(sticks_t *sticks, int line)
{
	char *str = NULL;
	int nb_matches = 0;
	int a = 0;

	my_printf("Matches: ");
	str = get_next_line(0);
	a = error_str_gesture(str);
	if (a == 84)
		return (0);
	else if (a == 1)
		return (-1);
	nb_matches = my_getnbr(str);
	free(str);
	if (error_nb_matches_gesture(sticks, line, nb_matches) == 84)
		return (0);
	return (nb_matches);
}

int player_turn(sticks_t *sticks)
{
	int line = 0;
	int nb_matches = 0;

	while (1) {
		line = line_input(sticks);
		if (line == 0)
			continue;
		else if (line == -1)
			return (1);
		nb_matches = matches_input(sticks, line);
		if (nb_matches == 0)
			continue;
		else if (nb_matches == -1)
			return (1);
		break;
	}
	sticks->sticks[line - 1] -= nb_matches;
	my_printf("Player removed %d match(es) ", nb_matches);
	my_printf("from line %d\n", line);
	return (0);
}
