CPP = c++

NAME = Animal

FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRC = main.cpp AAnimal.cpp Cat.cpp Dog.cpp Brain.cpp WrongCat.cpp WrongAnimal.cpp

HEADER =  AAnimal.hpp Cat.hpp Dog.hpp Brain.hpp WrongCat.hpp WrongAnimal.hpp

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