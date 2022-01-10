/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysarrar <aysarrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:40:22 by aysarrar          #+#    #+#             */
/*   Updated: 2022/01/10 18:05:27 by aysarrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	initialize_struct(t_game *game)
{
	game->win_width = 0;
	game->win_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->player_mouvement_counter = 0;
	game->collectable = collectible_count(game);
	game->collected = 0;
	game->endgame = 0;
	game->map_width = 0;
	game->map_height = 0;
}

void	launch(char *filename)
{
	int		fd;
	t_game	game;

	if (!check_extension(filename))
		handle_errors();
	else
	{
		fd = open(filename, O_RDONLY);
		game.map = get_map(fd);
		if (!game.map)
			handle_errors();
		if (check_valid_map(&game))
			game_init(&game);
		else
		{
			free_2d(game.map);
			handle_errors();
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		launch(av[1]);
	else
		printf("Error: invalid arguments\n");
}
