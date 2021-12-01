/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:11:53 by jbadia            #+#    #+#             */
/*   Updated: 2021/07/21 10:07:14 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_map *map)
{
	free_game(map);
	mlx_destroy_window(map->vars.mlx, map->vars.win);
	exit (0);
}

int	ft_putstr_err(char *error)
{
	ft_putendl_fd(error, 2);
	exit (1);
}

void	ft_move_counter(t_map *map)
{
	char	*nb_str;
	char	*count;

	nb_str = ft_itoa(map->count);
	count = ft_strjoin("move counter :", nb_str);
	mlx_string_put(map->vars.mlx, map->vars.win, 15, 20, 0x000066, count);
	free(nb_str);
	free(count);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	char	*line;

	line = NULL;
	map = NULL;
	ft_check_args(argc, argv[1]);
	map = copy_map(argv[1], line);
	map_checker(map);
	map->vars.anim = 0;
	map->vars.mlx = mlx_init();
	map->vars.win = mlx_new_window(map->vars.mlx, map->width * 32,
			map->height * 32, "so_long");
	ft_set_img(map);
	mlx_hook(map->vars.win, 2, 1L <<0, deal_key, map);
	mlx_hook(map->vars.win, 17, 1L <<17, close_win, map);
	mlx_loop_hook(map->vars.mlx, ft_print_texture, map);
	mlx_loop(map->vars.mlx);
}
