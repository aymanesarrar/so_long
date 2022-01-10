/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysarrar <aysarrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:54:14 by aysarrar          #+#    #+#             */
/*   Updated: 2022/01/10 17:59:19 by aysarrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	increment_collected(t_game *game)
{
	char	*nb;
	int		index;

	index = 0;
	if (game->map[game->player_y][game->player_x] == 'C')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->collected++;
	}
	game->player_mouvement_counter++;
	while (game->map[0][index])
	{
		img_draw(game, game->img_wall, index, 0);
		index++;
	}
	nb = ft_itoa(game->player_mouvement_counter);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, nb);
	free(nb);
}

void	move_player_w(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] != '1')
	{
		if (game->map[game->player_y][game->player_x] == 'E')
			img_draw(game, game->img_exit, game->player_x, game->player_y);
		else
			img_draw(game, game->img_space, game->player_x, game->player_y);
		game->player_y--;
		img_draw(game, game->img_space, game->player_x, game->player_y);
		img_draw(game, game->player_w, game->player_x, game->player_y);
		increment_collected(game);
		check_endgame(game);
	}
	if (game->map[game->player_y][game->player_x] == 'E' &&
			game->endgame == TRUE)
		endgame(game);
	else if (game->map[game->player_y][game->player_x] == 'E')
	{
		img_draw(game, game->img_exit, game->player_x, game->player_y);
		img_draw(game, game->player_w, game->player_x, game->player_y);
	}
}

void	move_player_d(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] != '1')
	{
		if (game->map[game->player_y][game->player_x] == 'E')
			img_draw(game, game->img_exit, game->player_x, game->player_y);
		else
			img_draw(game, game->img_space, game->player_x, game->player_y);
		game->player_x++;
		img_draw(game, game->img_space, game->player_x, game->player_y);
		img_draw(game, game->player_d, game->player_x, game->player_y);
		increment_collected(game);
		check_endgame(game);
	}
	if (game->map[game->player_y][game->player_x] == 'E' &&
			game->endgame == TRUE)
		endgame(game);
	else if (game->map[game->player_y][game->player_x] == 'E')
	{
		img_draw(game, game->img_exit, game->player_x, game->player_y);
		img_draw(game, game->player_d, game->player_x, game->player_y);
	}
}

void	move_player_s(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] != '1')
	{
		if (game->map[game->player_y][game->player_x] == 'E')
			img_draw(game, game->img_exit, game->player_x, game->player_y);
		else
			img_draw(game, game->img_space, game->player_x, game->player_y);
		game->player_y++;
		img_draw(game, game->img_space, game->player_x, game->player_y);
		img_draw(game, game->player_s, game->player_x, game->player_y);
		increment_collected(game);
		check_endgame(game);
	}
	if (game->map[game->player_y][game->player_x] == 'E' &&
			game->endgame == TRUE)
		endgame(game);
	else if (game->map[game->player_y][game->player_x] == 'E')
	{
		img_draw(game, game->img_exit, game->player_x, game->player_y);
		img_draw(game, game->player_s, game->player_x, game->player_y);
	}
}

void	move_player_a(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] != '1')
	{
		if (game->map[game->player_y][game->player_x] == 'E')
			img_draw(game, game->img_exit, game->player_x, game->player_y);
		else
			img_draw(game, game->img_space, game->player_x, game->player_y);
		game->player_x--;
		img_draw(game, game->img_space, game->player_x, game->player_y);
		img_draw(game, game->player_a, game->player_x, game->player_y);
		increment_collected(game);
		check_endgame(game);
	}
	if (game->map[game->player_y][game->player_x] == 'E' &&
			game->collectable == TRUE)
		endgame(game);
	else if (game->map[game->player_y][game->player_x] == 'E')
	{
		img_draw(game, game->img_exit, game->player_x, game->player_y);
		img_draw(game, game->player_a, game->player_x, game->player_y);
	}
}
