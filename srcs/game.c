/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysarrar <aysarrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:09:06 by aysarrar          #+#    #+#             */
/*   Updated: 2022/01/10 11:18:21 by aysarrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	draw_assets(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_width)
	{
		y = 0;
		while (y < game->map_height)
		{
			if (game->map[y][x] == '1')
				img_draw(game, game->img_wall, x, y);
			else if (game->map[y][x] == 'E')
				img_draw(game, game->img_exit, x, y);
			else if (game->map[y][x] == 'P')
				img_draw(game, game->img_player, x, y);
			else if (game->map[y][x] == 'C')
				img_draw(game, game->img_collect, x, y);
			y++;
		}
		x++;
	}
}

void	draw_space(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_width)
	{
		y = 0;
		while (y < game->map_height)
		{
			img_draw(game, game->img_space, x, y);
			y++;
		}
		x++;
	}
}

int	press_key(int key, t_game *game)
{
	if (key == KEY_D)
		move_player_d(game);
	else if (key == KEY_A)
		move_player_a(game);
	else if (key == KEY_W)
		move_player_w(game);
	else if (key == KEY_S)
		move_player_s(game);
	else if (key == KEY_ESC || key == KEY_Q)
	{
		game->endgame = 1;
		endgame(game);
	}
	return (0);
}

int	red_cross(t_game *game)
{
	game->endgame = 1;
	endgame(game);
	return (0);
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_width * 32,
			game->map_height * 32, "So Long");
	img_init(game);
	draw_space(game);
	draw_assets(game);
	get_player_position(game);
	mlx_hook(game->win, 2, 0, &press_key, game);
	mlx_hook(game->win, 17, 0, &red_cross, (void *)game);
	mlx_loop(game->mlx);
}
