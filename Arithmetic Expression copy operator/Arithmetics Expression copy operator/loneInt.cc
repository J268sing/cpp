#include "loneInt.h"
using  namespace std ;
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

loneInt::loneInt(const int &item): item{item}{}

int& loneInt::getItem(){return item;};
string loneInt::prettyprint() {
    ostringstream ss;
    ss << item; 
    return ss.str();
}
int loneInt::evaluate(){return getItem();} 
void loneInt::set(string s, int n){} 
void loneInt::unset(string s){} 

loneInt* loneInt::clone(){
    return new loneInt{item};
}

string loneInt::allset(){return "";}
loneInt:: ~loneInt(){}


