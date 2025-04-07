##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##

SRC = 	./src/main.c					\
	./src/check_error.c				\
	./src/map_display/project_point.c		\
	./src/map_display/get_point.c			\
	./src/map_display/draw_2d_map.c			\
	./src/map_display/draw_square.c			\
	./src/map_display/touch_square.c		\
	./src/map_display/display_texture.c		\
	./src/map_display/auto_complete.c		\
	./src/map/init_map.c				\
	./src/map/free_2d_map.c				\
	./src/map/init_2d_map.c				\
	./src/map/perlin.c				\
	./src/map/math_perlin_function.c		\
	./src/map/change_permutation.c			\
	./src/map/calc_angle.c				\
	./src/map/init_texture.c			\
	./src/button/display_button.c		\
	./src/button/free_button.c			\
	./src/button/get_button_event.c		\
	./src/button/init_button_evt.c		\
	./src/keyboard_manage/init_button.c		\
	./src/keyboard_manage/check_button.c		\
	./src/keyboard_manage/free_all_button.c		\
	./src/keyboard_manage/change_angle.c		\
	./src/keyboard_manage/change_pos.c		\
	./src/window_manage/event_manage.c		\
	./src/window_manage/init_window.c		\
	./src/window_manage/window_loop.c		\
	./src/window_manage/calc_scale.c		\
	./src/user_interact/create_circle.c		\
	./src/user_interact/init_mouse_interact.c	\
	./src/user_interact/mouse_interact.c		\
	./src/user_interact/play_thread_music.c		\
	./src/save_map/create_map_file.c		\
	./src/window_manage/init_sounds.c

NAME = my_world

CC	?=	gcc

CSFML = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CPPFLAGS = -W -Wall -iquote./include/

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my
	$(CC) -o $(NAME) $(OBJ) -L./lib/my -lmy -lm $(CSFML)

clean:
	make clean -C ./lib/my
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my

re: fclean all

help:
	@echo "Exemple of usage:\n"
	@echo "make:\t\t\tCreate the binary my_world"
	@echo "make clean:\t\tDelete every '*.o', created by 'make'"
	@echo "make fclean:\t\tDelete everything created by 'make'"
	@echo "make re:\t\tDo 'make fclean' instruction and 'make' after"
	@echo "make help:\t\tDisplay the compilation manual"

.PHONY: all clean fclean re help
