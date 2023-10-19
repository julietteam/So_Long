/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:35:29 by juandrie          #+#    #+#             */
/*   Updated: 2023/10/19 19:11:57 by juandrie         ###   ########.fr       */
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

// int	check_map_size(t_complete *game, int height, int width)
// {
// 	// if (game->widthmap > 48 || game->heightmap > 27)
	
// 	{
// 		ft_printf("Error\nThe map is too big for the screen.\n");
// 		exit_point(game);
// 		exit (0);
// 	}
// 	return (1);
// }
int display_map_if_resolution_permits(void *mlx_ptr, int required_width, int required_height) {
    int screen_width, screen_height;

    mlx_get_screen_size(mlx_ptr, &screen_width, &screen_height);

    if (screen_width >= required_width && screen_height >= required_height) {
        return 1; // La résolution de l'écran le permet.
    } else {
        ft_printf("Error\nThe map is too big for the screen.\n");
        exit_point(game); // Assurez-vous que cette fonction gère proprement la sortie.
        exit(0);
    }
}

