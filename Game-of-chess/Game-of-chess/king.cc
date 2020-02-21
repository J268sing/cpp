#include "king.h"
using namespace std;


//constructor
King::King(Position* pos, char name, bool moved): Piece{pos, name, moved} {}

// changes the position of the piece from initial position to fin position
void King::move(string fin){
    int c =  fin[0] - 'a';
    int r = 8 -  (fin[1] - '0');
    setMoved(true);
    getPos()->getRow() = r;
    getPos()->getCol() = c;
}
  
// returns true if a piece can be moved from initial position to fin position as per rules of king
bool King::canMove(string fin){
    int c =  fin[0] - 'a';
    int r = 8 -  (fin[1] - '0');
    if((getPos()->getRow() == (r-1))&&(getPos()->getCol() == c)){
        return true;
    } else if ((getPos()->getRow() == (r-1))&&(getPos()->getCol() == c)){
        return true;
    } else if ((getPos()->getRow() == (r+1))&&(getPos()->getCol() == c)){
        return true;
    } else if ((getPos()->getRow() == r)&&(getPos()->getCol() == (c - 1))){
        return true;
    } else if ((getPos()->getRow() == r)&&(getPos()->getCol() == (c+1))){
        return true;
    } else if ((getPos()->getRow() == (r-1))&&(getPos()->getCol() == (c-1))){
        return true;
    } else if ((getPos()->getRow() == (r-1))&&(getPos()->getCol() == (c+1))){
        return true;
    } else if ((getPos()->getRow() == (r+1))&&(getPos()->getCol() == (c-1))){
        return true;
    } else if ((getPos()->getRow() == (r+1))&&(getPos()->getCol() == (c+1))){
        return true;
    }
    
    return false;
}

   King::~King(){}




