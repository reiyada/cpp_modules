# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryada <ryada@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 17:18:35 by ryada             #+#    #+#              #
#    Updated: 2025/08/06 09:55:33 by ryada            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
#                                 Configuration                                #
# ---------------------------------------------------------------------------- #
NAME      = ex01
CXX       = c++
CXXFLAGS  = -Wall -Wextra -Werror -std=c++98 -g -o -I$(INC_DIR)

SRC_DIR   = srcs
INC_DIR   = includes
OBJ_DIR   = obj

SRCS      = $(wildcard $(SRC_DIR)/*.cpp)
OBJS      = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# ---------------------------------------------------------------------------- #
#                                     Color                                    #
# ---------------------------------------------------------------------------- #
GREEN_WHITE = \033[1;32;47m
BLUE     = \033[0;34m
CYAN     = \033[0;36m
RED      = \033[0;31m
RESET    = \033[0m

# ---------------------------------------------------------------------------- #
#                                     Rules                                    #
# ---------------------------------------------------------------------------- #
all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "$(GREEN_WHITE)💣 Build complete! Run ./$(NAME) 💣$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(CYAN)🧹 Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(CYAN)🧹 Removing executable...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re