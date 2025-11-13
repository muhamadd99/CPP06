CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Serialization

INC = Data.hpp \
		Serialize.hpp

SRC = main.cpp \
		Serialize.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(INC)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re