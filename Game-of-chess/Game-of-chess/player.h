#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "piece.h"
#include <vector>
#include "pawn.h"
#include "king.h"
#include "rook.h"
#include "knight.h"
#include "queen.h"
#include "bishop.h"



class Player{
    protected:
    std::vector<Piece*> p;
    int color;
    std::vector<char> piecesKilled;
    public:
    Player(int color);
    std::vector<Piece*>& getPieces();
    int& getColor();
    void eraseAt(std::string fin);
    std::vector<char>& getPiecesKilled();
    void removeAt(Position* pos);
    virtual bool move(std::string init, std::string fin, int canMove) = 0;
    void addPiece(Piece* add, char name);
    int piecePresentAtFinal(std::string fin);
    int piecePresentInBetweenPath(std::string init, std::string fin, char name);
    char getCharAtPos(std::string init);
    bool posBlocked(Position* pos);
    void print();
    ~Player();
};

#endif 


