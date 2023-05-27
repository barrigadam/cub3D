/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:41:41 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/27 15:15:43 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	checker_path_map(char *path_map)
{
	char	*extension;

	while (*(path_map + 4))
		path_map++;
	extension = ft_strdup(path_map);
	if (!ft_strncmp(extension, ".cub", 5))
		return (free(extension), 0);
	return (free(extension), 1);
}
