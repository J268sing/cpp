#include "player.h"
using namespace std;
#include <iostream>
//how can we declare an empty vector (piecesKilled)in MIL
// in the MIL should i declare vectors as nullpts or the compiler can do it for me
Player::Player(int color):color{color}{}


void Player::print(){
    int len = p.size();
    for(int i = 0; i < len; ++i){
        cout << "{" << p.at(i)->getPos()->getRow() << ", " <<
        p.at(i)->getPos()->getCol() << ", " << p.at(i)->getName()<< "}, " ;
    }
}



bool Player::posBlocked(Position* pos){
    int len = p.size();
    for(int i = 0; i < len; ++i){
         if((p.at(i)->getPos()->getCol() == pos->getCol())&&
           (p.at(i)->getPos()->getRow() == pos->getRow())){
               return true;
           }
    }
    return false;
}


void Player::addPiece(Piece* add, char name){
    int len = p.size();
    
    for(int i = 0; i < len ; ++i){
        if((p.at(i)->getPos()->getCol() == add->getPos()->getCol())&&
           (p.at(i)->getPos()->getRow() == add->getPos()->getRow())){
               if(p.at(i)->getName() == add->getName()){ 
                    return;
               } else {
                 p.erase(p.begin()+i);
                 p.emplace_back(add);
                 return ;
               }
               
    }
    }
    p.emplace_back(add);
}


vector<Piece*>& Player::getPieces(){
    return p;
}


int& Player::getColor(){
    return color;
}

vector<char>& Player::getPiecesKilled(){
    return piecesKilled;
}

Player::~Player(){
    int size = p.size();
    for(int i= 0; i <  size; ++ i){
        p.erase(p.begin());
    }
}

 

char Player::getCharAtPos(string init){
    int c =  init[0] - 'a';
    int r = 8 -  (init[1] - '0');
    
    int len = p.size();
     for(int i = 0; i < len ; ++i){
             if((p.at(i)->getPos()->getCol() == c)&&
              (p.at(i)->getPos()->getRow() == r)){
                  return p.at(i)->getName();
              }
     }

     // if nothing i present at init position
     return ' ';

}


int Player::piecePresentAtFinal(string fin){
    int c =  fin[0] - 'a';
    int r = 8 -  (fin[1] - '0');
    
    int len = p.size();
     for(int i = 0; i < len ; ++i){
             if((p.at(i)->getPos()->getCol() == c)&&
              (p.at(i)->getPos()->getRow() == r)){
                  return 1;
              }
     }
     return 0;
    
}


void Player::removeAt(Position* pos){
    int len = p.size();
    for(int i = 0; i < len; ++i){
        if((p.at(i)->getPos()->getCol() == pos->getCol())&&
           (p.at(i)->getPos()->getRow() == pos->getRow())){
               p.erase(p.begin()+i);
               break;
        }
    }
}

void Player::eraseAt(string fin){
    int c =  fin[0] - 'a';
    int r = 8 -  (fin[1] - '0');
    int len = p.size();
      for(int i = 0; i < len ; ++i){
             if((p.at(i)->getPos()->getCol() == c)&&
              (p.at(i)->getPos()->getRow() == r)){
                  cout << endl;
                   cout << endl;
                 p.erase(p.begin()+i);
                 break;
              }
     }

}


int Player::piecePresentInBetweenPath(std::string init, std::string fin, char name){
    int initc =  init[0] - 'a';
    int initr = 8 -  (init[1] - '0');
    int finc =  fin[0] - 'a';
    int finr = 8 -  (fin[1] - '0');
    int len = p.size();
    for(int i = 0; i < len; ++i){
        initc =  init[0] - 'a';
        initr = 8 -  (init[1] - '0');
        if((name == 'r')||(name == 'R')){
            if(((finc == initc)&&(initc == p.at(i)->getPos()->getCol()))&&(((0 <= finr)&&(finr <  p.at(i)->getPos()->getRow())&&(p.at(i)->getPos()->getRow() < initr) &&(initr <=7))
              ||((0 <= initr)&&(initr <  p.at(i)->getPos()->getRow())&&(p.at(i)->getPos()->getRow() < finr)&&(finr <=7)))){
                  return 1;
            } else if (((finr == initr)&&(initr == p.at(i)->getPos()->getRow()))&&(((0 <= finc)&&(finc <  p.at(i)->getPos()->getCol())&&(p.at(i)->getPos()->getCol() < initc) &&(initc <=7))
              ||((0 <= initc)&&(initc <  p.at(i)->getPos()->getCol())&&(p.at(i)->getPos()->getCol() < finc)&&(finc <=7)))){
                  return 1;
            }
        } else if ((name == 'b')||(name == 'B')){
            int diffR = finr - initr;
            int diffC = finc - initc;
            int loopVar = diffR;
            if(loopVar < 0){ loopVar = loopVar*(-1);}
            for(int j = 0; j < loopVar - 1; ++j){
                if(diffR < 0){
                     initr = initr - 1;
                } else if (diffR > 0){
                    initr = initr + 1;
                }
                 if(diffC < 0){
                     initc = initc - 1;
                } else if (diffC > 0){
                    initc = initc + 1; 
                }
                if((p.at(i)->getPos()->getCol() == initc)&&(p.at(i)->getPos()->getRow() == initr)){
                    return 1;
                }
            }  
        } else if ((name == 'q')||(name == 'Q')){
            if(((initc == finc) &&(1<= finr <= 8))|| ((initr == finr) && (1 <= finc <= 8))) {
                if(((finc == initc)&&(initc == p.at(i)->getPos()->getCol()))&&(((0 <= finr)&&(finr <  p.at(i)->getPos()->getRow())&&(p.at(i)->getPos()->getRow() < initr) &&(initr <=7))
                     ||((0 <= initr)&&(initr <  p.at(i)->getPos()->getRow())&&(p.at(i)->getPos()->getRow() < finr)&&(finr <=7)))){
                        return 1;
                } else if (((finr == initr)&&(initr == p.at(i)->getPos()->getRow()))&&(((0 <= finc)&&(finc <  p.at(i)->getPos()->getCol())&&(p.at(i)->getPos()->getCol() < initc) &&(initc <=7))
                     ||((0 <= initc)&&(initc <  p.at(i)->getPos()->getCol())&&(p.at(i)->getPos()->getCol() < finc)&&(finc <=7)))){
                        return 1;
                }
            } else if (((initr - finr == (initc - finc))|| ((finr - initr) == (initc - finc)))||((initc - finc ==  (initr - finr))|| ((finc - initc) ==  (initr -finr)))){
                int diffR = finr - initr;
                int diffC = finc - initc;
                int loopVar = diffR;
                if(loopVar < 0){ loopVar = loopVar*(-1);}
                for(int j = 0; j < loopVar - 1; ++j){
                    if(diffR < 0){
                        initr = initr - 1;
                    } else if (diffR > 0){
                        initr = initr + 1;
                    }  
                    if(diffC < 0){
                     initc = initc - 1;
                    } else if (diffC > 0){
                        initc = initc + 1; 
                    }
                    if((p.at(i)->getPos()->getCol() == initc)&&(p.at(i)->getPos()->getRow() == initr)){
                        return 1;
                    }
                }
            }
        } else if ((name == 'k')||(name == 'K')){   
        }
    }
    return 0;
}



