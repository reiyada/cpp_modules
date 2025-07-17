NAME     = megaphone
SRCS     = megaphone.cpp
OBJDIR   = obj
OBJS     = $(SRCS:.cpp=.o)
OBJS     := $(addprefix $(OBJDIR)/, $(notdir $(OBJS)))
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -o 

GREEN_WHITE = \033[1;32;47m
BLUE     = \033[0;34m
CYAN     = \033[0;36m
RED      = \033[0;31m
RESET    = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@echo "$(BLUE)🔨...Compiling $(NAME)... 🔨$(RESET)"
	@echo "$(GREEN_WHITE)💣 ./$(NAME) is ready to be executed!!💣$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@echo "$(CYAN)🧹...Cleaning object files... 🧹$(RESET) "
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(CYAN)🧹...Cleaning $(NAME)... 🧹$(RESET) "
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
