CXX = c++

NAME = PmergeMe

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 

RM = rm -rf

SRC = main.cpp PmergeMe.cpp

HEADER = RPN.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean