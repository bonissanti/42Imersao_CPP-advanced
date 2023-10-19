#--------------------------- Makefile for C++ -----------------------------#    
################################ Colors ####################################    

RED      = \033[1;31m
GREEN    = \033[1;32m
YELLOW   = \033[1;33m
BLUE     = \033[1;34m
RESET    = \033[0m

################################ Constants ##################################

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g
INCLUDES = graph.hpp
OBJDIR = obj
OBJ = $(OBJDIR)/graph.o $(OBJDIR)/main.o

################################# Rules ####################################

all: dir ex01

dir:
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp $(INCLUDES)
	@$(CC) -c -o $@ $< $(CFLAGS) 
	@echo "$(GREEN)Compiled:$(RESET) $<"

ex01: $(OBJ)
	@$(CC) -o $@ $^ $(CFLAGS)

################################# Clean ####################################

clean:
	@rm -rf $(OBJDIR)
	@echo "$(RED)Removed:$(RESET) $(OBJDIR)"

fclean: clean
	@rm -f ex01
	@echo "$(RED)Removed:$(RESET) ex01"

re: fclean all

.PHONY: all clean fclean re
