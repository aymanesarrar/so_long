/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysarrar <aysarrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:34:38 by aysarrar          #+#    #+#             */
/*   Updated: 2022/01/09 19:55:16 by aysarrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
//testtt
char    **get_map(int fd)
{
    char    *full_map;
    char    *str;
    char    **map;

    if (fd < 0)
        return (NULL);
    str = get_next_line(fd);
    if (!str)
        return (NULL);
    full_map = NULL;
    while (str)
    {
        if (!full_map)
            full_map = ft_strdup(str);
        else
            join_bufto_str(&full_map, str);
        free(str);
        str = get_next_line(fd);
    }
    free(str);
    map = ft_split(full_map, '\n');
    if (!map)
        return (NULL);
    return (map);
}

int check_rectangle(t_game *game)
{
    while (game->map[game->map_height])
        game->map_height++;
    game->map_width = ft_strlen(game->map[0]);
    return (game->map_width > game->map_height);
}

int check_valid_map(t_game *game)
{
	initialize_struct(game);
    if (game->map == NULL)
        return (FALSE);
    if (check_rectangle(game))
        if (check_map_valid_characters(game))
            if (check_map_line_length(game))
                if (check_assets(game))
                    if (check_map_ones(game))
                        if (check_starting_position(game))
                            return (TRUE);
    return (FALSE);
}

int check_map_line_length(t_game *game)
{
    int index;

    index = 0;
    while (game->map[index])
    {
        if (ft_strlen(game->map[index]) != (size_t)game->map_width)
            return (FALSE);
        index++;
    }
    return (TRUE);
}

int check_assets(t_game *game)
{
    int index;
    int count;

    index = 0;
    count = 0;
    while (game->map[index])
    {
        if (ft_strchr(game->map[index], 'C'))
            count++;
        if (ft_strchr(game->map[index], 'E'))
            count++;
        if (ft_strchr(game->map[index], 'P'))
            count++;
        index++;
    }
    return (count >= 3);
}