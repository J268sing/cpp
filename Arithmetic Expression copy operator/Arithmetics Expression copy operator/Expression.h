#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_
#include <string>

class Expression {
    public:
    virtual std::string prettyprint() = 0;
    virtual int evaluate() = 0;
    virtual void set(std::string s, int val) = 0;
    virtual void unset(std::string s) = 0;
    virtual std::string allset() = 0;
    virtual Expression* clone() = 0;
    virtual ~Expression() = 0;
};
#endif

