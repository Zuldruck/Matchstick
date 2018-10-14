/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** CPE_matchstick_2017 made by Sanchez Lucas
*/

#include "my.h"

int number_of_lines(sticks_t *sticks)
{
	int lines = 0;

	for (int i = 0; i < sticks->nb_lines; i++)
		if (sticks->sticks[i] > 0)
			lines += 1;
	return (lines);
}

int remaining_sticks(sticks_t *sticks)
{
	int remaining_sticks = 0;

	for (int i = 0; i < sticks->nb_lines; i++)
		remaining_sticks += sticks->sticks[i];
	return (remaining_sticks);
}
