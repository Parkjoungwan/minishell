NAME = minishell
LIBFT = Libft
SRC = src/argumentscheck_utils.c \
	src/argumentscheck.c \
	src/builtin_cd.c \
	src/builtin_echo.c \
	src/builtin_env.c \
	src/builtin_export.c \
	src/builtin_pwd.c \
	src/builtin_unset.c \
	src/builtin.c \
	src/check_builtin.c \
	src/cutbytokens.c \
	src/delentry.c \
	src/document.c \
	src/envset_util.c \
	src/envset.c \
	src/envsort.c \
	src/error.c \
	src/execute.c \
	src/exit_here.c \
	src/exit.c \
	src/expand_env_utils.c \
	src/expand_env.c \
	src/files.c \
	src/initpipes.c \
	src/inputscan.c \
	src/insertspace.c \
	src/main.c \
	src/makecmdlst.c \
	src/makeprompt.c \
	src/pipeexec.c \
	src/redirect.c \
	src/sigdefine.c \
	src/sigdefine2.c
	
CC = gcc
FLAGS = -pthread
RM = rm -f

RL= -L/opt/homebrew/opt/readline/lib \
	-I/opt/homebrew/opt/readline/include
##	-L /Users/khee-seo/.brew/opt/readline/lib \
##	-I /Users/khee-seo/.brew/opt/readline/include

$(NAME) : $(SRC) $(LIBFT)
	@make bonus -C $(LIBFT)
	@echo "\033[32m"Making LIBFT..."\033[0m"
	@$(CC) $(FLAGS) $(SRC) -L$(LIBFT) -lft -lreadline -o $(NAME) $(RL)
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