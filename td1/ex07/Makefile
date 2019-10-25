NAME		= main.out
INC			= ../ex06/CString.hpp Definition.hpp
CXX			= g++
CXXFLAGS	= -Wall -Wextra -Werror

all: $(NAME)
	./$<

$(NAME): main.cpp ../ex06/CString.o Definition.o $(INC)
	$(CXX) $(CXXFLAGS) -I../ex06 $< -o $@ $(word 2, $^) $(word 3, $^)

Point.o:
	make -C ../ex06 CString.o

Definition.o: Definition.cpp $(INC)
	$(CXX) $(CXXFLAGS) -c -I../ex06 $< -o $@

clean:
	make -C ../ex06 clean
	rm -f Definition.o $(NAME)

re: clean all
