/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:54:18 by juandrie          #+#    #+#             */
/*   Updated: 2023/10/19 15:28:01 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_complete *game)
{
	int	line;

	line = 0;
	while (line < game->heightmap && game->map)
	{
		free(game->map[line++]);
	}
	free(game->map);
}

void	destroy_images(t_complete *game)
{
	if (game->exit)
		mlx_destroy_image(game->mlxpointer, game->exit);
	if (game->floor)
		mlx_destroy_image(game->mlxpointer, game->floor);
	if (game->barrier)
		mlx_destroy_image(game->mlxpointer, game->barrier);
	if (game->player)
		mlx_destroy_image(game->mlxpointer, game->player);
	if (game->collectable)
		mlx_destroy_image(game->mlxpointer, game->collectable);
}

void	clean_up_game(t_complete *game)
{
	free_map(game);
	if (!game->mlxpointer)
		exit(0);
	destroy_images(game);
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	mlx_destroy_display(game->mlxpointer);
	free(game->mlxpointer);
}

int	exit_point(t_complete *game)
{
	if (!game)
		exit(0);
	clean_up_game(game);
	exit(0);
}
