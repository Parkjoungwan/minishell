NAME = minishell
LIBFT = ./Libft
RDLIB = /usr/local/opt/readline/lib/
RDHEAD = /usr/local/opt/readline/include
SRC = src/main.c src/envset.c src/makeprompt.c src/sigdefine.c Libft/ft_calloc.c Libft/ft_lstadd_back.c Libft/ft_lstnew.c Libft/ft_memcpy.c Libft/ft_strlcat.c Libft/ft_strlen.c Libft/ft_strncmp.c Libft/ft_memset.c Libft/ft_lstlast.c src/exit.c src/inputscan.c src/insertspace.c Libft/ft_strjoin.c Libft/ft_strdup.c Libft/ft_substr.c Libft/ft_strchr.c Libft/ft_isalnum.c Libft/ft_strtrim.c
CC = gcc
FLAGS = -pthread -lreadline -Wall -Wextra -Werror
RM = rm -f

$(NAME) : $(SRC) $(LIBFT)
	$(CC) $(FLAGS) $(SRC) -L$(RDLIB) -I$(RDHEAD) -o $(NAME)
	@echo "\033[32m"Making minishell..."\033[0m"

all: $(NAME)

fclean : clean
	@$(RM) $(NAME)
	@echo "\033[31m"fclean libft..."\033[0m"

clean :
	@echo "\033[31m"clean..."\033[0m"

re : fclean all

