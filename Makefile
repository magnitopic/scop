# SCOP
NAME			=	scop

SCOP_SRC		=	src/main.cpp \
					src/Object.cpp \
					src/glad.c \
					src/aux/loadShaderSource.cpp \
					src/scop.cpp

OBJS			=	$(SCOP_SRC:.cpp=.o)
OBJS			:=	$(OBJS:.c=.o)

# Compiler
CXX				=	g++
CC				=	gcc
RM				=	rm -f
CXXFLAGS		=	-Wall -Werror -Wextra -std=c++11 -DGL_SILENCE_DEPRECATION

# Platform detection
UNAME			:=	$(shell uname)

ifeq ($(UNAME), Darwin)
# macOS (Homebrew)
INCLUDES		=	-I./include -I/opt/homebrew/opt/glfw/include
EXTRAFLAGS		=	-L/opt/homebrew/opt/glfw/lib -lglfw -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
else
# Linux
INCLUDES		=	-I./include
EXTRAFLAGS		=	-lglfw -lGL -ldl -lpthread -lm
endif



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

%.o: %.c
				@$(CC) $(INCLUDES) -c $< -o $@

clean:
				@$(RM) $(OBJS)
				@printf "\n$(BLUE)==> $(RED)Removed SCOP objects 🗑️\n$(RESET)"

fclean:			clean
				@$(RM) $(NAME)
				@printf "$(BLUE)==> $(RED)Removed SCOP executable 🗑️\n$(RESET)"

re:				fclean all
				@printf "$(BLUE)==> $(CYAN)SCOP recompiled 🔄\n$(RESET)"

.PHONY:			all clean fclean re
