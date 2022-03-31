NAME = push_swap

PUSH_SWAP = ./libft/ft_isalpha.c ./libft/ft_isdigit.c ./libft/ft_isalnum.c ./libft/ft_isascii.c ./libft/ft_isprint.c \
./libft/ft_strlen.c ./libft/ft_memset.c ./libft/ft_bzero.c ./libft/ft_memcpy.c ./libft/ft_memmove.c ./libft/ft_strlcpy.c \
./libft/ft_strlcat.c ./libft/ft_toupper.c ./libft/ft_tolower.c ./libft/ft_strchr.c ./libft/ft_strrchr.c ./libft/ft_strncmp.c \
./libft/ft_memchr.c ./libft/ft_memcmp.c ./libft/ft_strnstr.c ./libft/ft_atoi.c ./libft/ft_calloc.c ./libft/ft_strdup.c \
./libft/ft_substr.c ./libft/ft_strjoin.c ./libft/ft_strtrim.c ./libft/ft_split.c ./libft/ft_itoa.c ./libft/ft_strmapi.c \
./libft/ft_striteri.c ./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c ./libft/ft_putendl_fd.c \
./libft/ft_lstnew_bonus.c ./libft/ft_lstadd_front_bonus.c ./libft/ft_lstsize_bonus.c ./libft/ft_lstlast_bonus.c \
./libft/ft_lstadd_back_bonus.c ./libft/ft_lstdelone_bonus.c ./libft/ft_lstclear_bonus.c ./libft/ft_lstiter_bonus.c \
./libft/ft_putnbr_fd.c\
\
./checkers/ft_first_check.c ./checkers/ft_check_dubs.c ./checkers/ft_sort_check.c\
\
./main_funcs/ft_push.c ./main_funcs/ft_swap.c ./main_funcs/rotate.c ./main_funcs/rev_rotate.c \
\
main.c ft_output.c ft_sort_three_one_stack.c ft_sort.c\

OBJS  = ${PUSH_SWAP:.c=.o}
DEPS  = ${PUSH_SWAP:.c=.d}
CC   = gcc -g -Wall -Wextra -Werror -MMD

all:  $(NAME)

-include $(DEPS)

.c.o :
	$(CC) -c $< -o ${<:.c=.o} -I.

$(NAME): ${OBJS} Makefile
	$(CC) ${OBJS} -o $(NAME) 

bonus: $(NAME)

clean:
	rm -f ${OBJS}
	rm -f ${DEPS}

fclean: clean
	rm -f $(NAME)

re :  fclean all

.PHONY:  all clean fclean re .c.o bonus