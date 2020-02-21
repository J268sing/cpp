#ifndef _KNIGHT_H_
#define _KNIGHT_H_
#include <string>
#include "piece.h"
#include "position.h"
#include  <iostream>

class Knight: public Piece {
    public:
    Knight(Position* pos, char name, bool moved); 
    void move(std::string fin) override;
    bool canMove(std::string fin) override;
    ~Knight();
};
#endif
       


       
