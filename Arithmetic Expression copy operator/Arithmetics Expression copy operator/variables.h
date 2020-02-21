#ifndef _variables_
#define _variables_
#include "Expression.h"
#include <string>

class variables: public Expression {
    //  prettyprint set unset evaluate
   std::string var = "";
   int item;
   bool varAssigned;

   public:
   variables(std::string var);
   variables(std::string var, int i, bool b);
   int& getItem();
   std::string& getVar();
   void set(std::string s, int i) override;
   void unset(std::string s) override;
   std::string prettyprint() override;
   int evaluate() override;
   std::string allset() override;
   variables* clone() override;
   ~variables() override;
 };
 class UnsetVarException {};


#endif
 
