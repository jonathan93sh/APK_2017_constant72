SOURCES=main.cpp
OBJECTS=${SOURCES:.cpp=.o}
EXECUTABLE=runProgram
CXX=g++

${EXECUTABLE}: ${OBJECTS}
	${CXX} -o $@ $^

all: ${OBJECTS}
	${CXX} -o ${EXECTUABLE} ${OBJECTS} -lnurses
clean:
	rm ${EXECUTABLE} ${OBJECTS}
help:
	echo all clean
