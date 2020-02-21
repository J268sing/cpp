#ifndef _ROOK_H_
#define _ROOK_H_
#include <string>
#include "piece.h"
#include "position.h"
#include <iostream>

class Rook: public Piece {
    public:
    bool moved;
    Rook(Position* pos, char name, bool moved);
    void move(std::string fin) override;
    bool canMove(std::string fin) override;
    ~Rook();
};
#endif

