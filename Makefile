NAME = minishell
LIBFT = Libft
SRC = src/main.c src/envset.c src/makeprompt.c src/sigdefine.c
CC = gcc
FLAGS = -pthread
RM = rm -f

$(NAME) : $(SRC) $(LIBFT)
	@make bonus -C $(LIBFT)
	@echo "\033[32m"Making LIBFT..."\033[0m"
	@$(CC) $(FLAGS) $(SRC) -L$(LIBFT) -lft -lreadline -o $(NAME)
	@echo "\033[32m"Making minishell..."\033[0m"

all: $(NAME)

fclean : clean
	@$(RM) $(NAME)
	@echo "\033[31m"clean minishell..."\033[0m"
	@make fclean -C $(LIBFT)
	@echo "\033[31m"fclean libft..."\033[0m"

clean :
	@make clean -C $(LIBFT)
	@echo "\033[31m"clean libft..."\033[0m"

re : fclean all

