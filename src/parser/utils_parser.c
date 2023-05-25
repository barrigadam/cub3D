/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 04:42:51 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/25 18:18:40 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_search_first(int fd, int height)
{
	char	*line;

	while (height > 1)
	{
		line = get_next_line(fd);
		free(line);
		height--;
	}
}

/**
 * @brief Guarda el  total de las lineas del archivo .cub
 * 
 * @param path_map ruta del mapa seleccionado
 * @param map estructura para guardar las medidas del mapa
 */
void	height_map(char *path_map, t_map *map)
{
	int		fd;
	char	*m_map;

	fd = open(path_map, O_RDONLY);
	map->height = 0;
	if (fd < 0 || !path_map)
		return ;
	fd = open(path_map, O_RDONLY);
	m_map = get_next_line(fd);
	while (m_map)
	{
		free(m_map);
		m_map = get_next_line(fd);
		map->height++;
	}
	close(fd);
}

/**
 * @brief Funcion para encontrar la primera linea del mapa
 * 
 * @param fd fd abierto por la fucion desde la que se llama
 * @return int 
 */
int	first_line_map(int fd, t_map *map)
{
	int		i;
	char	*line;
	int		found;

	map->start_map = 0;
	line = get_next_line(fd);
	found = 0;
	while (line)
	{
		if (!found)
			map->start_map++;
		i = -1;
		while (line[++i])
		{
			if ((line[i] != '1' && line[i] != '\t' && line[i] != ' '))
				break ;
			found = 1;
		}
		free(line);
			line = get_next_line(fd);
		if (found)
			return (free(line), map->start_map);
	}
	return (close(fd), map->start_map);
}

/**
 * @brief Funcion para contar el numero de caracteres de cada linea
 * 
 * @param map estructura del mapa
 * @param map ruta del mapa seleccionado
 */
void	width_map(char *path_map, t_map	*map)
{
	int		fd;
	int		first_line;
	char	*m_map;

	fd = open(path_map, O_RDONLY);
	map->width = 0;
	map->height = 0;
	first_line = first_line_map(fd, map);
	fd = open(path_map, O_RDONLY);
	while (first_line-- > 1)
	{
		m_map = get_next_line(fd);
		free(m_map);
	}
	while (m_map != NULL)
	{
		if (map->width < (int)ft_strlen(m_map))
			map->width = (int)ft_strlen(m_map);
			map->height++;
		m_map = get_next_line(fd);
		free(m_map);
	}
	close(fd);
}
