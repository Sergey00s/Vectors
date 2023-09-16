NAME = libvector.a
SRCS = Vector.cpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -f
CXX = c++
all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)


%.o: %.cpp
	$(CXX) -c -o $@ $< 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re
