CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla -W
EXEC = a4q2
OBJECTS = main.o binary.o unary.o  variables.o loneInt.o Expression.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
