/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** CPE_matchstick_2017 made by Sanchez Lucas
*/

#include "my.h"

void print_end_start_lines(int lines)
{
	for (int i = 0; i < (lines * 2) + 1; i++)
		my_putchar('*');
	my_putchar('\n');
}

void print_board(int lines, int *sticks)
{
	int full_sticks = 1;

	if (lines < 1)
		return;
	print_end_start_lines(lines);
	for (int i = 0; i < lines; i++) {
		my_putchar('*');
		for (int j = 1; j < lines - i; j++)
			my_putchar(' ');
		for (int j = 0; j < sticks[i]; j++)
			my_putchar('|');
		for (int j = 1; j < lines - i + full_sticks - sticks[i]; j++)
			my_putchar(' ');
		full_sticks += 2;
		my_putchar('*');
		my_putchar('\n');
	}
	print_end_start_lines(lines);
}
