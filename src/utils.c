/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:35:29 by juandrie          #+#    #+#             */
/*   Updated: 2023/10/18 18:32:06 by juandrie         ###   ########.fr       */
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

int	is_valid_file_extension(const char *filename)
{
	const char	*file_extension;

	file_extension = ".ber";
	if (ft_strstr(filename, file_extension) == NULL)
	{
		return (0);
	}
	return (1);
}

int	open_map_file(t_complete *game, const char *filename)
{
	game->fd = open(filename, O_RDONLY);
	if (game->fd < 0)
	{
		return (0);
	}
	return (1);
}

int	check_map_size(t_complete *game)
{
	if (game->widthmap > 48 || game->heightmap > 27)
	{
		ft_printf("The map is too big for the screen.\n");
		exit_point(game);
		exit (0);
	}
	return (1);
}
