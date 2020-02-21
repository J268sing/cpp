#include "piece.h"

using namespace std;
Piece::Piece(Position* pos, char name, bool moved): pos{pos}, name{name}, moved{moved} {}

char& Piece::getName(){
    return name;
}

Position* Piece::getPos(){
    return pos;
}

bool Piece::getMoved(){
    return moved;
}


void Piece::setMoved(bool val){
    moved =  val;
}

 Piece::~Piece(){
     delete pos;
 }     
    

    
