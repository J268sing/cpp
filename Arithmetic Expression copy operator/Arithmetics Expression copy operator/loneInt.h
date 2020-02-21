#ifndef _loneInt_
#define _loneInt_
#include "Expression.h"
#include <string>

class loneInt: public Expression {
    //  prettyprint set unset evaluate
    int item;
    public:  
    loneInt(const int &item);
    int& getItem(); 
    int evaluate() override;
    std::string prettyprint() override;
    void set(std::string s, int n) override;
    void unset(std::string s) override;
    std::string allset() override;
    loneInt* clone() override;
    ~loneInt() override;
};
 
#endif
 
