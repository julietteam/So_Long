/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:08:30 by juandrie          #+#    #+#             */
/*   Updated: 2023/10/25 13:52:08 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mark_visited(t_complete *game, char **temp_map, int x, int y)
{
	if ((temp_map[y][x] != '0' && temp_map[y][x] != 'C' && temp_map[y][x] != 'E'\
		&& temp_map[y][x] != 'P') || temp_map[y][x] == 'V')
		return ;
	temp_map[y][x] = 'V';
	if (x + 1 < game->widthmap)
		mark_visited(game, temp_map, x + 1, y);
	if (x - 1 >= 0)
		mark_visited(game, temp_map, x - 1, y);
	if (y + 1 < game->heightmap)
		mark_visited(game, temp_map, x, y + 1);
	if (y - 1 >= 0)
		mark_visited(game, temp_map, x, y - 1);
}

bool	reachable(t_complete *game, char **temp_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->heightmap)
	{
		j = 0;
		while (j < game->widthmap)
		{
			if (temp_map[i][j] == 'E')
				return (false);
			if (temp_map[i][j] == 'C')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	is_valid_path(t_complete *game)
{
	int		i;
	int		player_x;
	int		player_y;
	char	**temp_map;
	bool	valid;

	i = 0;
	player_x = game->x;
	player_y = game->y;
	temp_map = (char **)malloc(game->heightmap * sizeof(char *));
	while (i < game->heightmap)
	{
		temp_map[i] = ft_strdup(game->map[i]);
		i++;
	}
	mark_visited(game, temp_map, player_x, player_y);
	valid = reachable(game, temp_map);
	i = 0;
	while (i < game->heightmap)
	{
		free(temp_map[i]);
		i++;
	}
	free(temp_map);
	return (valid);
}
