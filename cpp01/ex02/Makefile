NAME     = ex02
SRCS     = main.cpp
OBJDIR   = obj
OBJS     = $(SRCS:%.cpp=$(OBJDIR)/%.o)

CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

GREEN_WHITE = \033[1;32;47m
BLUE     = \033[0;34m
CYAN     = \033[0;36m
RED      = \033[0;31m
RESET    = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN_WHITE)💣 ./$(NAME) is ready to be executed!!💣$(RESET)"

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@echo "$(BLUE)🔨...Compiling $<... 🔨$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@echo "$(CYAN)🧹...Cleaning object files... 🧹$(RESET)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(CYAN)🧹...Cleaning $(NAME)... 🧹$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
