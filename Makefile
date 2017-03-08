CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = fractol

SOURCES =	main.c\
			images.c\
			mandelbrot.c\
			julia.c\
			burningship.c\
			hooks.c

HEADERS = fractol.h

LIBS = libft/libft.a libft/ft_printf/libftprintf.a

OBJECT = $(SOURCES:.c=.o)

FRAMEWORK = minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

$(NAME):
	@make --directory libft/
	@make --directory minilibx_macos/
	@$(CC) $(FLAGS) -o fractol $(LIBS) $(SOURCES) $(FRAMEWORK)

all: $(NAME)

clean:
	@rm -rf $(OBJECT)
	@make clean --directory libft/
	@make clean --directory minilibx_macos/
	@echo "\033[1;34mFractol\t\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make fclean --directory libft/
	@make clean --directory minilibx_macos/
	@echo "\033[1;34mFractol\t\t\033[1;33mCleaning\t\033[0;32m[OK]\033[0m"

re: fclean all

rr:
	$(CC) $(FLAGS) -o fractol $(LIBS) $(SOURCES) $(FRAMEWORK)

run:
	./$(NAME)

.PHONY: clean fclean
