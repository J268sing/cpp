#include "position.h"


Position::Position(int row, int col): row{row}, col{col}{}
int& Position::getRow(){
    return row;
}

int& Position::getCol(){
    return col;
}

Position::~Position(){}

 
