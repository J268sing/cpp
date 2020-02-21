#ifndef _BISHOP_H_
#define _BISHOP_H_
#include <string>
#include "piece.h"
#include "position.h"
#include <iostream>


class Bishop: public Piece {
    public:
    Bishop(Position* pos, char name, bool moved); 
    void move(std::string fin) override;
    bool canMove(std::string fin) override;
    ~Bishop();

};
#endif
         
  
