/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysarrar <aysarrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:33:15 by aysarrar          #+#    #+#             */
/*   Updated: 2022/01/07 11:41:50 by aysarrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void    handle_errors()
{
    printf("Error\n");
    exit(EXIT_FAILURE);
}

int     check_possible_character(char c)
{
    if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
        return (TRUE);
    return (FALSE);
}

int     check_line_possible_characters(char *str)
{
    int index;

    index = 0;
    while (str[index])
    {
        if (!check_possible_character(str[index]))
            return (FALSE);
        index++;
    }
    return (TRUE);
}

int     check_map_valid_characters(t_game *game)
{
    int index;

    index = 0;
    while (game->map[index])
    {
        if (!check_line_possible_characters(game->map[index]))
            return (FALSE);
        index++;
    }
    return (TRUE);
}

int     check_extension(char *str)
{
    int		index;
    size_t	jndex;
    char    *extension;

    index = 0;
    extension = ".ber";
    while (str[index])
        index++;
    index--;
    jndex = 0;
    while (index > 0 && str[index] != '.')
	{
		if (ft_strchr(extension,  str[index]) && extension[jndex])
			jndex++;
		else
			break;
		index--;
	}
	if (ft_strchr(extension,  str[index]) && extension[jndex])
		jndex++;
    return (jndex == ft_strlen(extension));
}

