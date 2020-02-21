#include "queen.h"
using namespace std;

//constructor
Queen::Queen(Position* pos, char name, bool moved): Piece{pos, name, moved}{}

//// changes the position of the piece from initial position to fin position
void Queen::move(string fin){
    int c =  fin[0] - 'a';
    int r = 8 -  (fin[1] - '0');
    setMoved(true);
    getPos()->getRow() = r;
    getPos()->getCol() = c;
}


// returns true if a piece can be moved from initial position to fin position as per rules of queem
bool Queen::canMove(string fin){
    
    return true;
}


Queen::~Queen(){}









