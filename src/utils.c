/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:35:29 by juandrie          #+#    #+#             */
/*   Updated: 2023/10/23 14:06:22 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!big)
		return (NULL);
	if (little[j] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] != '\0' && big[i + j] == little[j])
				j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}

int	open_map_file(t_complete *game, const char *filename)
{
	game->fd = open(filename, O_RDONLY);
	if (game->fd < 0)
		return (0);
	return (1);
}

int	display_map(t_complete *game)
{
	int	screen_width;
	int	screen_height;
	int	required_width;
	int	required_height;

	required_width = game->widthmap * 50;
	required_height = game->heightmap * 50;
	mlx_get_screen_size(game->mlxpointer, &screen_width, &screen_height);
	if (screen_width >= required_width && screen_height >= required_height)
		return (1);
	else
	{
		ft_printf("Error\nThe map is too big for the screen.\n");
		exit_point(game);
		exit(0);
	}
}
