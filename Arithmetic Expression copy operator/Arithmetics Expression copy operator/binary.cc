#include <iostream>
#include <string>
#include "binary.h"
using namespace std;
binary::binary(string op,  Expression* obj1, Expression* obj2): op{op}, obj1{obj1}, obj2{obj2}{}

string& binary::getOp(){ return op;}

string binary::prettyprint(){
    return  "(" + obj2->prettyprint() +  " " + op + " " + obj1->prettyprint() + ")";
}

 

int binary::evaluate(){
    if(op == "+"){
     return obj1->evaluate() +  obj2->evaluate();
    } else if (op == "-"){
     return obj1->evaluate() -  obj2->evaluate();
    } else if (op == "*"){
     return obj1->evaluate() *  obj2->evaluate();
    } else {
        if(obj1->evaluate() != 0){
             cout  << obj1->evaluate() <<  endl;
            return obj2->evaluate() /  obj1->evaluate();
        } else {
            throw divideByZero();
        }
    }
}

binary* binary::clone() {
    return new binary{op, obj1->clone(), obj2->clone()};
} 

void binary::set(string s, int n){
    obj1->set(s, n);
    obj2->set(s, n);
}

void binary::unset(string s){
    obj1->unset(s);
    obj2->unset(s);
}

string binary::allset(){
   if(obj1->allset() !=  ""){
       return obj1->allset();
   }
   else {
       return obj2->allset() ;
   }
}


binary::~binary(){delete obj1; delete obj2;}


