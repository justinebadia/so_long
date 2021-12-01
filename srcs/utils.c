/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:10:57 by jbadia            #+#    #+#             */
/*   Updated: 2021/07/20 17:33:07 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_deal_enemy(t_map *map)
{
	write(1, "LOSER", 6);
	free_game(map);
	mlx_destroy_window(map->vars.mlx, map->vars.win);
	exit (1);
}

void	ft_print_count(t_map *map)
{
	ft_putstr_fd("nombre de coups :", 1);
	ft_putnbr_fd(map->count, 1);
	ft_putstr_fd("\n", 1);
}

void	init_struct(t_map *map)
{
	map->coin_count = 0;
	map->count = 0;
	map->height = 0;
	map->width = 0;
	map->x_pos = 0;
	map->y_pos = 0;
	map->vars.anim = 0;
	map->vars.img_height = 0;
	map->vars.img_width = 0;
}
