#ifndef _LEVEL1_H_
#define _LEVEL1_H_
#include "player.h"
//#include <iostream>
//#include <string>
class Level1: public Player{
    public:
    Level1(int color);
    bool pawnsKillMove(std::string init, std::string fin);
    bool castle(Piece* p, int dir);
    bool move(std::string init, std::string fin, int canMovee) override;
    ~Level1();
};

#endif



