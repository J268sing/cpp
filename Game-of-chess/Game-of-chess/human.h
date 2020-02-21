#ifndef _HUMAN_H_
#define _HUMAN_H_
#include "player.h"
//#include <iostream>
//#include <string>
class Human: public Player{
    public:
    Human(int color);
    bool pawnsKillMove(std::string init, std::string fin);
    bool castle(Piece* p, int dir);
    bool move(std::string init, std::string fin, int canMovee) override;
    ~Human();
};

#endif


