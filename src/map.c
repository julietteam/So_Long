/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:14:42 by julietteand       #+#    #+#             */
/*   Updated: 2023/10/23 13:58:55 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	width_map(char *str)
{
	int	width;

	width = 0;
	while (str[width] != '\0')
		width++;
	if (str[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_complete *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	temporary = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	if (!temporary)
		return (0);
	temporary[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		temporary[i] = game->map[i];
		i++;
	}
	temporary[i] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	return (1);
}

int	read_map_dimensions(t_complete *game)
{
	char	*readmap;

	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!readmap && !game->map)
			return (close (game->fd), 0);
		if (!readmap)
			break ;
		if (!add_line(game, readmap))
		{
			free(readmap);
			get_next_line(-1);
			free(game->map);
			return (close (game->fd), 0);
		}
		game->widthmap = width_map(game->map[0]);
	}
	close (game->fd);
	return (1);
}

int	map_reading(t_complete *game, char **argv)
{
	char	*filename;

	filename = argv[1];
	if (!open_map_file(game, filename))
		return (0);
	if (!read_map_dimensions(game))
		return (0);
	return (1);
}
