/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:13:12 by jbadia            #+#    #+#             */
/*   Updated: 2021/07/20 15:04:18 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_endgame(t_map *map)
{
	free_game(map);
	write(1, "WINNER", 7);
	mlx_destroy_window(map->vars.mlx, map->vars.win);
	exit (0);
}

void	free_game(t_map *map)
{
	int	i;

	i = 0;
	if (map && map->board)
	{
		while (i < map->height)
		{
			free(map->board[i]);
			i++;
		}
		free(map->board);
		if (map)
			free((void *)map);
	}
}
