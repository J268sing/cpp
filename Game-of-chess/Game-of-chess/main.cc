#include <iostream>
#include "chessBoard.h"
#include "piece.h"
#include "pawn.h"
#include "position.h"
#include "player.h"
#include "human.h"
#include "exception.h"
using namespace std;
#include <sstream>
#include <cstdlib>

/*doubts
 
   
*/
/*
TODO:
destructor for the code


use pieces for drawing board.
write documentation for all the code that has been written
check design pattern for the code that has been written
exception handling in a class
give all the print functions to textview class
human player ye vo leke dekhne aa
write checkSetUp() code

*/   



int main(int argc,char **argv){
    bool retval = false;
    int count = 0;
    int isComputer1 = 0;
    int isComputer2 = 0;
    int bothSetUp = 1; // 1 if on
    std::string init ;
    std::string fin;
    int wScore = 0;
    int bScore = 0;

    srand(time(NULL));
    string level= "0";
    string level2 = "0";
    string arg3;
    
    if((argc > 3)||(argc < 3)){
        std::cout << "Wrong Number of inputs provided. Please Try again." << endl;
    } else{
        
        string p1 = argv[1]; // name of the first player
        string p2 = argv[2]; // name of the second player
        string input; 
        if(p1 == "computer[1]"){
            isComputer1 = 1;   
        }
        if(p2 == "computer[1]"){
            isComputer2 = 1;
        }
        ChessBoard  c{p1, p2}; 

        std::cout << c;
        int whoseTurn = 1; // 1 if first player has to make a move and 2 if second player has to make a move
        
        int play = 1;
        std::string init ;
        std::string fin;
        // for better experience I can ask here whether you would like to setup your players or 
        // play with default setup if they want to setup up then do it otherwise dont. So, should i implement it or not
        while((play == 1)){
            if(isComputer1 != 1){
            cin >> input;
            }
            if(cin.fail()){
                break;
            }
            if(input == "setup"){
                std::string placeAt;
                std::string piece;
                c.empty(); // this will remove all the pieces present on board and makes the board empty
                std::cout << c;
                std::cout << "Ok. Now " << p1 << " can start setting up players. Some examples of setting players are:" << endl;
                std::cout << "+ K a3 will place king at position a3. - a3 will remove the piece present at a3." << endl;
                std::cout << "= playername will allow the other user to set his players. Press done to after you are done with setting pieces." << endl;
                while(cin >> input){
                    if(input == "+"){
                        cin >> piece;
                        cin >> placeAt;
                        // checking of invalid inputs
                        if((piece.length() != 1)||(placeAt.length() != 2)){
                            std::cout << "invalid input."<< endl;
                            std::cout << "An example of valid input is: + K a3. Where k represents King and a3 is the poition"<< endl;
                        } else{
                        c.setUpConfigurations(input,placeAt,bothSetUp, piece);
                        std::cout << c;
                      
                        }
                    } else if (input == "-"){
                        // checking of invalid inputs
                        cin >> placeAt;
                        if(placeAt.length() != 2){
                            std::cout << "invalid input."<< endl;
                            std::cout << "An example of valid input is: - a3. Where k represents King and a3 is the poition"<< endl;
                        }
                        c.setUpConfigurations(input,placeAt, bothSetUp);
                        std::cout << c;
                      
                    } else if (input == "="){
                        cin >> input; 
                        if(input == p1){
                            bothSetUp = 1;
                            std::cout << p1 << " can set his pieces now." << endl;
                        } else if (input == p2){
                            bothSetUp = 2;
                            std::cout << p2 << " can set his pieces now." << endl;
                        } else{
                            std::cout << "There is no player with name = " << input << " so please try again"<< endl;
                        }
                    } else if (input == "done"){
                        if(c.checkSetUp(bothSetUp)){
                        play = 0;
                        break;
                        } else {
                            std::cout << "The pieces have not been set as per rules." << endl;
                            std::cout << "Pieces must be set such that:"<< endl;
                            std::cout << "There is exactly one white king and exactly one black king, no pawns are on the ﬁrst or last row of the board and neither king is in check." << endl;
                            std::cout << "Therefore, to play the game try setting up the players again." << endl;
                        }
                    } else{
                        std::cout << " wrong input please try again" << endl;
                    }
                }

            } else if(input == "resign"){
                if(bothSetUp == 1){
                    wScore = wScore;
                    bScore = bScore + 2;
                    std::cout << p1 << " resigned" << endl;
                    std::cout << p2 << " won" << endl;
                    std::cout << "Final Score" << endl;
                    std::cout << "White: " << wScore << endl; 
                    std::cout << "Black: " << bScore << endl;
                } else{
                    wScore = wScore + 2;
                    bScore = bScore;
                    std::cout << p2 << " resigned" << endl;
                    std::cout << p1 << " won" << endl;
                    std::cout << "Final Score" << endl;
                    std::cout << "White: " << wScore << endl; 
                    std::cout << "Black: " << bScore << endl;
                }
                    play = 0;
                } else if ((isComputer1 == 1)){
                    while(true){
                    int col = rand()%8;
                    int r = rand()%8;
                   // cout <<"rand = " <<r << col << "    ";
                    int fr = 8-r;
                    char fc = col+'a';
                    ostringstream ss7;    
                    ss7 << fc;
                    ss7 << fr;
                    string finPos = ss7.str();
                   // cout << "finPos " << finPos << endl;
                    try{
                        
                          count =1;
                        c.computeRandomMove(whoseTurn, finPos);
                    if(whoseTurn == 1){
                        if(c.noLegalMoves(2) == "checkmate"){
                            std::cout << p2 << " is checkmate.\n "<< p1 << " won." << endl;\
                            wScore = wScore + 2;
                            std::cout << "Final Score" << endl;
                            std::cout << "White: " << wScore << endl; 
                            std::cout << "Black: " << bScore << endl;
                            return 0;
                        } 
                    } else if (whoseTurn == 2){
                        if(c.noLegalMoves(1) == "checkmate"){
                            std::cout << p1 << " is checkmate.\n "<< p2 << " won." << endl;
                            bScore = bScore + 2;
                            std::cout << "Final Score" << endl;
                            std::cout << "White: " << wScore << endl; 
                            std::cout << "Black: " << bScore << endl;
                            return 0;
                        }
                    }

                    if((c.noLegalMoves(2) == "stalemtate")&&(c.noLegalMoves(1) == "stalemate")){
                        std::cout << "Stalemate. The game is draw" << endl;
                        bScore = bScore+ 1;
                        wScore = wScore + 1;
                        std::cout << "Final Score" << endl;
                        std::cout << "White: " << wScore << endl; 
                        std::cout << "Black: " << bScore << endl;
                        return 0;
                    }
                        
                    count = 1;
                    } catch(Exception &instance){
                        count = 0;
                    }
                    
                    if((count == 1)&&(whoseTurn == 1)){
                     //   cout << "jatt" << endl;
                        whoseTurn = 2;
                        count = 0;
                        play = 0;
                        std::cout << c;
                        break;
                    } else if ((count == 1)&&(whoseTurn == 2)){
                        whoseTurn = 1;
                        count = 0;
                        play = 0;
                        std::cout << c;
                        break;
                    }
                    
                    }
                } else if (input == "move"){
                   // std::string init ;
                    //std::string fin;
                    cin >> init;
                    cin >> fin;
                    try{
                        count =1;
                    c.move(init, fin, whoseTurn);
                    } catch (Exception &instnace) {
                        count = 0;
                        std::cout << instnace.getError() << std::endl;
                    }
                    if((count == 1)&&(whoseTurn == 1)){
                        whoseTurn = 2;
                    } else if ((count == 1)&&(whoseTurn == 2)){
                        whoseTurn = 1;
                    }
                    count = 0;
                    std::cout << c;
                    play = 0;
                } else{
                    std::cout << "wrong input." << "You can either input:"<< endl;
                    std::cout << "setup to set players initially," << endl;
                    std::cout << "resign to quit the game," << endl;
                    std::cout << "move arg1 arg2 arg3 to move arg1 from arg2 to arg3" << endl;
                }
            }
            play = 1;
            if((isComputer1 == 1)&&(isComputer2 == 1)){

            }
            while((play == 1)){
                if((isComputer1 == 0)&&(whoseTurn == 1)){
                    cin >> input;
                } else if ((isComputer2 == 0)&&(whoseTurn == 2)){
                cin >> input;
                }
                if(cin.fail()){
                    break;
                }
            

                if(input == "resign"){
                    if(bothSetUp == 1){
                     wScore = wScore;
                    bScore = bScore + 2;
                    std::cout << p1 << " resigned" << endl;
                    std::cout << p2 << " won" << endl;
                    std::cout << "Final Score" << endl;
                    std::cout << "White: " << wScore << endl; 
                    std::cout << "Black: " << bScore << endl;
                    play = 0;
                    } else{
                        wScore = wScore + 2;
                    bScore = bScore;
                    std::cout << p2 << " resigned" << endl;
                    std::cout << p1 << " won" << endl;
                    std::cout << "Final Score" << endl;
                    std::cout << "White: " << wScore << endl; 
                    std::cout << "Black: " << bScore << endl;
                        play = 0;
                    }
                } else if ((whoseTurn == 1)&&(isComputer1 == 1)){

                    while(true){
                    int col = rand()%8;
                    int r = rand()%8;
                   // cout <<"rand = " <<r << col << "    ";
                    int fr = 8-r;
                    char fc = col+'a';
                    ostringstream ss7;    
                    ss7 << fc;
                    ss7 << fr;
                    string finPos = ss7.str();
                   // cout << "finPos " << finPos << endl;
                    try{
                          count =1;
                        c.computeRandomMove(whoseTurn, finPos);
                    if(whoseTurn == 1){
                        if(c.noLegalMoves(2) == "checkmate"){
                            std::cout << p2 << " is checkmate.\n "<< p1 << " won." << endl;\
                            wScore = wScore + 2;
                            std::cout << "Final Score" << endl;
                            std::cout << "White: " << wScore << endl; 
                            std::cout << "Black: " << bScore << endl;
                            return 0;
                        } 
                    } else if (whoseTurn == 2){
                        if(c.noLegalMoves(1) == "checkmate"){
                            std::cout << p1 << " is checkmate.\n "<< p2 << " won." << endl;
                            bScore = bScore + 2;
                            std::cout << "Final Score" << endl;
                            std::cout << "White: " << wScore << endl; 
                            std::cout << "Black: " << bScore << endl;                          return 0;
                        }
                    }

                    if((c.noLegalMoves(2) == "stalemtate")&&(c.noLegalMoves(1) == "stalemate")){
                        std::cout << "Stalemate. The game is draw" << endl;
                        bScore = bScore+ 1;
                        wScore = wScore + 1;
                        std::cout << "Final Score" << endl;
                        std::cout << "White: " << wScore << endl; 
                        std::cout << "Black: " << bScore << endl;                        return 0;
                    }
                    count = 1;
                    } catch(Exception &instance){
                        count = 0;
                    }
                    
                    if((count == 1)&&(whoseTurn == 1)){
                     //   cout << "jatt" << endl;
                        whoseTurn = 2;
                        count = 0;
                        play = 1;
                        std::cout << c;
                        break;
                    } else if ((count == 1)&&(whoseTurn == 2)){
                        whoseTurn = 1;
                        count = 0;
                        play = 1;
                        std::cout << c;
                        break;
                    }
                    
                    }

                } else if ((whoseTurn == 2)&&(isComputer2 == 1)){
                 while(true){
                    int col = rand()%8;
                    int r = rand()%8;
                   // cout <<"rand = " <<r << col << "    ";
                    int fr = 8-r;
                    char fc = col+'a';
                    ostringstream ss7;    
                    ss7 << fc;
                    ss7 << fr;
                    string finPos = ss7.str();
                   // cout << "finPos " << finPos << endl;
                    try{
                         count =1;
                        c.computeRandomMove(whoseTurn, finPos);
                    if(whoseTurn == 1){
                        if(c.noLegalMoves(2) == "checkmate"){
                            std::cout << p2 << " is checkmate.\n "<< p1 << " won." << endl;\
                            wScore = wScore + 2;
                            std::cout << "Final Score" << endl;
                            std::cout << "White: " << wScore << endl; 
                            std::cout << "Black: " << bScore << endl;
                            return 0;
                        } 
                    } else if (whoseTurn == 2){
                        if(c.noLegalMoves(1) == "checkmate"){
                            std::cout << p1 << " is checkmate.\n "<< p2 << " won." << endl;
                            bScore = bScore + 2;
                            std::cout << "Final Score" << endl;
                            std::cout << "White: " << wScore << endl; 
                            std::cout << "Black: " << bScore << endl;
                            return 0;
                        }
                    }

                    if((c.noLegalMoves(2) == "stalemtate")&&(c.noLegalMoves(1) == "stalemate")){
                        std::cout << "Stalemate. The game is draw" << endl;
                        bScore = bScore+ 1;
                        wScore = wScore + 1;
                        std::cout << "Final Score" << endl;
                        std::cout << "White: " << wScore << endl; 
                        std::cout << "Black: " << bScore << endl;
                        return 0;
                    }
                        
                        //c.computeRandomMove(whoseTurn, finPos);
                    count = 1;
                    } catch(Exception &instance){
                        count = 0;
                    }
                    
                    if((count == 1)&&(whoseTurn == 1)){
                     //   cout << "jatt" << endl;
                        whoseTurn = 2;
                        count = 0;
                        play = 1;
                        std::cout << c;
                        break;
                    } else if ((count == 1)&&(whoseTurn == 2)){
                        whoseTurn = 1;
                        count = 0;
                        play = 1;
                        std::cout << c;
                        break;
                    }
                    
                    }
                } else if (input == "move"){
                   
                    cin >> init;
                    cin >> fin;
                    try{
                        count =1;
                    c.move(init, fin, whoseTurn);
                    if(whoseTurn == 1){
                        if(c.noLegalMoves(2) == "checkmate"){
                            std::cout << p2 << " is checkmate.\n "<< p1 << " won." << endl;\
                            wScore = wScore + 2;
                            std::cout << "Final Score" << endl;
                            std::cout << "White: " << wScore << endl; 
                            std::cout << "Black: " << bScore << endl;
                            return 0;
                        } 
                    } else if (whoseTurn == 2){
                        if(c.noLegalMoves(1) == "checkmate"){
                            std::cout << p1 << " is checkmate.\n "<< p2 << " won." << endl;
                            return 0;
                        }
                    }

                    if((c.noLegalMoves(2) == "stalemtate")&&(c.noLegalMoves(1) == "stalemate")){
                        std::cout << "Stalemate. The game is draw" << endl;
                        bScore = bScore+ 1;
                        wScore = wScore + 1;
                        std::cout << "Final Score" << endl;
                        std::cout << "White: " << wScore << endl; 
                        std::cout << "Black: " << bScore << endl;
                        return 0;
                    }
                    } catch (Exception &instnace) {
                        count = 0;
                        std::cout << instnace.getError() << std::endl;
                    }
                    if((count == 1)&&(whoseTurn == 1)){
                        whoseTurn = 2;
                        count = 0;
                    } else if ((count == 1)&&(whoseTurn == 2)){
                        whoseTurn = 1;
                        count = 0;
                    }
                    count = 0;
                    std::cout << c;
                } else {
                    std::cout << " wrong input please try again" << endl;
                }
            }
    }
}


