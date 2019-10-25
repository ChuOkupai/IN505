NAME		= main.out
INC			= Vecteur.hpp
CXX			= g++
CXXFLAGS	= -Wall -Wextra -Werror -D TAB_DYNAMIQUE=1

all: $(NAME)
	./$<

$(NAME): main.cpp Vecteur.o $(INC)
	$(CXX) $(CXXFLAGS) $< -o $@ $(word 2, $^)

Vecteur.o: Vecteur.cpp $(INC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f Vecteur.o $(NAME)

re: clean all
