#ifndef _binary_
#define _binary_
#include "Expression.h"
#include <string>

class binary: public Expression {
    //  prettyprint set unset evaluate
    std::string op;
    Expression* obj1;
    Expression* obj2;
    public:
    binary( std::string op, Expression* obj1, Expression* obj2);
    std::string& getOp();
    std::string prettyprint() override;
    int evaluate() override;
    void set(std::string s, int n) override;
    void unset(std::string s) override;
    std::string allset() override;
    ~binary() override; 
}; 

class divideByZero {
    public:
    std::string msg = "Floating point exception";
};
#endif


