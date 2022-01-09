MAIN=so_long
NAME=libft.a
CC=gcc
CCFLAGS= -Wall -Wextra -Werror
MAINSRC=srcs/main.c
SRCS = ft_atoi.c \
       ft_bzero.c \
	ft_calloc.c \
       ft_itoa.c \
       ft_isalnum.c \
       ft_isalpha.c \
       ft_isascii.c \
       ft_isdigit.c \
       ft_isprint.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_memset.c \
       ft_putchar_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c \
       ft_putstr_fd.c \
       ft_split.c \
       ft_strchr.c \
       ft_strdup.c \
       ft_strjoin.c \
       ft_strlcat.c \
       ft_strlcpy.c \
       ft_strlen.c \
       ft_strmapi.c \
       ft_strncmp.c \
       ft_strnstr.c \
       ft_strrchr.c \
       ft_strtrim.c \
       ft_substr.c \
       ft_tolower.c \
       ft_toupper.c \
       ft_striteri.c \
       get_next_line.c \
       get_next_line_utils.c \
       map_validation.c \
       map_validation2.c \
       img_init.c \
       utils.c \
       game.c \
       endgame.c \
       player_movement.c

BONUS_SRCS = ft_lstadd_back.c \
	   ft_lstadd_front.c \
	   ft_lstclear.c \
	   ft_lstdelone.c \
	   ft_lstiter.c \
	   ft_lstlast.c \
	   ft_lstmap.c \
	   ft_lstnew.c \
	   ft_lstsize.c \

OBJS = srcs/libft/ft_atoi.o \
       srcs/libft/ft_bzero.o \
	srcs/libft/ft_calloc.o \
       srcs/libft/ft_itoa.o \
       srcs/libft/ft_isalnum.o \
       srcs/libft/ft_isalpha.o \
       srcs/libft/ft_isascii.o \
       srcs/libft/ft_isdigit.o \
       srcs/libft/ft_isprint.o \
       srcs/libft/ft_memchr.o \
       srcs/libft/ft_memcmp.o \
       srcs/libft/ft_memcpy.o \
       srcs/libft/ft_memmove.o \
       srcs/libft/ft_memset.o \
       srcs/libft/ft_putchar_fd.o \
       srcs/libft/ft_putendl_fd.o \
       srcs/libft/ft_putnbr_fd.o \
       srcs/libft/ft_putstr_fd.o \
       srcs/libft/ft_split.o \
       srcs/libft/ft_strchr.o \
       srcs/libft/ft_strdup.o \
       srcs/libft/ft_strjoin.o \
       srcs/libft/ft_strlcat.o \
       srcs/libft/ft_strlcpy.o \
       srcs/libft/ft_strlen.o \
       srcs/libft/ft_strmapi.o \
       srcs/libft/ft_strncmp.o \
       srcs/libft/ft_strnstr.o \
       srcs/libft/ft_strrchr.o \
       srcs/libft/ft_strtrim.o \
       srcs/libft/ft_substr.o \
       srcs/libft/ft_tolower.o \
       srcs/libft/ft_toupper.o \
       srcs/libft/ft_striteri.o \
       srcs/libft/get_next_line.o \
       srcs/libft/get_next_line_utils.o \
       srcs/map_validation.o \
       srcs/map_validation2.o \
       srcs/img_init.o \
       srcs/utils.o \
       srcs/game.o \
       srcs/endgame.o \
       srcs/player_movement.o

RM = rm -rf

.c.o:	
			${CC} ${CCFLAGS} -c $<

all:		${MAIN}
              
$(MAIN):	${NAME}
			${CC} -lmlx -framework OpenGL -framework AppKit $(MAINSRC) $(NAME) -o $(MAIN)

$(NAME):	${OBJS}
			ar rcs ${NAME} ${SRCS:.c=.o}

bonus: 		${OBJS} ${BONUS_OBJS}
			ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

clean:
			${RM} ${SRCS:.c=.o} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME} $(MAIN)

re:			fclean all