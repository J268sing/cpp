#include "knight.h"
using namespace std;



//constructor
Knight::Knight(Position* pos, char name, bool moved): Piece{pos, name, moved}{}


// changes the position of the piece from initial position to fin position
void Knight::move(std::string fin){
    int c =  fin[0] - 'a';
    int r = 8 -  (fin[1] - '0');
    setMoved(true);
    getPos()->getRow() = r;
    getPos()->getCol() = c;
}
   
 
// returns true if a piece can be moved from initial position to fin position as per rules of knight
bool Knight::canMove(string fin){
    int c =  fin[0] - 'a';
    int r = 8 -  (fin[1] - '0'); 

    if((c - getPos()->getCol() == -1)||((c - getPos()->getCol()) == 1)){
        if((r - getPos()->getRow() == 2)||(r- getPos()->getRow() == -2)){
            return true;
        }
    } else if ((r - getPos()->getRow() == -1)||((r - getPos()->getRow()) == 1)){
        if((c - getPos()->getCol() == 2)||(c - getPos()->getCol() == -2)){
            return true;
        }
    return false;
}
}

Knight::~Knight(){}



