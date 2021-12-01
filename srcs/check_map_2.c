/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:47:54 by jbadia            #+#    #+#             */
/*   Updated: 2021/07/20 13:59:44 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->board[i][j])
		{
			if (map->board[i][j] == PLAYER || map->board[i][j] == PLAYER_L
			|| map->board[i][j] == PLAYER_R || map->board[i][j] == PLAYER_U)
			{
				map->x_pos = i;
				map->y_pos = j;
			}
			j++;
		}
		i++;
	}
}

int	ft_check_player(t_map *map)
{
	int	i;
	int	j;
	int	count_p;

	i = 0;
	j = 0;
	count_p = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->board[i][j])
		{
			if (map->board[i][j] == PLAYER)
				count_p++;
			j++;
		}
		i++;
	}
	if (count_p > 1 || count_p <= 0)
		return (1);
	return (0);
}

int	ft_check_exit(t_map *map)
{
	int	i;
	int	j;
	int	count_e;

	i = 0;
	j = 0;
	count_e = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->board[i][j])
		{
			if (map->board[i][j] == EXIT)
				count_e++;
			j++;
		}
		i++;
	}
	if (count_e > 2 || count_e <= 0)
		return (1);
	return (0);
}

int	ft_check_coin(t_map *map)
{
	int	i;
	int	j;
	int	count_c;

	i = 0;
	j = 0;
	count_c = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->board[i][j])
		{
			if (map->board[i][j] == COIN)
			{
				count_c++;
				map->coin_count++;
			}
			j++;
		}
		i++;
	}
	if (count_c < 1 || count_c <= 0)
		return (1);
	return (0);
}
