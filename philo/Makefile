NAME	= philo

CC		= cc
FLAGS	= -Wall -Wextra -Werror -g3

INCLUDE	= -I.

SRC		= $(addprefix src/, philo.c initializer.c waiter.c error.c \
							utils.c dinner.c actions.c peek_i.c peek_ii.c)
OBJ		= $(SRC:src/%.c=obj/%.o)

BLU		= \033[1;36m
WHT		= \033[1;39m
DFL		= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLU) Compiling...$(DFL)"
	@$(CC) $(FLAGS) $(OBJ) $(INCLUDE) -lpthread -o $(NAME)
	@echo "$(BLU) All set up!\n $(WHT)Run: ./philo [nº of philos] [time to die] [time to eat] [time to sleep] [nº of meals (optional)]$(DFL)"

obj/%.o:src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

test: $(NAME)
	@echo "$(WHT) \nRunning three tests:\n - Lonely philo\n - 4 philos, 1 death\n - No death, 7 meals\n$(DFL)"
	./philo 1 800 200 200
	./philo 4 310 200 100
	./philo 5 800 200 200 7

clean:
	@rm -rf obj/
	@echo "$(BLU) All objects were deleted.$(DFL)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLU) Binary deleted.$(DFL)"

re: fclean all

.PHONY: all clean fclean re
