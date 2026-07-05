CPP = c++

NAME = Array

FLAGS = -Wall -Wextra -Werror -std=c++98 

RM = rm -rf

SRC = main.cpp

HEADER = Array.hpp Array.tpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean