NAME = CIH

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Account.cpp tests.cpp

HEADERS = Account.hpp

OBJ = $(SRC:.cpp=.o)

RM = rm -fr

all: $(NAME)

$(NAME): $(OBJ) 
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean