/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** CPE_matchstick_2017 made by Sanchez Lucas
*/

#include "my.h"

int error_str_gesture(char *str)
{
	if (str == NULL)
		return (1);
	if (my_str_isnum(str + 1) == 1 && str[0] == '-')
		return (0);
	if (my_str_isnum(str) == 0 || my_strlen(str) == 0) {
		my_printf("Error: invalid input (positive number expected)\n");
		free(str);
		return (84);
	}
	return (0);
}

int error_line_gesture(int line, int lines)
{
	if (line > lines || line < 1) {
		my_printf("Error: this line is out of range\n");
		return (84);
	}
	return (0);
}

int error_nb_matches_gesture(sticks_t *sticks, int line, int nb_matches)
{
	if (nb_matches == 0 || nb_matches < 0) {
		if (nb_matches == 0) {
			my_printf("Error: you have to remove ");
			my_printf("at least one match\n");
		} else {
			my_printf("Error: invalid input ");
			my_printf("(positive number expected)\n");
		}
		return (84);
	} else if (nb_matches > sticks->max_matches) {
		my_printf("Error: you cannot remove more than ");
		my_printf("%d matches per turn\n", sticks->max_matches);
		return (84);
	} else if (sticks->sticks[line - 1] < nb_matches) {
		my_printf("Error: not enough matches on this line\n");
		return (84);
	}
	return (0);
}

int error_args_gesture(char **str, int size)
{
	if (size != 3)
		return (1);
	if (my_str_isnum(str[1]) == 0 || my_str_isnum(str[2]) == 0)
		return (1);
	if (my_getnbr(str[1]) <= 0 || my_getnbr(str[2]) <= 0)
		return (1);
	return (0);
}
