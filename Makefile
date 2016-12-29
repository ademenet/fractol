CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = fdf

SOURCES =	main.c\
					fractals.c\
					mandelbrot.c

HEADERS = fdf.h

OBJECT = $(SOURCES:.c=.o)

$(NAME):
	@make --directory libft/
	@$(CC) $(FLAGS) -o fdf libft/libft.a $(SOURCES)

all: $(NAME)

clean:
	@rm -rf $(OBJECT)
	@make clean --directory libft/
	@echo "\033[1;34mFDF\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make fclean --directory libft/
	@echo "\033[1;34mFDF\t\033[1;33mCleaning\t\033[0;32m[OK]\033[0m"

re: fclean all

rr:
	$(CC) $(FLAGS) -o fdf libft/libft.a $(SOURCES) $(FRAMEWORK)

run:
	./$(NAME)

.PHONY: clean fclean
