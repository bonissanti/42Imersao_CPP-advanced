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
INCLUDES = account.hpp bank.hpp
OBJDIR = obj
OBJ = $(OBJDIR)/account.o $(OBJDIR)/bank.o $(OBJDIR)/bank_utils.o $(OBJDIR)/main.o

################################# Rules ####################################

all: dir ex00

dir:
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp $(INCLUDES)
	@$(CC) -c -o $@ $< $(CFLAGS) 
	@echo "$(GREEN)Compiled:$(RESET) $<"

ex00: $(OBJ)
	@$(CC) -o $@ $^ $(CFLAGS)

################################# Clean ####################################

clean:
	@rm -rf $(OBJDIR)
	@echo "$(RED)Removed:$(RESET) $(OBJDIR)"

fclean: clean
	@rm -f ex00
	@echo "$(RED)Removed:$(RESET) ex00"

re: fclean all

.PHONY: all clean fclean re
