/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:34:50 by julietteand       #+#    #+#             */
/*   Updated: 2023/10/18 17:54:23 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	horizontalwall(t_complete *game)
{
	int	width;
	int	column;

	width = game->widthmap;
	column = 0;
	while (column < width)
	{
		if (game->map[0][width] == '1' &&
			game->map[game->heightmap - 1][column] == '1')
			return (0);
		column++;
	}
	return (1);
}

static int	verticalwall(t_complete *game)
{
	int	line;
	int	height;

	line = 0;
	height = game->widthmap;
	while (line < game->heightmap)
	{
		if (!(game->map[line][0] == '1' && game->map[line][height - 1] == '1'))
			return (0);
		line++;
	}
	return (1);
}

void	if_walls(t_complete *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = verticalwall(game);
	horizontalwalls = horizontalwall(game);
	if (!verticalwalls || !horizontalwalls)
	{
		ft_printf("No walls !!\n");
		exit_point(game);
	}
}
