/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_graphics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:10:05 by juandrie          #+#    #+#             */
/*   Updated: 2023/10/18 13:30:07 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_barrier(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer, \
		game->winpointer, game->barrier, width * 40, height * 40);
}

void	draw_exit(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer, \
		game->winpointer, game->exit, width * 40, height * 40);
}

void	draw_floor(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer, \
		game->winpointer, game->floor, width * 40, height * 40);
}

void	process_cell(t_complete *game, char cell, int x, int y)
{
	if (cell == '1')
	{
		draw_barrier(game, x, y);
	}
	if (cell == 'C')
	{
		place_collectable(game, x, y);
	}
	if (cell == 'P')
	{
		place_player(game, x, y);
	}
	if (cell == 'E')
	{
		draw_exit(game, x, y);
	}
	if (cell == '0')
	{
		draw_floor(game, x, y);
	}
}

void	adding_in_graphics(t_complete *game)
{
	int	line;
	int	column;

	game->collectables = 0;
	line = 0;
	while (line < game->heightmap)
	{
		column = 0;
		while (game->map[line][column])
		{
			process_cell(game, game->map[line][column], line, column);
			column++;
		}
		line++;
	}
}
