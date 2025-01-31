NAME = Bureaucrat

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR = ./src/

SRC_FILES = main.cpp\
			Bureaucrat.cpp\
			Form.cpp

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

INC = -Iinclude/

OBJ_DIR = .obj/

OBJ = $(SRC:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

RM = rm -rf

all:
	@if [ ! -f $(NAME) ] || [ `find $(OBJ) -newer $(NAME) | wc -l` -ne 0 ]; then \
		make --no-print-directory $(NAME); \
		printf "$(ERASE)$(GREEN)Program$(RESET) $(CYAN)$(BOLD)$(NAME)$(RESET) $(GREEN)created!\n$(RESET)"; \
	else \
		printf "$(ERASE)$(YELLOW)No relink needed for$(RESET) $(CYAN)$(BOLD)$(NAME)\n$(RESET)"; \
	fi

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME);

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@printf "$(ERASE)$(BLUE) > Compilation: $(RESET) $<"

clean:
	@printf "$(ERASE)$(GREEN)Cleaning up...$(RESET)"
	@$(RM) ./.obj/
	@printf "$(ERASE)$(GREEN)Clean finished!\n$(RESET)"

fclean: clean
	@printf "$(ERASE)$(GREEN)Fcleaning up...$(RESET)"
	@$(RM) ${NAME}
	@printf "$(ERASE)$(GREEN)Fclean finished!\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re
.SILENT:

# COLORS
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
BOLD = \033[1m
ERASE = \033[2K\r
RESET = \033[0m
