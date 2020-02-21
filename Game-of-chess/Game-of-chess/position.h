#ifndef _POSITION_H
#define _POSITION_H

class Position{
    int row;
    int col;
    public:
    Position(int row, int col);
    int& getRow();
    int& getCol();
    ~Position();
};

#endif


