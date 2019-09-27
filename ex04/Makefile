INC			= Point.hpp
CXX			= g++
CXXFLAGS	= -Wall -Wextra -Werror

all: main
	./$<

main: main.cpp Point.o $(INC)
	$(CXX) $(CXXFLAGS) $< -o $@ $(word 2, $^)

Point.o: Point.cpp $(INC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f Point.o main

re: clean all
