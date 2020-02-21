#include "rook.h"
using namespace std;


//constructor
Rook::Rook(Position* pos, char name, bool moved): Piece{pos, name, moved} {}



// changes the position of the piece from initial position to fin position
void Rook::move(std::string fin){
    int c =  fin[0] - 'a';
    int r = 8 -  (fin[1] - '0');
    setMoved(true);
    getPos()->getRow() = r;
    getPos()->getCol() = c;
} 


// returns true if a piece can be moved from initial position to fin position as per rules of rook
bool Rook::canMove(string fin){
    int c =  fin[0] - 'a';
    int r = 8 -  (fin[1] - '0');
    if((c == getPos()->getCol()) &&(1<= r <= 8)){
        return true;
    } else if((r == getPos()->getRow()) && (1 <= c <= 8)){
        return true;
    } else {
        return false;
    } 
}


Rook::~Rook(){}



