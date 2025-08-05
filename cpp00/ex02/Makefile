# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryada <ryada@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 15:33:11 by ryada             #+#    #+#              #
#    Updated: 2025/08/05 15:33:13 by ryada            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
#                                 Configuration                                #
# ---------------------------------------------------------------------------- #
NAME      = Account
CXX       = c++
CXXFLAGS  = -Wall -Wextra -Werror -std=c++98 -g

SRC_FILES = Account.cpp tests.cpp
OBJ_DIR   = obj
OBJS      = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES:.cpp=.o)))

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

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(CYAN)🧹 Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(CYAN)🧹 Removing executable...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
