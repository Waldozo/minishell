
SOURCE = minishell.c utils.c parsing.c parsing_pipe.c parsing_redir.c \
parsing_quote.c path.c utils2.c special_tokens.c handle.c word_quote.c
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