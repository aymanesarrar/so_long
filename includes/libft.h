/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../../includes/libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysarrar <aysarrar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:37:02 by aysarrar          #+#    #+#             */
/*   Updated: 2021/11/02 11:01:59 by aysarrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"
# define BUFFER_SIZE 1000
# define TRUE 1
# define FALSE 0

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_space;
	void	*img_collect;
	void	*img_player;
	void	*img_exit;
	void	*player_w;
	void	*player_s;
	void	*player_a;
	void	*player_d;
	char	**map;
	int		img_width;
	int		img_height;
	int		win_width;
	int		win_height;
	int		player_direction;
	int		player_x;
	int		player_y;
	int		collected;
	int		collectable;
	int		endgame;
	int		map_width;
	int		map_height;
}			t_game;
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strdel(char **adr_str);
void	join_bufto_str(char **str, void *buf);
char	*gnl(ssize_t readr, char **str_input);
char	*get_next_line(int fd);
int		check_valid_map(t_game *game);
int		check_rectangle(t_game *game);
char    **get_map(int fd);
int     check_extension(char *str);
int     check_map_valid_characters(t_game *game);
int     check_line_possible_characters(char *str);
int     check_possible_character(char c);
void    handle_errors();
void    initialize_struct(t_game *game);
void    game_init(t_game *game);
int		check_map_line_length(t_game *game);
void	img_init(t_game *game);
void	*img_initialize(char *img, t_game *game);
void	img_draw(t_game *game, void *img, int x, int y);
void	*free_2d(char **tab);
void    draw_assets(t_game *game);
int		check_assets(t_game *game);
int		check_map_ones(t_game *game);
int		check_starting_position(t_game *game);
#endif
