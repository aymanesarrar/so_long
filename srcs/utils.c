/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysarrar <aysarrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:09:56 by aysarrar          #+#    #+#             */
/*   Updated: 2022/01/10 11:11:05 by aysarrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*free_2d(char **tab)
{
	int	index;

	index = 0;
	while (tab[index])
	{
		free(tab[index]);
		index++;
	}
	free(tab);
	return (NULL);
}

int	check_map_ones(t_game *game)
{
	int	index;
	int	jndex;

	index = 0;
	jndex = 0;
	while (index < game->map_height)
	{
		jndex = 0;
		while (jndex < game->map_width)
		{
			if (game->map[0][jndex] != '1' ||
				game->map[index][0] != '1' ||
				game->map[game->map_height - 1][jndex] != '1' ||
				game->map[index][game->map_width - 1] != '1')
				return (FALSE);
			jndex++;
		}
		index++;
	}
	return (TRUE);
}

int	check_starting_position(t_game *game)
{
	int	index;
	int	jndex;
	int	count;

	index = 0;
	count = 0;
	while (game->map[index])
	{
		jndex = 0;
		while (game->map[index][jndex])
		{
			if (game->map[index][jndex] == 'P')
				count++;
			jndex++;
		}
		index++;
	}
	return (count == 1);
}

void	get_player_position(t_game *game)
{
	int	index;
	int	jndex;

	index = 0;
	while (game->map[index])
	{
		jndex = 0;
		while (game->map[index][jndex])
		{
			if (game->map[index][jndex] == 'P')
			{
				game->player_y = index;
				game->player_x = jndex;
			}
			jndex++;
		}
		index++;
	}
}

int	collectible_count(t_game *game)
{
	int	index;
	int	jndex;
	int	count;

	index = 0;
	count = 0;
	while (game->map[index])
	{
		jndex = 0;
		while (game->map[index][jndex])
		{
			if (game->map[index][jndex] == 'C')
				count++;
			jndex++;
		}
		index++;
	}
	return (count);
}
