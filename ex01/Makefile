NAME		= ex01.out
CXX			= g++
CXXFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(NAME).cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(NAME)

re: clean $(NAME)
