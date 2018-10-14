/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** CPE_matchstick_2017 made by Sanchez Lucas
*/

#include "my.h"

int print_player_turn(sticks_t *sticks)
{
	my_printf("Your turn:\n");
	if (player_turn(sticks) == 1)
		return (3);
	print_board(sticks->nb_lines, sticks->sticks);
       	if (remaining_sticks(sticks) == 0) {
		my_printf("You lost, too bad...\n");
		return (2);
	}
	my_putchar('\n');
	return (0);
}

int print_ai_turn(sticks_t *sticks)
{
	my_printf("AI's turn...\n");
	artificial_intelligence(sticks);
	print_board(sticks->nb_lines, sticks->sticks);
	if (remaining_sticks(sticks) == 0) {
		my_printf("I lost... snif... ");
		my_printf("but I'll get you next time!!\n");
		return (1);
	}
	my_putchar('\n');
	return (0);
}

int game_loop(sticks_t *sticks)
{
	int player = 0;
	int ai = 0;

	my_putstr("\033c");
	print_board(sticks->nb_lines, sticks->sticks);
	my_putchar('\n');
	while (1) {
		player = print_player_turn(sticks);
		if (player == 2)
			return (2);
		else if (player == 3)
			return (0);
		my_putstr("\033c");
		ai = print_ai_turn(sticks);
		if (ai == 1)
			return (1);
	}
	return (0);
}
