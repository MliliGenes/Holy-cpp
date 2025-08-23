NAME = ex02
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR = .
OBJDIR = obj
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

INCDIR = include
INCLUDES = -I$(INCDIR)

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
NC = \033[0m # No Color

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(BLUE)Linking $(NAME)...$(NC)"
	@$(CXX) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(NC)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@echo "$(BLUE)Compiling $<...$(NC)"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

re: fclean $(NAME)

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -rf $(OBJDIR)
	@echo "$(GREEN)✓ Object files cleaned!$(NC)"

fclean: clean
	@echo "$(RED)Cleaning executable...$(NC)"
	@rm -f $(NAME)
	@echo "$(GREEN)✓ Full clean completed!$(NC)"

.PHONY: all re clean fclean

help:
	@echo "Available targets:"
	@echo "  $(NAME)  - Build the executable"
	@echo "  all      - Build the executable (default)"
	@echo "  re       - Rebuild everything from scratch"
	@echo "  clean    - Remove object files"
	@echo "  fclean   - Remove object files and executable"
	@echo "  help     - Show this help message"
