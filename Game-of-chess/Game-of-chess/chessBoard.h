#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_
#include <string>
#include "player.h"
#include "human.h"
#include "level1.h"
/*Doubts
   is it optimum to include using namespace std in .h file?
*/

class ChessBoard{
    char board[8][8];
    //Player* p1;
    //Player* p2;

    public:
    Player* p1;
    Player* p2;
    ChessBoard(std::string p11, std::string p22);
    void empty(); 
    bool checkSetUp(int whichPlayer);
    //void canMove(std::string fin);
    void notifyBoard();
    int piecePresentAtFinal(std::string fin, int whichPlayer);
    bool kingInCheck(int whoseTurn);

    Piece* createPiece(Position* p, char name, bool moved);
    void move(std::string init, std::string fin, int whoseTurn, int isComputer = 0);
    void computeRandomMove(int whichPlayer, std::string fin);
    std::string noLegalMoves(int whichPlayer);
    void setUpConfigurations(std::string op, std::string position,int whichPlayer, std::string piece = "" );// do we have to write the default value of piece here also?
    friend std::ostream& operator<<(std::ostream& out, const ChessBoard& cb);
    ~ChessBoard();
};


  

#endif   




