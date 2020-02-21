#include "variables.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

variables::variables(std::string var): var{var} {
    varAssigned = false;
}

int& variables::getItem(){ return item;}
string& variables::getVar(){return var;}
void variables::set(string s, int i)  {
    if(s == var){
        item = i; varAssigned = true;
    }
}

void variables::unset(string s)  {
    if(s == var){
    varAssigned = false;
    } 
}

variables* variables::clone(){
    if(!varAssigned){
        return new variables(var);
    } else {
        return new variables(var, item, varAssigned);
    }
}

variables::variables(std::string s, int i, bool b): var{var}, item{i}, varAssigned{true}{}

string variables::prettyprint()  {
    if(varAssigned == true){
        ostringstream ss;
        ss << item; 
        return ss.str();
    } else {
        return var;
    }
}

int variables::evaluate(){
    if(varAssigned == true){
        return getItem();
    } else {
        cout << var << " has no value." <<  endl;
        throw UnsetVarException{};
    }
}



 string variables::allset() {
     if (varAssigned){
         return "";
     } else {
         return var;
     }
 }

variables::~variables(){}


