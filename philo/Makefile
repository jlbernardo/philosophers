NAME	= philo

CC		= cc
FLAGS	= -Wall -Wextra -Werror -g3

INCLUDE	= -I

SRC		= $(addprefix src/, philo.c initializer.c checker.c error.c)
OBJ		= $(SRC:src/%.c=obj/%.o)

BLU		= \033[1;36m
WHT		= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(INCLUDE) -o $(NAME)
	@echo "$(BLU) All set up!\n Run: ./philo (nbr of philos) (time to die) (time to eat) (time to sleep) (nbr of meals, optional)$(WHT)"

/obj%.o:src/%.c
	@echo "$(BLU) Compiling...$(WHT)"
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf obj/
	@echo "$(BLU) All objects were deleted.$(WHT)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLU) Binary deleted.$(WHT)"

re: fclean all

.PHONY: all clean fclean re
