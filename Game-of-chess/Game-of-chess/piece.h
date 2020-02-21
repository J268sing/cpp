#ifndef _PIECE_H_
#define _PIECE_H_
#include "position.h"
#include <string>

/*Doubts
here in place of method getPos(), should we instead make a method in Position class
that returns a pointer to the pos or not
*/

  
class Piece{
    Position* pos;
    char name;
    bool moved;
    public:
    Piece(Position* pos, char name, bool moved);
    Position* getPos();
    char& getName();
    bool getMoved() ;
    void setMoved(bool val);
    virtual void  move(std::string fin) = 0;
    virtual bool canMove(std::string fin) = 0;
    virtual ~Piece() = 0;
};
#endif


 

    
