#include "unary.h"
#include "Expression.h"
#include <iostream>
using namespace std;

unary::unary(string op,  Expression *obj): op{op},  obj{obj}{}
string unary::prettyprint(){
     if(op == "NEG"){
        return  "-" +  obj->prettyprint();
     } else {
        return   "|" + obj->prettyprint() +  "|" ;
     }
}

string unary::getOp(){return op;}

void unary::set(string s, int n) {obj->set(s, n);}
void unary::unset(string s) {obj->unset(s);}
int unary::evaluate(){
    if(op == "NEG"){
        return (-1)*obj->evaluate();
    } else{
        if(obj->evaluate() < 0){
            return obj->evaluate()*(-1);
        } else {
            return obj->evaluate();
        }
    }
}


unary* unary::clone(){
    return new unary{this->op, this->obj->clone()};
}

unary::~unary(){ delete obj;}

std::string unary::allset(){
    return obj->allset();
}



