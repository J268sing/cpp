#ifndef __Excecption__
#define __Excecption__
#include "player.h"
class Exception {
    std::string errorMessage = "the move you are trying is invalid";
    public:
    std::string getError() {return errorMessage;} 
    Exception(std::string error) : errorMessage{error} {}
};
#endif






