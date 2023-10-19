/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:27:53 by julietteand       #+#    #+#             */
/*   Updated: 2023/10/18 15:34:34 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_memset_sl(void *pointeurmem, int valeur, size_t length)
{
	unsigned char	*pointeur;

	pointeur = (unsigned char *)pointeurmem;
	while (length--)
		*pointeur++ = (unsigned char)valeur;
	return (pointeurmem);
}

int	main(int ac, char **av)
{
	t_complete	game;

	if (ac != 2)
		return (1);
	ft_memset_sl(&game, 0, sizeof(t_complete));
	map_reading(&game, ac, av);
	check_errors(&game);
	game.mlxpointer = mlx_init();
	if (!game.mlxpointer)
		return (1);
	game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * 40),
			(game.heightmap * 40), "solong");
	if (!game.winpointer)
	{
		mlx_destroy_display(game.mlxpointer);
		return (1);
	}
	place_images_in_game(&game);
	adding_in_graphics(&game);
	mlx_key_hook(game.winpointer, controls_working, &game);
	mlx_hook(game.winpointer, 17, 0, (void *)exit_point, &game);
	mlx_loop(game.mlxpointer);
	return (0);
}
