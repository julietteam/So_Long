/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:32:24 by julietteand       #+#    #+#             */
/*   Updated: 2023/10/23 14:06:56 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <mlx.h>
# include <mlx_int.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../Libft/libft.h"

typedef struct t_start
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;
	char	**map;

	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}	t_complete;

int		exit_point(t_complete *game);
int		map_reading(t_complete *game, char **argv);
int		move(t_complete *game, int i, int j);
int		controls_working(int command, t_complete *game);
int		open_map_file(t_complete *game, const char *filename);
int		display_map(t_complete *game);
int		read_map_dimensions(t_complete *game);
int		width_map(char *str);
char	*ft_strstr(const char *big, const char *little);
void	adding_in_graphics(t_complete *game);
void	place_images_in_game(t_complete *game);
void	place_collectable(t_complete *game, int height, int width);
void	place_player(t_complete *game, int height, int width);
void	check_errors(t_complete *game);
void	if_walls(t_complete *game);
void	process_cell(t_complete *game, char cell, int x, int y);
void	draw_barrier(t_complete *game, int x, int y);
void	draw_exit(t_complete *game, int x, int y);
void	draw_floor(t_complete *game, int x, int y);
void	free_map(t_complete *game);
void	destroy_images(t_complete *game);
void	clean_up_game(t_complete *game);

#endif