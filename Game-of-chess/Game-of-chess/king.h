#ifndef _KING_H_
#define _KING_H_
#include <string>
#include "piece.h"
#include "position.h"
#include <iostream>
class King: public Piece {
    public:
    King(Position* pos, char name, bool moved);
    void move(std::string fin) override;
    bool canMove(std::string fin) override;
    ~King();
};
#endif
        
  

  
