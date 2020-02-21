XX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla -W
EXEC = chess
OBJECTS = main.o chessBoard.o position.o  piece.o pawn.o king.o queen.o rook.o bishop.o knight.o player.o human.o level1.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
