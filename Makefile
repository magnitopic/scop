# SCOP
NAME			=	scop

SCOP_SRC		=	src/main.cpp \
					src/scop.cpp

OBJS			=	$(SCOP_SRC:.cpp=.o)

# Compiler
CXX				=	g++
RM				=	rm -f
CXXFLAGS		=	-Wall -Werror -Wextra -std=c++11 -DGL_SILENCE_DEPRECATION

# GLFW paths (Homebrew on macOS)
GLFW_PATH		=	/opt/homebrew/opt/glfw
INCLUDES		=	-I$(GLFW_PATH)/include
EXTRAFLAGS		=	-L$(GLFW_PATH)/lib -lglfw -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

# Colours
RED				=	\033[0;31m
GREEN			=	\033[0;32m
YELLOW			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
WHITE			=	\033[0;37m
RESET			=	\033[0m

# Rules
all:			$(NAME)
				@printf "$(BLUE)==> $(CYAN)SCOP compiled ✅\n\n$(RESET)"

$(NAME):		$(OBJS)
				@$(CXX) $(CXXFLAGS) $(OBJS) $(EXTRAFLAGS) -o $(NAME)

%.o: %.cpp
				@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
				@$(RM) $(OBJS)
				@printf "\n$(BLUE)==> $(RED)Removed SCOP objects 🗑️\n$(RESET)"

fclean:			clean
				@$(RM) $(NAME)
				@printf "$(BLUE)==> $(RED)Removed SCOP executable 🗑️\n$(RESET)"

re:				fclean all
				@printf "$(BLUE)==> $(CYAN)SCOP recompiled 🔄\n$(RESET)"

.PHONY:			all clean fclean re
