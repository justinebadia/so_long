/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:01:40 by jbadia            #+#    #+#             */
/*   Updated: 2021/07/20 13:43:38 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_print_texture(t_map *map)
{
	int			i;
	int			j;
	static int	k = 0;

	i = 0;
	if (k % 50 == 0)
		map->vars.anim ^= 1;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_put_img_to_win(map, i, j);
			j++;
		}
		i++;
	}
	ft_move_counter(map);
	k++;
	return (0);
}

void	ft_put_img_to_win(t_map *map, int i, int j)
{
	if (map->board[i][j] == WALL)
		mlx_put_image_to_window(map->vars.mlx, map->vars.win,
			map->vars.img_wall, j * 32, i * 32);
	if (map->board[i][j] == PATH)
		mlx_put_image_to_window(map->vars.mlx, map->vars.win,
			map->vars.img_path, j * 32, i * 32);
	if (map->board[i][j] == EXIT)
		mlx_put_image_to_window(map->vars.mlx, map->vars.win,
			map->vars.img_exit, j * 32, i * 32);
	if (map->board[i][j] == COIN)
		mlx_put_image_to_window(map->vars.mlx, map->vars.win,
			map->vars.img_coin, j * 32, i * 32);
	if (map->board[i][j] == PLAYER)
		mlx_put_image_to_window(map->vars.mlx, map->vars.win,
			map->vars.img_player, j * 32, i * 32);
	ft_put_img_to_win2(map, i, j);
}

void	ft_put_img_to_win2(t_map *map, int i, int j)
{
	if (map->board[i][j] == ENEMY)
		mlx_put_image_to_window(map->vars.mlx, map->vars.win,
			map->vars.img_enemy[map->vars.anim].img, j * 32, i * 32);
	if (map->board[i][j] == PLAYER_U)
		mlx_put_image_to_window(map->vars.mlx, map->vars.win,
			map->vars.img_pback, j * 32, i * 32);
	if (map->board[i][j] == PLAYER_L)
		mlx_put_image_to_window(map->vars.mlx, map->vars.win,
			map->vars.img_pleft, j * 32, i * 32);
	if (map->board[i][j] == PLAYER_R)
		mlx_put_image_to_window(map->vars.mlx, map->vars.win,
			map->vars.img_prigth, j * 32, i * 32);
}

void	ft_set_img(t_map *map)
{
	map->vars.img_coin = ft_check_img(map, "./sprites/coin.xpm");
	map->vars.img_path = ft_check_img(map, "./sprites/path.xpm");
	map->vars.img_wall = ft_check_img(map, "./sprites/wall.xpm");
	map->vars.img_player = ft_check_img(map, "./sprites/down2.xpm");
	map->vars.img_exit = ft_check_img(map, "./sprites/exit.xpm");
	map->vars.img_enemy[0].img = ft_check_img(map, "./sprites/ennemy.xpm");
	map->vars.img_enemy[1].img = ft_check_img(map, "./sprites/ennemy2.xpm");
	map->vars.img_pback = ft_check_img(map, "./sprites/back.xpm");
	map->vars.img_prigth = ft_check_img(map, "./sprites/right.xpm");
	map->vars.img_pleft = ft_check_img(map, "./sprites/left.xpm");
}

void	*ft_check_img(t_map *map, char *img_path)
{
	int	fd;

	fd = open(img_path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("wrong path!", 2);
		close(fd);
		close_win(map);
	}
	close(fd);
	return (mlx_xpm_file_to_image(map->vars.mlx, img_path,
			&map->vars.img_width, &map->vars.img_height));
}
