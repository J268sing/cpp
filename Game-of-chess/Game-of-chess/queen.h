#ifndef _QUEEN_H_
#define _QUEEN_H_
#include <string>
#include "piece.h"
#include "position.h"
#include <iostream>
class Queen: public Piece {
    public:
    Queen(Position* pos, char name, bool moved); 
    void move(std::string fin) override;
    bool canMove(std::string fin) override;
    ~Queen();
};
#endif
          

          
