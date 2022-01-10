/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysarrar <aysarrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:39:35 by aysarrar          #+#    #+#             */
/*   Updated: 2022/01/10 11:10:14 by aysarrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*img_initialize(char *img, t_game *game)
{
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image(game->mlx,
			img, &(game->img_width), &(game->img_height));
	if (!img_ptr)
		handle_errors();
	return (img_ptr);
}

void	img_draw(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 32, y * 32);
}

void	img_init(t_game *game)
{
	game->player_w = img_initialize("assets/player/PLAYER_W.xpm", game);
	game->player_a = img_initialize("assets/player/PLAYER_A.xpm", game);
	game->player_s = img_initialize("assets/player/PLAYER_S.xpm", game);
	game->player_d = img_initialize("assets/player/PLAYER_D.xpm", game);
	game->img_exit = img_initialize("assets/Door01.xpm", game);
	game->img_player = img_initialize("assets/player/PLAYER.xpm", game);
	game->img_collect = img_initialize("assets/food.xpm", game);
	game->img_space = img_initialize("assets/space.xpm", game);
	game->img_wall = img_initialize("assets/brick.xpm", game);
}
