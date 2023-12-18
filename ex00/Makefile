NAME= megaphone

CXXFLAGS= -Wall -Wextra -Werror -std=c++98

SRC= megaphone.cpp

CXX= c++

OBJ= $(SRC:.cpp=.o)

all: $(NAME)


$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all
