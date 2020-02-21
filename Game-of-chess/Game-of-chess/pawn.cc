#include "pawn.h"
using namespace std;


Pawn::Pawn(Position* pos, char name, bool moved): Piece{pos, name, moved} {}



// changes the position of the piece from initial position to fin position
void Pawn::move(string fin){
    int c =  fin[0] - 'a';
    int r = 8 -  (fin[1] - '0');
    Position* p = getPos();
    setMoved(true);
    p->getCol() = c;
    p->getRow() = r;
 }

 // returns true if a piece can be moved from initial position to fin position as per rules of pawn
bool Pawn::canMove(string fin){
    char item = getName();
    int c =  fin[0] - 'a';
    int r = 8 -  (fin[1] - '0'); 
  
    if((item>= 65) && (item <= 90)){
        if (((r + 1) == getPos()->getRow())&&(c == getPos()->getCol())){
            return true;
        } else if ((getMoved() == false)&&((r + 2) == getPos()->getRow())&&(c == getPos()->getCol())) {
            return true;;
        } else if ((fin[2] == ' ')&&((((r + 1) == getPos()->getRow())&&((c+1) == getPos()->getCol()))
                                       ||(((r + 1) == getPos()->getRow())&&((c-1) == getPos()->getCol())))){
            return true;   
        } else {
            return false;
    }
    } else{
        if (((r - 1) == getPos()->getRow())&&(c == getPos()->getCol())){
            return true;
        }else if ((getMoved() == false)&&((r - 2) == getPos()->getRow())&&(c == getPos()->getCol())) {
            return true;;
        } else if  ((fin[2] == ' ')&&((((r - 1) == getPos()->getRow())&&((c+1) == getPos()->getCol()))
                                       ||(((r - 1) == getPos()->getRow())&&((c-1) == getPos()->getCol())))) {
            return true;
        } else {
            return false;
        }
    }
}
   

   
