/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:51:16 by juandrie          #+#    #+#             */
/*   Updated: 2023/10/18 11:53:48 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_checker(t_complete *game, int h, int w)
{
	if (game->map[h][w] != '1' &&
		game->map[h][w] != '0' &&
		game->map[h][w] != 'P' &&
		game->map[h][w] != 'E' &&
		game->map[h][w] != 'C' &&
		game->map[h][w] != '\n')
	{
		ft_printf("\nError Here!%c\n", game->map[h][w]);
		exit_point(game);
	}
	if (game->map[h][w] == 'C')
		game->columncount++;
	if (game->map[h][w] == 'P')
		game->playercount++;
	if (game->map[h][w] == 'E')
		game->exitcount++;
}

void	character_valid(t_complete *game)
{
	int	line;
	int	column;

	line = 0;
	while (line < game->heightmap - 1)
	{
		column = 0;
		while (column <= game->widthmap)
		{
			count_checker(game, line, column);
			column++;
		}
		line++;
	}
	if (!(game->playercount == 1 && game->columncount >= 1
			&& game->exitcount == 1))
	{
		ft_printf("\nError\nSomething is wrong!\n");
		ft_printf("either player, exit or collectable issue\n");
		exit_point(game);
	}
}

void	check_errors(t_complete *game)
{
	if_walls(game);
	character_valid(game);
}
