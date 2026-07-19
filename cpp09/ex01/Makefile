CPP = c++

NAME = RPN

FLAGS = -Wall -Wextra -Werror -std=c++98 

RM = rm -rf

SRC = main.cpp RPN.cpp

HEADER = RPN.hpp

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