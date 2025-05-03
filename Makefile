
SOURCE = minishell.c utils.c parsing.c
OBJ = ${SOURCE:.c=.o}
CC = cc
NAME = minishell
CFLAGS = -Wall -Wextra -Werror 


all : $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@ -lreadline

clean:
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re