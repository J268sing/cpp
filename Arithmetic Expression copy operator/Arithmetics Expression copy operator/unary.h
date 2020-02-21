#ifndef _unaryInt_
#define _unaryInt_
#include "Expression.h"
#include <string>

class unary: public Expression {
    //  prettyprint set unset evaluate
    std::string op;
    Expression* obj;
    public:
    unary(std::string op, Expression *obj);                                                                               
    std::string prettyprint() override;
    std::string getOp();
    int evaluate() override;
    void set(std::string s, int i) override;
    void unset(std::string s) override;
    std::string allset() override;
    unary* clone() override;
    ~unary() override;
 }; 

#endif


 
 
 
