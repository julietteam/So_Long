/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:14:42 by julietteand       #+#    #+#             */
/*   Updated: 2023/10/18 18:35:29 by juandrie         ###   ########.fr       */
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
		if (!readmap)
			break ;
		if (!add_line(game, readmap))
		{
			free (readmap);
			break ;
		}
		game->widthmap = width_map(game->map[0]);
	}
	close (game->fd);
	return (1);
}

int	map_reading(t_complete *game, int ac, char **argv)
{
	char	*filename;

	filename = argv[1];
	if (ac != 2 || !is_valid_file_extension(filename))
		return (0);
	if (!open_map_file(game, filename))
		return (0);
	if (!read_map_dimensions(game))
		return (0);
	if (!check_map_size(game))
	{
		return (0);
	}
	return (1);
}
