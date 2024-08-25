CC = cc
CFLAGS = -Wall -Wextra -Werror
FOLDER = /Users/aohssine/42/test_git/pipex/pipex42
SRC = $(FOLDER)/main.c \
		$(FOLDER)/path.c \
		$(FOLDER)/exec.c \
		$(FOLDER)/ft_split.c   


RED = \033[0;31m
GREEN = \033[0;32m
END = \033[0m

OBJ = $(SRC:.c=.o)
NAME = pipex

all: $(NAME)

$(NAME) : $(OBJ) $(FOLDER)/header.h
	@echo "$(GREEN)pipex...$(END)"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)clean pipex $(END)"
	rm -fr $(OBJ)   

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY : clean