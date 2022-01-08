CC = gcc

CFLAGS= -Wall -Wextra -Werror 

NAME=libft.a

SRCS= ./ft_atoi.c ./ft_bzero.c ./ft_isalnum.c ./ft_isalpha.c ./ft_isdigit.c ./ft_isprint.c ./ft_memccpy.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memmove.c ./ft_memset.c ./ft_strchr.c ./ft_strlcat.c ./ft_strlcpy.c ./ft_strlen.c ./ft_strncmp.c ./ft_strnstr.c ./ft_strrchr.c ./ft_tolower.c ./ft_toupper.c ./ft_isascii.c ./ft_calloc.c ./ft_strdup.c ./ft_substr.c ./ft_strjoin.c ./ft_strtrim.c ./ft_split.c ./ft_itoa.c ./ft_strmapi.c ./ft_putchar_fd.c ./ft_putstr_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c  

OBJS= $(SRCS:.c=.o)

Bonus_OBJS= $(Bonus:.c=.o)

Bonus= ./ft_lstnew.c ./ft_lstadd_front.c ./ft_lstsize.c ./ft_lstadd_back.c ./ft_lstlast.c ./ft_lstdelone.c ./ft_lstclear.c ./ft_lstiter.c ./ft_lstmap.c 

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(Bonus_OBJS)
	@ar -rcs $(NAME) $(OBJS) $(Bonus_OBJS)

$(OBJS): 
	@$(CC) $(CFLAGS) -c $(SRCS)

$(Bonus_OBJS):
	@$(CC) $(CFLAGS) -c $(Bonus)

clean: 
	@rm -f $(OBJS) $(Bonus_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
