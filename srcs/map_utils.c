/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:19:05 by jbadia            #+#    #+#             */
/*   Updated: 2021/07/21 10:08:32 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_args(int argc, char *argv)
{
	int	i;
	int	len;
	int	fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_putstr_err("fichier inexistant");
	close(fd);
	len = ft_strlen(argv) - 4;
	if (argc > 2)
		ft_putstr_err("ERROR - trop d'arguments");
	if (ft_strncmp(&argv[len], ".ber", 4))
		ft_putstr_err("ERROR - .ber");
	return (0);
}

int	ft_line_counter(char *file_argv)
{
	int		fd;
	char	buff[2];
	int		bytes;
	int		count_lines;

	count_lines = 0;
	fd = open(file_argv, O_RDONLY);
	if (fd < 0)
		return (-1);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buff, 1);
		if (bytes < 0)
		{
			close(fd);
			return (-1);
		}
		buff[bytes] = '\0';
		if (ft_strchr(buff, '\n'))
			count_lines++;
	}
	close(fd);
	return (count_lines + 1);
}

t_map	*create_map(char *file_argv)
{
	t_map	*map;
	int		line_count;

	line_count = ft_line_counter(file_argv);
	if (line_count == -1)
		return (NULL);
	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	init_struct(map);
	map->height = line_count;
	map->board = (char **)ft_calloc((line_count + 1), (sizeof(char *)));
	if (!map->board)
	{
		free((void *)&map);
		return (NULL);
	}
	return (map);
}

t_map	*copy_map(char *file_argv, char	*line)
{
	int		ret_gnl;
	int		fd;
	t_map	*map;

	map = create_map(file_argv);
	if (!map)
		return (NULL);
	fd = open(file_argv, O_RDONLY);
	if (fd < 0)
		free((void **)&map);
	if (fd < 0)
		return (NULL);
	ret_gnl = 1;
	while (ret_gnl > 0)
	{
		ret_gnl = get_next_line(fd, &line);
		if (ret_gnl == -1)
		{
			close(fd);
			free((void *)&map);
			return (NULL);
		}
		add_line(map, line);
	}
	return (map);
}

void	add_line(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (i < map->height && map->board[i])
		i++;
	if (i < map->height)
		map->board[i] = line;
	if (i == 0)
		map->width = (int)ft_strlen(line);
}
