/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** CPE_matchstick_2017 made by Sanchez Lucas
*/

#include "my.h"

int *sticks_array(int lines)
{
	int nb_sticks = 1;
	int *sticks = malloc(sizeof(int) * lines);

	for (int i = 0; i < lines; i++) {
		sticks[i] = nb_sticks;
		nb_sticks += 2;
	}
	return (sticks);
}

int main(int ac, char **av)
{
	sticks_t *sticks = malloc(sizeof(*sticks));
	int ret = 0;

	srandom(time(NULL));
	if (error_args_gesture(av, ac) == 1) {
		free(sticks);
		return (84);
	}
	sticks->nb_lines = my_getnbr(av[1]);
	sticks->max_matches = my_getnbr(av[2]);
	sticks->sticks = sticks_array(sticks->nb_lines);
	ret = game_loop(sticks);
	free(sticks->sticks);
	free(sticks);
	return (ret);
}
