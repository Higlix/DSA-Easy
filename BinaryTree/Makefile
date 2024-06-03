NAME = trees
SRC += main.c utils.c
OBJ += $(SRC:%.c=%.o)

CC = gcc -g
#CFLAGS = -Wall -Werror -Wextra 
CFLAGS=

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)
	@mkdir -p OBJ
	@mv *.o OBJ

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

src: clean all

clean:
	rm -rf $(OBJ)
	rm -rf OBJ

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re