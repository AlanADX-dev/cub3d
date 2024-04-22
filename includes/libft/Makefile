NAME = libft.a

SRC = ft_strdup ft_putstr ft_substr ft_split ft_strlen ft_strncmp ft_atoi ft_calloc ft_bzero

SRCS = $(addsuffix .c, ${SRC})

OBJS = ${SRCS:.c=.o}

FLAG = -Wall -Wextra -Werror

.c.o:
	gcc ${FLAG} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
	ar rc $(NAME) ${OBJS}
	ranlib $(NAME)

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
