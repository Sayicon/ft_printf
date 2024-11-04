CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = $(filter-out ./files/main_test.c, $(wildcard ./files/*.c))
OBJS = $(SRCS:.c=.o)

LIBS = -L./libft -lft
LIBFT_OBJS = $(filter-out ./libft/main_test.o, $(wildcard ./libft/*.o))

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJS)
	make clean -C ./libft

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

test: $(OBJS)
	make -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) ./files/main_test.c -o program $(LIBS)
	@echo Derleme Tamamlandı

.PHONY : all clean fclean re bonus test info

info:
	@echo
	@echo "	 [info | all | bonus | clean | fclean | re | test]"
	@echo
	@echo "		info: displays informations"
	@echo "		all: compile the library"
	@echo "		clean: remove object files"
	@echo "		fclean: remove object files and archive library"
	@echo "		re: fclean and all"
	@echo "		test: create the test program"