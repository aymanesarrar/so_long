/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysarrar <aysarrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:13:16 by aysarrar          #+#    #+#             */
/*   Updated: 2022/01/09 19:40:45 by aysarrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	check_endgame(t_game *game)
{
	if (game->collectable == game->collected)
		game->endgame = TRUE;
}

void	endgame(t_game *game)
{
	if (game->endgame == TRUE)
	{
		free_2d(game->map);
		free(game->player_w);
		free(game->player_a);
		free(game->player_s);
		free(game->player_d);
		free(game->img_space);
		free(game->img_collect);
		free(game->img_exit);
		free(game->img_wall);
		free(game->img_player);
		mlx_destroy_window(game->mlx, game->win);
		exit(1);
	}
}