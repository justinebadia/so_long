/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:18:57 by jbadia            #+#    #+#             */
/*   Updated: 2021/07/20 14:10:08 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_checker(t_map *map)
{
	if (map->height < 3)
	{
		free_game(map);
		ft_putstr_err("Invalid map, too small!");
	}
	if (ft_check_coin(map) == 1 || ft_check_exit(map) == 1
		|| ft_check_player(map) == 1 || ft_elem_checker(map) == 1)
	{
		free_game(map);
		ft_putstr_err("Invalid map, missing or to many item!");
	}
	if (ft_wall_checker(map) == 1 || ft_wall_checker2(map) == 1)
	{
		free_game(map);
		ft_putstr_err("missing wall");
	}
	if (ft_is_square(map) == 1)
	{
		free_game(map);
		ft_putstr_err("not a square");
	}
	return (0);
}

int	ft_elem_checker(t_map *map)
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
			if ((map->board[i][j] != PLAYER) && (map->board[i][j] != EXIT)
			&& (map->board[i][j] != COIN) && (map->board[i][j] != WALL)
			&& (map->board[i][j] != PATH) && (map->board[i][j] != ENEMY)
			&& (map->board[i][j] != PLAYER_L) && (map->board[i][j] != PLAYER_R)
			&& (map->board[i][j] != PLAYER_U))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_wall_checker(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = map->height - 1;
	while (map->board[0][i])
	{
		if (map->board[0][i] != WALL)
			return (1);
		i++;
	}
	i = 0;
	while (map->board[j][i])
	{
		if (map->board[j][i] != WALL)
			return (1);
		i++;
	}
	return (0);
}

int	ft_wall_checker2(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = map->width - 1;
	while (i < map->height)
	{
		if (map->board[i][0] != WALL)
			return (1);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->board[i][j] != WALL)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_square(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(map->board[i]);
	while (i < map->height)
	{
		if ((int)ft_strlen(map->board[i]) != len)
			return (1);
		i++;
	}
	return (0);
}
