/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysarrar <aysarrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:40:22 by aysarrar          #+#    #+#             */
/*   Updated: 2022/01/08 16:13:41 by aysarrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void    draw_assets(t_game *game)
{
       int  x;
       int  y;

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

void    draw_space(t_game *game)
{
         int  x;
         int  y;
    
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

int press_key(int key, t_game *game)
{
    if (key == KEY_D)
    {
        if (game->map[game->player_y][game->player_x + 1] != '1')
        {
            img_draw(game, game->img_space, ++game->player_x, game->player_y);
            img_draw(game, game->player_d, game->player_x, game->player_y);
            img_draw(game, game->img_space, game->player_x - 1, game->player_y);
            game->player_mouvement_counter++;
            printf("%d\n", game->player_mouvement_counter);
        }
    }
    else if (key == KEY_A)
    {
        if (game->map[game->player_y][game->player_x - 1] != '1')
        {
            img_draw(game, game->img_space, --game->player_x, game->player_y);
            img_draw(game, game->player_a, game->player_x, game->player_y);
            img_draw(game, game->img_space, game->player_x + 1, game->player_y);
            game->player_mouvement_counter++;
            printf("%d\n", game->player_mouvement_counter);
        }
    }
    else if (key == KEY_W)
    {
        if (game->map[game->player_y - 1][game->player_x] != '1')
        {
            img_draw(game, game->img_space, game->player_x, --game->player_y);
            img_draw(game, game->player_w, game->player_x, game->player_y);
            img_draw(game, game->img_space, game->player_x, game->player_y + 1);
            game->player_mouvement_counter++;
            printf("%d\n", game->player_mouvement_counter);
        }
    }
    else if (key == KEY_S)
    {
        if (game->map[game->player_y + 1][game->player_x] != '1')
        {
            img_draw(game, game->img_space, game->player_x, ++game->player_y);
            img_draw(game, game->player_s, game->player_x, game->player_y);
            img_draw(game, game->img_space, game->player_x, game->player_y - 1);
            game->player_mouvement_counter++;
            printf("%d\n", game->player_mouvement_counter);
        }
    }
    return 0;
}

void    game_init(t_game *game)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->map_width * 32, game->map_height * 32, "Filler");
    img_init(game);
    draw_space(game);
    draw_assets(game);
    get_player_position(game);
    mlx_hook(game->win, 2, 0, press_key, game);
    mlx_loop(game->mlx);
}

void    initialize_struct(t_game *game)
{
    game->win_width = 0;
    game->win_height = 0;
    game->player_x = 0;
    game->player_y = 0;
    game->player_mouvement_counter = 0;
    game->collectable = 0;
    game->collected = 0;
    game->endgame = 0;
    game->map_width = 0;
    game->map_height = 0;
}

void    launch(char *filename)
{
        int     fd;
        t_game  game;

        if (!check_extension(filename))
            handle_errors();
        else
        {
            fd = open(filename, O_RDONLY);
            game.map = get_map(fd);
            if (check_valid_map(&game))
                game_init(&game);
            else
            {
                free_2d(game.map);
                handle_errors();
            }
        }
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        launch(av[1]);
    }
    else
        printf("Error: invalid arguments\n");
}