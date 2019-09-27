INC			= ../ex04/Point.hpp Segment.hpp
CXX			= g++
CXXFLAGS	= -Wall -Wextra -Werror

all: main
	./$<

main: main.cpp ../ex04/Point.o Segment.o $(INC)
	$(CXX) $(CXXFLAGS) -I../ex04 $< -o $@ $(word 2, $^) $(word 3, $^)

Point.o:
	make -C ../ex04 Point.o

Segment.o: Segment.cpp $(INC)
	$(CXX) $(CXXFLAGS) -c -I../ex04 $< -o $@

clean:
	make -C ../ex04 clean
	rm -f Segment.o main

re: clean all
