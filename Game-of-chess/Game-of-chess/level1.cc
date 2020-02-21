#include "level1.h"

using namespace std;

Level1::Level1(int color): Player{color}{}
 
bool Level1::move(string init, string fin, int canMovee){
    
    int c =  init[0] - 'a';
    int r = 7 -  (init[1] - '0'); 
    int len = p.size(); 
    int fc = fin[0] - 'a';
    bool loop = false;
    for(int i = 0; i < len ; ++i){
        if((p.at(i)->getPos()->getCol() == c)&&
           (p.at(i)->getPos()->getRow() == r+1)){
               if((p.at(i)->getName() == 'K')||(p.at(i)->getName() == 'k')){
                   if((c - fc) == 2){
                   loop = castle(p.at(i), 1);
                   } else if ((fc-c) == 2){
                   loop = castle(p.at(i), 2);
                   }
               }
           //    if((p.at(i)->getName() == 'P')||(p.at(i)->getName() == 'p')){
             //      if(pawnsKillMove(init, fin)){
               //        p.at(i)->move(fin);
                 //  }
               //}

              // cout <<"loop  = " <<  loop  << "  can moveee   " << canMovee << endl;
               if((loop == false)&&(canMovee == 0)){
               if(p.at(i)->canMove(fin)){
                    p.at(i)->move(fin);
                 //   cout << "not baby" << endl;
                   return true;
               } else{
               }

               } else if ((loop == false) && (canMovee == 1)){
                   if(p.at(i)->canMove(fin)){

                     //  cout << "baby" << endl;
                       return true;
                   }
               }
               return false;
           } 
    }

    return false;
}

bool Level1::pawnsKillMove(string init, string fin){
    int c =  init[0] - 'a';
    int r = 7 -  (init[1] - '0'); 
    
}


// dir is 1 for left and 2 for right
bool Level1::castle(Piece* pi, int dir){
    if(pi->getMoved() == true){ return false;}
    int len = p.size();
    for(int i = 0; i < len ; ++i){
        if((dir == 1)&&((p.at(i)->getPos()->getCol() == 0)&&
           (p.at(i)->getPos()->getRow() == 7))){
               if(p.at(i)->getMoved() == false){
                   p.at(i)->move("d1");
                   pi->move("c1");

                   return true;
               }
        } else if ((dir == 1)&&((p.at(i)->getPos()->getCol() == 0)&&
                   (p.at(i)->getPos()->getRow() == 0))){
                if(p.at(i)->getMoved() == false){
                   p.at(i)->move("d8");
                   pi->move("c8");
                   return true;
               }
        } else if ((dir == 2)&&((p.at(i)->getPos()->getCol() == 7)&&
            (p.at(i)->getPos()->getRow() == 0))){
                 if(p.at(i)->getMoved() == false){
                   p.at(i)->move("f8");
                   pi->move("g8");
                   return true;
               }
        } else if((dir == 2)&&((p.at(i)->getPos()->getCol() == 7)&&
           (p.at(i)->getPos()->getRow() == 7))){
               if(p.at(i)->getMoved() == false){
                   p.at(i)->move("f1");
                   pi->move("g1");
                   return true;
               }
        }
    }
    return false;
}



Level1::~Level1(){}



