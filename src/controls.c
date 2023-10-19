/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:50:15 by julietteand       #+#    #+#             */
/*   Updated: 2023/10/19 18:53:34 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	keyboard_w(t_complete *game, int movement)
{
	int	line;
	int	column;
	int	moving;

	line = game->x_axis;
	column = game->y_axis;
	if (movement == 119)
	{
		column--;
		if (game->map[column][line] == '1')
			return (0);
		moving = move(game, line, column);
		if (!moving)
			return (0);
	}
	ft_printf("Movements: %i\n", game->counter);
	return (1);
}

static int	keyboard_s(t_complete *game, int movement)
{
	int	line;
	int	column;
	int	moving;

	line = game->x_axis;
	column = game->y_axis;
	if (movement == 115)
	{
		column++;
		if (game->map[column][line] == '1')
			return (0);
		moving = move(game, line, column);
		if (!moving)
			return (0);
	}
	ft_printf("Movements: %i\n", game->counter);
	return (1);
}

static	int	keyboard_a(t_complete *game, int movement)
{
	int	line;
	int	column;
	int	moving;

	line = game->x_axis;
	column = game->y_axis;
	if (movement == 97)
	{
		line--;
		if (game->map[column][line] == '1')
			return (0);
		moving = move(game, line, column);
		if (!moving)
			return (0);
	}
	ft_printf("Movements: %i\n", game->counter);
	ft_printf("Items: %i\n", game->collectables);
	return (1);
}

static	int	keyboard_d(t_complete *game, int movement)
{
	int	line;
	int	column;
	int	moving;

	line = game->x_axis;
	column = game->y_axis;
	if (movement == 100)
	{
		line++;
		if (game->map[column][line] == '1')
			return (0);
		moving = move(game, line, column);
		if (!moving)
			return (0);
	}
	ft_printf("Movements: %i\n", game->counter);
	ft_printf("Items: %i\n", game->collectables);
	return (1);
}

int	controls_working(int command, t_complete *game)
{
	int	works;

	works = 0;
	if (command == 65307)
		exit_point(game);
	if (command == 'w' || command == 'W')
		works = keyboard_w(game, 119);
	if (command == 's' || command == 'S')
		works = keyboard_s(game, 115);
	if (command == 'a' || command == 'A')
		works = keyboard_a(game, 97);
	if (command == 'd' || command == 'D')
		works = keyboard_d(game, 100);
	if (works)
		adding_in_graphics(game);
	return (1);
}
