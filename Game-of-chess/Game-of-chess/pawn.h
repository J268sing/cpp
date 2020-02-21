#ifndef _PAWN_H_
#define _PAWN_H_
#include <string>
#include "piece.h"
#include "position.h"
#include <iostream>

class Pawn: public Piece {
    public:
    Pawn(Position* pos, char name, bool moved);
    void move(std::string fin) override;
    bool canMove(std::string fin) override;
};
#endif
                      

                      
