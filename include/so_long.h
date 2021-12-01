/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:04:55 by jbadia            #+#    #+#             */
/*   Updated: 2021/07/20 17:26:12 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PLAYER 'P'
# define PLAYER_U 'U'
# define PLAYER_L 'L'
# define PLAYER_R 'R'
# define EXIT 'E'
# define COIN 'C'
# define WALL '1'
# define PATH '0'
# define ENEMY '9'

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

enum e_key_board
{
	key_board_A	=	0x00,
	key_board_S	=	0x01,
	key_board_D	=	0x02,
	key_board_W	=	0x0D,
	key_board_Escape	= 0x35,
};

typedef struct s_ennemy
{
	void	*img;
}				t_ennemy;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*relative_path;
	int			img_width;
	int			img_height;
	char		*img_player;
	char		*img_pback;
	char		*img_prigth;
	char		*img_pleft;
	char		*img_coin;
	char		*img_wall;
	char		*img_path;
	char		*img_exit;
	t_ennemy	img_enemy[2];
	int			anim;

}				t_vars;

typedef struct s_map
{
	int		count;
	int		coin_count;
	int		height;
	int		width;
	int		x_pos;
	int		y_pos;
	char	**board;
	t_vars	vars;

}				t_map;

int		ft_check_args(int argc, char *argv);
int		ft_line_counter(char *file_argv);
t_map	*create_map(char *file_argv);
t_map	*copy_map(char *file_argv, char *line);
void	add_line(t_map *map, char *line);
void	init_struct(t_map *map);
void	ft_find_player(t_map *map);
int		ft_check_coin(t_map *map);
int		ft_check_exit(t_map *map);
int		ft_check_player(t_map *map);

int		map_checker(t_map *map);
int		ft_elem_checker(t_map *map);
int		ft_wall_checker(t_map *map);
int		ft_wall_checker2(t_map *map);
int		ft_is_square(t_map *map);

int		ft_deal_enemy(t_map *map);
void	ft_print_count(t_map *map);

int		ft_print_texture(t_map *map);
void	ft_put_img_to_win(t_map *map, int i, int j);
void	ft_put_img_to_win2(t_map *map, int i, int j);
void	ft_set_img(t_map *map);
void	*ft_check_img(t_map *map, char *img_path);

int		deal_key(int key, t_map *map);
void	ft_move_left(t_map *map);
void	ft_move_right(t_map *map);
void	ft_move_up(t_map *map);
void	ft_move_down(t_map *map);

int		ft_putstr_err(char *error);
int		close_win(t_map *map);
void	ft_move_counter(t_map *map);

void	ft_endgame(t_map *map);
void	free_game(t_map *map);

#endif