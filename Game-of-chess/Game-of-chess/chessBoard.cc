#include "chessBoard.h"
#include <iostream>
#include <sstream>
#include "exception.h"
using namespace std;
  
   
//constructor
ChessBoard::ChessBoard(string p11, string p22) {
    
    if((p11 == "computer[1]")||(p11 == "Computer[1]")){
        p1 = new Level1{1};
    } else {
        p1 = new Human{0};
    }
    if ((p22 == "computer[1]")||(p22 == "Computer[1]")){
        p2 = new Level1{0};
    } else {
        p2 = new Human{0};
    }
    for(int r = 7; r >= 0; -- r){
        for (int c = 0; c < 8; ++c){
            if(r == 1){
                p2->addPiece( new Pawn{new Position{r, c}, 'p', false}, 'p');
                board[r][c] = 'p';
            } else if ( r == 6){
                p1->addPiece( new Pawn{new Position{r, c}, 'P', false}, 'P');
                board[r][c] = 'P';
            } else if((r == 0) &&((c == 0) || (c == 7))){
                p2->addPiece( new Rook{new Position{r, c}, 'r', false}, 'r');
                board[r][c] = 'r';
            } else if ((r == 7) &&((c == 0) || (c == 7))){
                p1->addPiece( new Rook{new Position{r, c}, 'R', false}, 'R');
                board[r][c] = 'R';
            } else if ((r == 0) &&((c == 1) || (c == 6))){
                p2->addPiece( new Knight{new Position{r, c}, 'n', false}, 'n');
                board[r][c] = 'n';
            }else if ((r == 7) &&((c == 1) || (c == 6))){
                p1->addPiece( new Knight{new Position{r, c}, 'N', false}, 'N');
                board[r][c] = 'N';
            }else if ((r == 0) &&((c == 2) || (c == 5))){
                p2->addPiece( new Bishop{new Position{r, c}, 'b', false}, 'b');
                board[r][c] = 'b';
            }else if ((r == 7) &&((c == 2) || (c == 5))){
                p1->addPiece( new Bishop{new Position{r, c}, 'B', false}, 'B');
                board[r][c] = 'B';
            }else if ((r == 0) &&(c == 3)){
                p2->addPiece( new Queen{new Position{r, c}, 'q', false}, 'q');
                board[r][c] = 'q';
            }else if ((r == 7) &&(c == 3)){
                p1->addPiece( new Queen{new Position{r, c}, 'Q', false}, 'Q');
                board[r][c] = 'Q';
            }else if ((r == 0) &&(c == 4)){
                p2->addPiece( new King{new Position{r, c}, 'k', false}, 'k');
                board[r][c] = 'k';
            }else if ((r == 7) &&(c == 4)){
                p1->addPiece( new King{new Position{r, c}, 'K', false}, 'K');
                board[r][c] = 'K';
            }else if ((r+c)%2 == 0){
                board[r][c] = ' ';
            } else {
                board[r][c] = '_';
            }
        }
    }
}

//output operator used to print the board
ostream& operator<<(ostream& out, const ChessBoard& cb){
    int count = 8;
    char alpha = 'a';
    for (int r = 0; r < 10; ++r){
        for(int c = -2; c < 8; ++c){
            if((r == 8)&&(c >=0)){
                out << ' ' ;
            } else if ((c >=0)&&(r == 9)){
                out << alpha ;
                ++alpha;
            } else if  ((r<8)&&(c == -2)){
                out << count;
                count --;
            } else if (c <= -1){
                out << ' ';
            } else {
            out << cb.board[r][c];
            }
        }
        out << endl;
    }
    return out;
}


//notifyBoard() notifies the board to update its characters whenever there is a change in position
//     of any piece 
void ChessBoard::notifyBoard(){
    int r;
    int c;
    char nam;

    //empty board to refill it with updated position of pieces
    for(int x = 0; x < 8; ++ x){
        for (int y = 0; y < 8; ++y){
            if(((x+y)%2) == 0){
                board[x][y] = ' ';
            } else {
                board[x][y] = '_';
            }
        }
    }
    
    //refill board with updated positions of pieces of player1
    int len = p1->getPieces().size();
    for(int i = 0; i < len ; ++i){
        nam = p1->getPieces().at(i)->getName();
        r = p1->getPieces().at(i)->getPos()->getRow();
        c = p1->getPieces().at(i)->getPos()->getCol();
        board[r][c] = nam;
    }

    //refill board with updated positions of pieces of player1
    len = p2->getPieces().size();
    for(int i = 0; i < len ; ++i){
        nam = p2->getPieces().at(i)->getName();
        r = p2->getPieces().at(i)->getPos()->getRow();
        c = p2->getPieces().at(i)->getPos()->getCol();
        board[r][c] = nam;
    }
}


bool ChessBoard::checkSetUp(int whichPlayer){
    // ethe hale eh karna peya aa ke no king is in check
    int wKings = 0;
    int bKings = 0;
    for(int r = 0; r < 8; ++ r){
        for (int c = 0; c < 8; ++c){
            if(board[r][c] == 'K'){
                ++wKings;
            } else if(board[r][c] == 'k'){
                ++bKings;
            }
            if((r == 0)||(r == 7)){
                if((board[r][c] == 'p')||(board[r][c] == 'P')){
                    return false;
                } 
            }
        }
    }
   // cout <<"wKings: " << wKings << endl;
    //cout <<"bKings: " << bKings << endl;

    if((wKings != 1)||(bKings != 1)){
     //   cout << "ethe";
        return false;
    }
    return true;
}


//empty() removes all the pieces that player1 and player2 has as well as makes the board filled with ' ' for black space
//       and '_' for white space
void ChessBoard::empty(){
    for(int r = 0; r < 8; ++ r){
        for (int c = 0; c < 8; ++c){
            if((r <2) || r >5){
                if(((r+c)%2) == 0){
                    board[r][c] = ' ';
                } else {
                    board[r][c] = '_';
                } 
            }
        }
    }

    //remove all pieces from p1
    int len = p1->getPieces().size();
    for(int i = 0; i < len; ++i){
        p1->getPieces().erase(p1->getPieces().begin());
    }

    //remove all pieces from p1
    len = p2->getPieces().size();
    for(int i = 0; i < len; ++i){
        p2->getPieces().erase(p2->getPieces().begin());
    }
    
}


//createPiece(Position* p, char name) creates a new piece of type name with its position on
//    board equal to p
Piece* ChessBoard::createPiece(Position* p, char name, bool moved){
    if((name  == 'K')||(name == 'k')){
        return new King{p, name, moved};
    } else if ((name  == 'Q')||(name == 'q')){
        return new Queen{p, name, moved};
    } else if ((name  == 'N')||(name == 'n')){
        return new Knight{p, name, moved};
    } else if ((name  == 'B')||(name == 'b')){
        return new Bishop{p, name, moved};
    } else if ((name == 'R')||(name == 'r')){
        return new Rook{p, name, moved};
    } else {
        return new Pawn{p, name, moved};
    }
}



//setUpConfigurations(string op, string position,int whichPlayer, string piece) will setup the configurations of the 
//    modified new board. The type of update on board will depend on the operator op. + op will add a piece on board
//     and - op will remove a piece from board
void ChessBoard::setUpConfigurations(string op, string position,int whichPlayer, string piece){
    if(op == "+"){
        //first check if the position and piece are within the constraints of board and player names respectively
        if((position[0] >= 'a')&&(position[0] <= 'h')&&(position[1] >= 49)&&(position[1] <= 56)){
        if(((piece[0] == 'R')||(piece[0] == 'N')||(piece[0] == 'B')||(piece[0] == 'Q')||(piece[0] == 'K')||(piece[0] == 'P'))&&(whichPlayer == 1)){
            int c =  position[0] - 'a';
            int r = 7 -  (position[1] - '0'); 
            if((piece[0] == 'P')&&(((1+r) == 0) || ((1+r) == 7))){
                 cout  << "Cannot place P in the last row" << endl;
                return;
            }
            Position* p  = new Position{r+1, c};
            Piece* pi = createPiece(p, piece[0], true);
            if(p2->posBlocked(p)){
                cout  << "A piece is already present at that position of opponent player.\n Please tell the opponent to remove it to allow you to keep a player at that position" << endl;
                return;
            }
            p1->addPiece(pi, piece[0]);
            board[r+1][c] = piece[0];
        } else if (((piece[0] == 'r')||(piece[0] == 'n')||(piece[0] == 'b')||(piece[0] == 'q')||(piece[0] == 'k')||(piece[0] == 'p'))&&(whichPlayer == 2)){
            int c =  position[0] - 'a';
            int r = 7 -  (position[1] - '0');
            if((piece[0] == 'p')&&(((1+r) == 0) || ((1+r) == 7))){
                 cout  << "Cannot place P in the last row" << endl;
                return;
            }
            Position* p  = new Position{r+1, c};
            Piece* pi = createPiece(p, piece[0], true);
            if(p1->posBlocked(p)){
                cout  << "A piece is already present at that position of opponent player.\n Please tell the opponent to remove it to allow you to keep a player at that position" << endl;
                return;
            }
            p2->addPiece(pi, piece[0]);
            board[r+1][c] = piece[0];
        } else{
            cout << "invalid input."<< endl;
            cout << "An +- example of valid input is: + K a3. Where k represents King and a3 is the poition"<< endl;
        }
        
        }
        } else if(op == "-"){
            if((position[0] >= 'a')&&(position[0] <= 'h')&&(position[1] >= 49) &&(position[1] <= 56)){
                int c =  position[0] - 'a';
                int r = 7 -  (position[1] - '0'); 
                if((board[r+1][c] != ' ') ||(board[r+1][c] != '_')){
                    Position* p ;
                    if(whichPlayer ==1){
                        p = new Position{r+1, c};
                        p1->removeAt(p);
                    } else{
                        p = new Position{r+1, c};
                        p2->removeAt(new Position{r+1, c});
                    }
                    delete p;
                }
                if((r+c)%2 != 0){
                     board[r+1][c] = ' ';
                } else {
                   board[r+1][c] = '_';
                }
            } else {
                cout << "invalid input."<< endl;
                cout << "An - example of valid input is: + K a3. Where k represents King and a3 is the poition"<< endl;
            }
        } else {
            cout << "Wrong operator input" << endl;
        }   
}

//move(string init, string fin, int whoseTurn) will move the piece of whoseTurn player from init to fin position
//     if the move is legit according to rules
void ChessBoard::move(string init, string fin, int whoseTurn, int isComputer){
    bool alreadyInCheck;
    bool retval;  
    string jatt;
    if(whoseTurn ==1){
        alreadyInCheck = true;//(kingInCheck(1));
      //  cout <<"alreadyincheck    " << alreadyInCheck << endl;
    } else {
        alreadyInCheck = true;//(kingInCheck(2));
      //  cout <<"alreadyincheck    " << alreadyInCheck << endl;
    }  

   
    if(((whoseTurn == 1)&&(p1->piecePresentAtFinal(fin) == 1))||((whoseTurn == 2)&&(p2->piecePresentAtFinal(fin) == 1))){
        jatt =  "Cannot move to " + fin + " because there is already a piece present at " + fin + " of opposite colour" ;
        throw Exception(jatt);
    }

    char item ='a';
    if(whoseTurn == 1){
        item = p1->getCharAtPos(init);
    } else {
        item = p2->getCharAtPos(init);
    }
    if((item == 'p') || (item == 'P')){
        if((init[0] == fin[0])&&((p2->piecePresentAtFinal(fin) == 1||p1->piecePresentAtFinal(fin) == 1))){
            jatt =  "Cannot move to " + fin + " because there is already a piece present at " + fin + " of opposite colour" ;
            throw Exception(jatt);
            retval = false;
        } else {
            if(whoseTurn == 1){
                if(p2->piecePresentAtFinal(fin) == 1){
                    fin = fin + " ";
                } else {
                    fin = fin + "_";
                }
                retval = p1->move(init , fin, 0);
                notifyBoard();
                if((retval == true)&&kingInCheck(whoseTurn)&&alreadyInCheck){
                    p1->move(fin, init, 0);
                    notifyBoard();
                    retval = false;
                    jatt =  "Cannot move to " + fin + " because this move causes your king in check"  ;
                    throw Exception(jatt);
                 }else if ((retval == true)&&(p2->piecePresentAtFinal(fin))){
                p2->eraseAt(fin);

            }
            notifyBoard();
            } else {
                if(p1->piecePresentAtFinal(fin) == 1){
                    fin = fin + " ";
                } else {
                    fin = fin + "_";
                }
                retval = p2->move(init , fin, 0);
                notifyBoard();
                if((retval == true)&&kingInCheck(whoseTurn)&&alreadyInCheck){
                    p2->move(fin, init, 0);
                    notifyBoard();
                    retval =  false;
                    jatt =  "Cannot move to " + fin + " because this move causes your king in check"  ;
                    throw Exception(jatt);
                } else if ((retval == true)&&(p1->piecePresentAtFinal(fin))){
                p1->eraseAt(fin);
            }
                notifyBoard();
            }   
        }
    } else if (item == ' '){
         jatt =  "The move you are trying to do is invalid";
        throw Exception(jatt);
        retval =  false;
    } else if ((item == 'r')|| (item == 'R')) {
        if((whoseTurn == 1)&&(p1->piecePresentInBetweenPath(init, fin, item) == 0)&&(p2->piecePresentInBetweenPath(init, fin, item) == 0)&&(p1->piecePresentAtFinal(fin) == 0)){
            retval =  p1->move(init, fin, 0);
            notifyBoard();
            if((retval == true)&&kingInCheck(whoseTurn)&&alreadyInCheck){
                p1->move(fin, init, 0);
                notifyBoard();
                retval = false;
                jatt =  "Cannot move to " + fin + " because this move causes your king in check"  ;
                throw Exception(jatt);
            } else if ((retval == true)&&(p2->piecePresentAtFinal(fin))){
                p2->eraseAt(fin);
            }
            notifyBoard();
        }else if((whoseTurn == 2)&&(p1->piecePresentInBetweenPath(init, fin, item) == 0)&&(p2->piecePresentInBetweenPath(init, fin, item) == 0)&&(p2->piecePresentAtFinal(fin) == 0)){
            retval = p2->move(init, fin, 0);
            notifyBoard();
            
            if((retval == true)&&kingInCheck(whoseTurn)&&alreadyInCheck){
                p2->move(fin, init, 0);
                notifyBoard();
                retval = false;
                jatt =  "Cannot move to " + fin + " because this move causes your king in check"  ;
                throw Exception(jatt);
            } else if ((retval == true)&&(p1->piecePresentAtFinal(fin))){
                p1->eraseAt(fin);
            }
            notifyBoard();
        } else{
            jatt = "There is a piece present in between path so you cannot move to the desired location";
            throw Exception(jatt);
            retval =  false;
        }
    } else if ((item == 'n')|| (item == 'N')) {
        if((whoseTurn == 1)&&(p1->piecePresentAtFinal(fin) == 0)){
            retval = p1->move(init, fin, 0);
            notifyBoard();
            if((retval == true)&&kingInCheck(whoseTurn)&&alreadyInCheck){
                p1->move(fin, init, 0);
                notifyBoard();
                retval = false;
                jatt =  "Cannot move to " + fin + " because this move causes your king in check"  ;
                throw Exception(jatt);
            }else if ((retval == true)&&(p2->piecePresentAtFinal(fin))){
                p2->eraseAt(fin);
            }
            notifyBoard();
        } else if ((whoseTurn == 2)&&(p2->piecePresentAtFinal(fin) == 0)){
            retval = p2->move(init, fin, 0);
            notifyBoard();
            if((retval == true)&&kingInCheck(whoseTurn)&&alreadyInCheck){
                p2->move(fin, init, 0);
                notifyBoard();
                retval = false;
                jatt =  "Cannot move to " + fin + " because this move causes your king in check"  ;
                throw Exception(jatt);
            }else if ((retval == true)&&(p1->piecePresentAtFinal(fin))){
                p1->eraseAt(fin);
            }
            notifyBoard();
         } else{
            jatt = "Cannot move to " + fin + " because there you already have at piece there"   ;
            throw Exception(jatt);
            retval = false;
        }
    } else if ((item == 'b')|| (item == 'B')) {
        if((whoseTurn == 1)&&(p1->piecePresentInBetweenPath(init, fin, item) == 0)&&(p2->piecePresentInBetweenPath(init, fin, item) == 0)&&(p1->piecePresentAtFinal(fin) == 0)){
            retval = p1->move(init, fin, 0);
            notifyBoard();
            if((retval == true)&&kingInCheck(whoseTurn)&&alreadyInCheck){
                p1->move(fin, init, 0);
                notifyBoard();
                retval = false;
                jatt =  "Cannot move to " + fin + " because this move causes your king in check"  ;
                throw Exception(jatt);
            }else if ((retval == true)&&(p2->piecePresentAtFinal(fin))){
                p2->eraseAt(fin);
            }
            notifyBoard();
            retval = false;
        }else if((whoseTurn == 2)&&(p1->piecePresentInBetweenPath(init, fin, item) == 0)&&(p2->piecePresentInBetweenPath(init, fin, item) == 0)&&(p2->piecePresentAtFinal(fin) == 0)){
            retval = p2->move(init, fin, 0);
            notifyBoard();

            if((retval == true)&&kingInCheck(whoseTurn)&&alreadyInCheck){
            p2->move(fin, init, 0);
            notifyBoard();
            retval = false;
            jatt =  "Cannot move to " + fin + " because this move causes your king in check"  ;
            throw Exception(jatt);
            }else if ((retval == true)&&(p1->piecePresentAtFinal(fin))){
                p1->eraseAt(fin);
            }
            notifyBoard();
        } else{
            jatt =  "There is a piece present in between path so you cannot move to the desired location"  ;
            throw Exception(jatt);
            retval = false;
        } 
    } else if ((item == 'q')|| (item == 'Q')) {
        if((whoseTurn == 1)&&(p1->piecePresentInBetweenPath(init, fin, item) == 0)&&(p2->piecePresentInBetweenPath(init, fin, item) == 0)&&(p1->piecePresentAtFinal(fin) == 0)){
            retval = p1->move(init, fin, 0);
                notifyBoard();
            if((retval == true)&&kingInCheck(whoseTurn)&&alreadyInCheck){
                p1->move(fin, init, 0);
                notifyBoard();
                retval = false;
                jatt =  "Cannot move to " + fin + " because this move causes your king in check"  ;
                throw Exception(jatt);
            }else if ((retval == true)&&(p2->piecePresentAtFinal(fin))){
                p2->eraseAt(fin);
            }
            notifyBoard();
        }else if((whoseTurn == 2)&&(p1->piecePresentInBetweenPath(init, fin, item) == 0)&&(p2->piecePresentInBetweenPath(init, fin, item) == 0)&&(p2->piecePresentAtFinal(fin) == 0)){
            retval = p2->move(init, fin, 0);
            notifyBoard();
            if((retval == true)&&kingInCheck(whoseTurn)&&alreadyInCheck){
                p2->move(fin, init, 0);
                notifyBoard();
                retval = false;
                jatt =  "Cannot move to " + fin + " because this move causes your king in check"  ;
                throw Exception(jatt);
            }else if ((retval == true)&&(p1->piecePresentAtFinal(fin))){
                p1->eraseAt(fin);
            }
            notifyBoard();
        } else{
            jatt =  "There is a piece present in between path so you cannot move to the desired location"  ;
            throw Exception(jatt);
            retval = false; 
         } 
    } else if ((item == 'k') || (item == 'K')){
        int c = init[0] - 'a';
        int fc = fin[0] - 'a';
        //checks one of the condition of castling that is to check if a piece is present at one of the final positions of
        // king or rook which may disallow castling.
        if((c - fc) == 2){
            if((whoseTurn == 1)&&((p1->piecePresentAtFinal("b1") == 1)||(p2->piecePresentAtFinal("c1") == 1)
                ||(p1->piecePresentAtFinal("c1") == 1)||(p2->piecePresentAtFinal("b1") == 1)
                ||(p2->piecePresentAtFinal("d1") == 1)||(p1->piecePresentAtFinal("d1") == 1))){

            jatt =    "Cannot castle because there is already a piece present at one of the final positions" ;
            throw Exception(jatt);
            retval = false;    
            }else if ((whoseTurn == 2)&&((p1->piecePresentAtFinal("b8") == 1)||(p2->piecePresentAtFinal("c8") == 1)
                ||(p1->piecePresentAtFinal("c8") == 1)||(p2->piecePresentAtFinal("b8") == 1)
                ||(p2->piecePresentAtFinal("d8") == 1)||(p2->piecePresentAtFinal("d8") == 1))){
                jatt =    "Cannot castle because there is already a piece present at one of the final positions" ;
                throw Exception(jatt);
                retval = false;
            }
        } else if ((fc - c) == 2){
            if((whoseTurn == 1)&&((p1->piecePresentAtFinal("g1") == 1)||(p2->piecePresentAtFinal("f1") == 1)
                ||(p1->piecePresentAtFinal("f1") == 1)||(p2->piecePresentAtFinal("g1") == 1))){
                jatt =    "Cannot castle because there is already a piece present at one of the final positions" ;
                throw Exception(jatt);
                retval = false;       
            }else if ((whoseTurn == 2)&&((p1->piecePresentAtFinal("g8") == 1)||(p2->piecePresentAtFinal("f8") == 1)
                ||(p1->piecePresentAtFinal("f8") == 1)||(p2->piecePresentAtFinal("g8") == 1))){
                jatt =    "Cannot castle because there is already a piece present at one of the final positions" ;
                throw Exception(jatt);
                retval = false;    
            }
        }
        if((whoseTurn == 1)&&(p1->piecePresentAtFinal(fin) == 1)){
            jatt =    "Cannot castle because there is already a piece present at one of the final positions" ;
            throw Exception(jatt);
            retval = false;    
        } else if((whoseTurn == 2)&&(p2->piecePresentAtFinal(fin) == 1)){
            jatt =    "Cannot castle because there is already a piece present at one of the final positions" ;
            throw Exception(jatt);
            retval = false;    
        } else {
            if(whoseTurn == 1){
                retval = p1->move(init , fin, 0);
                notifyBoard();
                if((retval == true)&&kingInCheck(whoseTurn)&&alreadyInCheck){
                    p1->move(fin, init, 0);
                    notifyBoard();
                    retval = false;
                    jatt =  "Cannot move to " + fin + " because this move causes your king in check"  ;
                    throw Exception(jatt);
                }else if ((retval == true)&&(p2->piecePresentAtFinal(fin))){
                p2->eraseAt(fin);
            }
            notifyBoard();
            } else {
            retval = p2->move(init , fin, 0);
            notifyBoard();
            if((retval == true)&&kingInCheck(whoseTurn)&&alreadyInCheck){
                p2->move(fin, init, 0);
                retval = false;
                notifyBoard();
                jatt =  "Cannot move to " + fin + " because this move causes your king in check"  ;
                throw Exception(jatt);
            }else if ((retval == true)&&(p1->piecePresentAtFinal(fin))){
                p1->eraseAt(fin);
            }
                notifyBoard();
            }
        }
    } else{
        jatt =  "Cannot move to " + fin + " because this move causes your king in check"  ;
                throw Exception(jatt);
         retval = true;
    }
    if(whoseTurn ==1){
        if(kingInCheck(2)){
            cout << "Player 2's king is in check" << endl;
        }
    } else {
        if(kingInCheck(1)){
            cout << "Player 1's king is in check" << endl;
        }
    }
    if(retval == false){
        jatt =  "Cannot move to " + fin + " because this move causes your king in check"  ;
    throw Exception(jatt);
    }
}

// ethe mai player de destructor vangu destructor likhan ya fer player de destructor function nu call kran
ChessBoard::~ChessBoard(){
    delete p1;
    delete p2;
}


bool ChessBoard::kingInCheck(int whoseTurn){
    int r;
    int c;
    char charPresent = ' ';
    char king = 'k';
    int start = 65;
    int end = 90;
    int fixedRow;
    int fixedCol;
    Player* p = p2;
    if(whoseTurn == 1){
        king = 'K';
        p  = p1;
        start = 97;
        end = 122;
    }

     bool retval = false;
         int len = p->getPieces().size();
        for(int i = 0; i < len; ++i){
            if(p->getPieces().at(i)->getName() == king){
                r = p->getPieces().at(i)->getPos()->getRow();
                c = p->getPieces().at(i)->getPos()->getCol();
            }
        }
        if(whoseTurn ==1){
            p = p2;
        } else{
            p =p1;
        }
        fixedRow = r;
        fixedCol = c;

        r = fixedRow;
        c = fixedCol;
        //convert the positions of board in typed position style for example (0,0) into a8
        int fr = 8 - r;
        char fc =  c + 'a' ;

        //change the final row(fr) and final column(fc) into strings using string stream
        ostringstream ss;    
        ss << fc;
        ss << fr;
        string kingPos = ss.str();

        //check for first elements present diagonally from bottom right corner to top left corner
        while((r>0)&&(r<=7)&&(c>0)&&(c<=7)){
         //   cout << "inloop6" << endl;

            r = r -1;
            c = c-1;
            charPresent = board[r][c];
            if((charPresent != ' ')&&(charPresent != '_')){
                break;
            }
        }
      //  cout << "charpresent6 " << charPresent << endl;
        fr = 8-r;
        fc = c+'a';
        ostringstream ss1;    
        ss1 << fc;
        ss1 << fr;
        string initPos = ss1.str();

         if ((charPresent >=start)&&(charPresent <= end)){
       //          cout << "main RETVALs  " << retval <<endl;

             retval = p->move(initPos, kingPos, 1);
        }

        if(retval == true){
            return retval;
        }   

        r = fixedRow;
        c = fixedCol;     
        //check for first elements present diagonally from top left corner to bottom right corner
        while((r>=0)&&(r<7)&&(c>=0)&&(c<7)){
          //  cout << "inloop7" << endl;
            r = r+1;
            c = c+1;
            charPresent = board[r][c];
            if((charPresent != ' ')&&(charPresent != '_')){
                break;
            }
        }
     //   cout << "charpresent7 " << charPresent << endl;

        fr = 8-r;
        fc = c+'a';
        ostringstream ss2;    
        ss2 << fc;
        ss2 << fr;
        initPos = ss2.str();

         if ((charPresent >=start)&&(charPresent <= end)){
             retval = p->move(initPos, kingPos, 1);
        }
        
        if(retval == true){
            return retval;
        } 

        r = fixedRow;
        c = fixedCol;
        //check for first elements present diagonally from bottom left corner to top right corner
        while((r>0)&&(r<=7)&&(c>=0)&&(c<7)){
       //                 cout << "inloop8" << endl;

            r = r - 1;
            c = c+1;
            charPresent = board[r][c];
            if((charPresent != ' ')&&(charPresent != '_')){
                break;
            }
        }
       // cout << "charpresent8 " << charPresent << endl;

        fr = 8-r;
        fc = c+'a';
        ostringstream ss3;    
        ss3 << fc;
        ss3 << fr;
        initPos = ss3.str();

         if ((charPresent >=start)&&(charPresent <= end)){
       //     cout << "kyo  " << endl;
             retval = p->move(initPos, kingPos, 1);
        }

        if(retval == true){
            return retval;
        } 

        r = fixedRow;
        c = fixedCol;
        //check for first elements present diagonally from top right corner to bottom left corner
        while((r>=0)&&(r<7)&&(c>0)&&(c<=7)){
      //                  cout << "inloop1" << endl;

            r = r + 1;
            c = c-1;
            charPresent = board[r][c];
            if((charPresent != ' ')&&(charPresent != '_')){
                break;
            }
        }
       // cout << "charpresent1 " << charPresent << endl;

        fr = 8-r;
        fc = c+'a';
        ostringstream ss4;    
        ss4 << fc;
        ss4 << fr;
        initPos = ss4.str();

         if ((charPresent >=start)&&(charPresent <= end)){
             retval = p->move(initPos, kingPos, 1);
        }

        if(retval == true){
            return retval;
        } 

        r = fixedRow;
        c = fixedCol;
        //check for first elements present vertically from bottom to top having same column
        while((r>0)&&(r<=7)&&(c>=0)&&(c<=7)){
       //                 cout << "inloop2" << endl;

            r = r  - 1;
            charPresent = board[r][c];
            if((charPresent != ' ')&&(charPresent != '_')){
                break;
            }
        }
       // cout << "charpresent2 " << charPresent << endl;

        fr = 8-r;
        fc = c+'a';
        ostringstream ss5;    
        ss5 << fc;
        ss5 << fr;
        initPos = ss5.str();

         if ((charPresent >=start)&&(charPresent <= end)){
             retval = p->move(initPos, kingPos, 1);
        }

        if(retval == true){
             return retval;
        } 


        r = fixedRow;
        c = fixedCol;
        //check for first elements present vertically from top to bottom having same column
        while((r>=0)&&(r<7)&&(c>=0)&&(c<=7)){
     //                   cout << "inloop3" << endl;

            r = r + 1;
            charPresent = board[r][c];
            if((charPresent != ' ')&&(charPresent != '_')){
                break;
            }
        }
    //   cout << "charpresent3 " << charPresent << endl;

        fr = 8-r;
        fc = c+'a';
        ostringstream ss6;    
        ss6 << fc;
        ss6 << fr;
        initPos = ss6.str();
     //   cout <<"initpos  " << initPos << kingPos << endl;
        if ((charPresent >=start)&&(charPresent <= end)){
            cout << endl;
//cout << endl;
             retval = p->move(initPos, kingPos, 1);
         //    cout << "right here " << retval << endl;
        }
   //     cout << "right heres " << retval << endl;

        if(retval == true){
            return retval;
        } 


        r = fixedRow;
        c = fixedCol;
        //check for first elements present horizontally from left to right having same row
        while((r>=0)&&(r<=7)&&(c>=0)&&(c<7)){
     //                   cout << "inloop4" << endl;

            c = c+1;
            charPresent = board[r][c];
            if((charPresent != ' ')&&(charPresent != '_')){
                break;
            }
        }
     //   cout << "charpresent4 " << charPresent << endl;

        fr = 8-r;
        fc = c+'a';
        ostringstream ss7;    
        ss7 << fc;
        ss7 << fr;
        initPos = ss7.str();

         if ((charPresent >=start)&&(charPresent <= end)){
             retval = p->move(initPos, kingPos, 1);
        }
        if(retval == true){
            return retval;
        } 

        r = fixedRow;
        c = fixedCol;
        //check for first elements present horizontally from right to left having same row
        while((r>=0)&&(r<=7)&&(c>0)&&(c<=7)){
      //                  cout << "inloop5" << endl;

            c = c-1;
            charPresent = board[r][c];
            if((charPresent != ' ')&&(charPresent != '_')){
                break;
            }
        }
      //  cout << "charpresent5 " << charPresent << endl;

        fr = 8-r;
        fc = c+'a';
        ostringstream ss8;    
        ss8 << fc;
        ss8 << fr;
        initPos = ss8.str();

        if ((charPresent >=start)&&(charPresent <= end)){
             retval = p->move(initPos, kingPos, 1);
        }
        if(retval == true){
            return retval;
        }

        r = fixedRow;
        c = fixedCol;

        // r = r-1,c = c+2   or r = r+1, c = c+2 or r = r-1, c= c-2 or r = r+1, c = c-2
        // r = r+2, c = c -1 or r = r+2, c = c+1, or r = r -2, c = c-1 or r = r - 2, c = c+1



   // cout << "retvalaaa   " << retval << endl;
        return retval;
}

// bottrom right to top left
//top left to bottrom right
// bottom left to top right
// top right to bottom left
//bottom to top
// top to bottom
// left to right
//right to left










void ChessBoard::computeRandomMove(int whichPlayer, string fin){
    Player* p ;
    if(whichPlayer == 1){
        p = p1;
    } else {
        p = p2;
    }
    
    int loopBreaker = 0;
    int len = p->getPieces().size();
    int c =  fin[0] - 'a';
    int r = 8 -  (fin[1] - '0'); 
  //  cout << "row,col  "  << r << c << endl;
    //cout <<"ethe" << endl;
    for(int i = 0; i < len; ++i){
        loopBreaker = 0;
        int col = p->getPieces().at(i)->getPos()->getRow();
        int r =  p->getPieces().at(i)->getPos()->getCol();
        int fr = 8-r;
        char fc = col +'a';
        ostringstream ss7;    
        ss7 << fc;
        ss7 << fr;
        string initPos = ss7.str();
       // cout << initPos << fin << endl;
        try{move( initPos, fin, whichPlayer, 1);
        
        loopBreaker = 1;
        } catch (Exception &instance){
            loopBreaker = 0;
        }
        //continue;
        if(loopBreaker == 1){
           notifyBoard();
            return;
        }
    }
    notifyBoard();
    throw Exception("Give any other final position");

}



string ChessBoard::noLegalMoves(int whichPlayer){
    Player*p;
    int count = 1;
    if(whichPlayer == 1){
        p = p1;
    } else{
        p = p2;
    }
    int l1 = p2->getPieces().size();
    int l2 = p1->getPieces().size();
    if((l1 == 1)&&(l2 == 1)){
        return "stalemate";
    }

    bool nolegalmoves = true ;
    bool alreadyInCheck = kingInCheck(whichPlayer);
    for(int r = 0; r < 8 ;++r){
        for(int c = 0; c < 8 ; ++c){
        int fr = 8-r;
        char fc = c +'a';
        ostringstream ss7;    
        ss7 << fc;
        ss7 << fr;
        string finPos = ss7.str();
        int len = p->getPieces().size();
        for(int i = 0; i < len ; ++i){
            int row = p->getPieces().at(i)->getPos()->getRow();
            int col = p->getPieces().at(i)->getPos()->getCol();
            fr = 8-row;
            fc = col + 'a';
            ostringstream ss8;
            ss8<<col;
            ss8 << row;
            string initPos = ss8.str();
            try{move(initPos, finPos, whichPlayer);
            
                 count = 0;
            } catch(Exception &instance){
                count = 1;
            }

            if((kingInCheck(whichPlayer) == false)&&(count == 0)){
                nolegalmoves =  false;
                break;
            }
        }
        }
    }


    if((alreadyInCheck == true)&&(nolegalmoves == true)){
        return "checkmate";
    } else if ((alreadyInCheck == false)&&(nolegalmoves = true)){
        return "stalemate";
    } else {
        return "";
    }
}




