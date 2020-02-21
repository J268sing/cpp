CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla -W
EXEC = a4q3
OBJECTS = abstractDecorator.o basic.o exception.o flip.o image.o main.o  rotate.o sepia.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} ppm.o -o ${EXEC}
-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC}  ${DEPENDS}
.PHONY: clean
