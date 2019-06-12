CXX = g++
CXXFLAGS = -std=c++11 -g
OBJS = menu.o main.o queue.o stack.o
SRCS = menu.cpp main.cpp queue.cpp stack.cpp
HEADERS = menu.hpp queue.hpp stack.hpp

main:${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

clean:
	rm *.o main

zip:
	zip -D stl_queue_stack.zip *.cpp *.hpp *.pdf makefile

val:
	valgrind --leak-check=full ./main