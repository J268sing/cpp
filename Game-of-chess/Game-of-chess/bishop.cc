#include "bishop.h"
using namespace std;

//consntructor
Bishop::Bishop(Position* pos, char name, bool moved): Piece{pos, name, moved}{}
 

// changes the position of the piece from initial position to fin position
void Bishop::move(string fin){
    int c =  fin[0] - 'a';
    int r = 8 -  (fin[1] - '0');
    setMoved(true);
    getPos()->getRow() = r;
    getPos()->getCol() = c;
}
   
// returns true if a piece can be moved from initial position to fin position as per rules of bishop
bool Bishop::canMove(string fin){
    int c =  fin[0] - 'a';
    int r = 8 -  (fin[1] - '0'); 

    int diff = c - getPos()->getCol();
    if((r - getPos()->getRow() == diff)|| ((getPos()->getRow() - r) == diff)){
        return true;
    }

    diff = r - getPos()->getRow();

    if((c - getPos()->getCol() == diff)|| ((getPos()->getCol() - c) == diff)){
        return true;
    }

    return false;
}

Bishop::~Bishop(){
}



