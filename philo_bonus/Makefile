NAME	= philo_bonus

CC		= cc
FLAGS	= -Wall -Wextra -Werror -g3

INCLUDE	= -I.

SRC		= $(addprefix src/, philo.c initializer.c dinner.c actions.c \
							utils.c error.c)

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

clean:
	@rm -rf obj/
	@echo "$(BLU) All objects were deleted.$(DFL)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLU) Binary deleted.$(DFL)"

re: fclean all

.PHONY: all clean fclean re
