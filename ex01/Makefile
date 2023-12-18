SRCS		=	main.cpp contact.cpp phonebook.cpp

OBJS		=	${SRCS:.cpp=.o}

CXX			=	c++

CPPFLAGS	=	-std=c++98 -Wall -Wextra -Werror

NAME		=	phonebook

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re		:	fclean all
