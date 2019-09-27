INC			= CString.hpp
CXX			= g++
CXXFLAGS	= -Wall -Wextra -Werror

all: main
	./$<

main: main.cpp CString.o $(INC)
	$(CXX) $(CXXFLAGS) $< -o $@ $(word 2, $^)

CString.o: CString.cpp $(INC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f CString.o main

re: clean all
