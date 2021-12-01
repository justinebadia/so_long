/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:07:07 by jbadia            #+#    #+#             */
/*   Updated: 2021/07/20 17:07:04 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key, t_map *map)
{
	ft_find_player(map);
	if (key == key_board_A)
		ft_move_left(map);
	if (key == key_board_D)
		ft_move_right(map);
	if (key == key_board_W)
		ft_move_up(map);
	if (key == key_board_S)
		ft_move_down(map);
	if (key == key_board_Escape)
		close_win(map);
	return (0);
}

void	ft_move_up(t_map *map)
{
	int	i;
	int	j;

	i = map->x_pos;
	j = map->y_pos;
	if (map->board[i - 1][j] != WALL)
	{
		if (map->board[i - 1][j] == EXIT && map->coin_count == 0)
			ft_endgame(map);
		else if (map->board[i - 1][j] == ENEMY)
			ft_deal_enemy(map);
		else
		{
			if (map->board[i - 1][j] == PATH || map->board[i - 1][j] == COIN)
			{
				if (map->board[i - 1][j] == COIN)
					map->coin_count--;
				map->board[i][j] = PATH;
				map->board[i - 1][j] = PLAYER_U;
				map->count++;
			}
		}
		ft_print_count(map);
	}
}

void	ft_move_down(t_map *map)
{
	int	i;
	int	j;

	i = map->x_pos;
	j = map->y_pos;
	if (map->board[i + 1][j] != WALL)
	{
		if (map->board[i + 1][j] == EXIT && map->coin_count == 0)
			ft_endgame(map);
		else if (map->board[i + 1][j] == ENEMY)
			ft_deal_enemy(map);
		else
		{
			if (map->board[i + 1][j] == PATH || map->board[i + 1][j] == COIN)
			{
				if (map->board[i + 1][j] == COIN)
					map->coin_count--;
				map->board[i][j] = PATH;
				map->board[i + 1][j] = PLAYER;
				map->count++;
			}
		}
		ft_print_count(map);
	}
}

void	ft_move_left(t_map *map)
{
	int	i;
	int	j;

	i = map->x_pos;
	j = map->y_pos;
	if (map->board[i][j - 1] != WALL)
	{
		if (map->board[i][j - 1] == EXIT && map->coin_count == 0)
			ft_endgame(map);
		else if (map->board[i][j - 1] == ENEMY)
			ft_deal_enemy(map);
		else
		{
			if (map->board[i][j - 1] == PATH || map->board[i][j - 1] == COIN)
			{
				if (map->board[i][j - 1] == COIN)
					map->coin_count--;
				map->board[i][j] = PATH;
				map->board[i][j - 1] = PLAYER_L;
				map->count++;
			}
		}
		ft_print_count(map);
	}
}

void	ft_move_right(t_map *map)
{
	int	i;
	int	j;

	i = map->x_pos;
	j = map->y_pos;
	if (map->board[i][j + 1] != WALL)
	{
		if (map->board[i][j + 1] == EXIT && map->coin_count == 0)
			ft_endgame(map);
		else if (map->board[i][j + 1] == ENEMY)
			ft_deal_enemy(map);
		else
		{
			if (map->board[i][j + 1] == PATH || map->board[i][j + 1] == COIN)
			{
				if (map->board[i][j + 1] == COIN)
					map->coin_count--;
				map->board[i][j] = PATH;
				map->board[i][j + 1] = PLAYER_R;
				map->count++;
			}
		}
		ft_print_count(map);
	}
}
