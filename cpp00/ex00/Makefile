NAME = megaphone

CPP = c++ 

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp 

OBJ = $(SRC:.cpp=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ) 
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp 
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY: clean