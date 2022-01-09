/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysarrar <aysarrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:40:22 by aysarrar          #+#    #+#             */
/*   Updated: 2022/01/09 18:21:30 by aysarrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int main(int ac, char **av)
{
    if (ac == 2)
        launch(av[1]);
    else
        printf("Error: invalid arguments\n");
}