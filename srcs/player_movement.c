/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysarrar <aysarrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:54:14 by aysarrar          #+#    #+#             */
/*   Updated: 2022/01/09 18:12:33 by aysarrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	move_player_w(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] != '1')
    {
        img_draw(game, game->img_space, game->player_x, --game->player_y);
        img_draw(game, game->player_w, game->player_x, game->player_y);
        img_draw(game, game->img_space, game->player_x, game->player_y + 1);
        game->player_mouvement_counter++;
    	printf("%d\n", game->player_mouvement_counter);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->collected++;
		check_endgame(game);
		if (game->map[game->player_y][game->player_x] == 'E' && game->endgame)
			endgame(game);
    }
}

void	move_player_d(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] != '1')
	{
		img_draw(game, game->img_space, ++game->player_x, game->player_y);
		img_draw(game, game->player_d, game->player_x, game->player_y);
		img_draw(game, game->img_space, game->player_x - 1, game->player_y);
		game->player_mouvement_counter++;
		printf("%d\n", game->player_mouvement_counter);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->collected++;
		check_endgame(game);
		if (game->map[game->player_y][game->player_x] == 'E' && game->endgame)
			endgame(game);
	}
}

void	move_player_s(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] != '1')
	{
		img_draw(game, game->img_space, game->player_x, ++game->player_y);
		img_draw(game, game->player_s, game->player_x, game->player_y);
		img_draw(game, game->img_space, game->player_x, game->player_y - 1);
		game->player_mouvement_counter++;
		printf("%d\n", game->player_mouvement_counter);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->collected++;
		check_endgame(game);
		if (game->map[game->player_y][game->player_x] == 'E' && game->endgame)
			endgame(game);
	}
}

void	move_player_a(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] != '1')
	{
		img_draw(game, game->img_space, --game->player_x, game->player_y);
		img_draw(game, game->player_a, game->player_x, game->player_y);
		img_draw(game, game->img_space, game->player_x + 1, game->player_y);
		game->player_mouvement_counter++;
		printf("%d\n", game->player_mouvement_counter);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->collected++;
		check_endgame(game);
		if (game->map[game->player_y][game->player_x] == 'E' && game->endgame)
			endgame(game);
	}
}