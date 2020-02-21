#include <iostream>
#include <sstream>
#include <string>
#include "loneInt.h"
#include "variables.h"
#include "unary.h"
#include "binary.h"
#include <vector>
#include "Expression.h"
using namespace std;

// You will need to write your own test harness

// Read and construct expression object. Returns a pointer to a heap-allocated
// object (caller must delete it).
istream &operator>>(istream &in, Expression *&e) {
  vector<Expression*> v;
  string s;
  while (in >> s) {
    istringstream ss(s);
    int n;
    if (ss >> n){
     // Expression* ex = new loneInt{n};
      v.push_back(new loneInt{n});
    }
    else if (s == "NEG" || s == "ABS") {
     Expression* ex =  v.back();
     v.pop_back();
     //Expression un = unary{s, ex};
     v.push_back(new unary{s, ex});
    }
    else if (s == "+" || s == "-" || s == "*" || s == "/") {
      Expression* ex1 = v.back();
      v.pop_back();
      Expression* ex2 = v.back();
      v.pop_back();
     // Expression bi = binary{s, ex1, ex2};
      v.push_back(new binary{s, ex1, ex2});
    }  
    else if (s == "done") {
      break;
    }
    else {
      v.push_back(new variables{s});
    }
  }

  e = v.front();
  v.pop_back();
  return in;     
}

int main () {
  string s;

  Expression *e;
  cin >> e;
  string jash = e->prettyprint();
  cout <<jash << endl;
  // Command interpreter
  while (cin >> s) {
    if (s == "eval") {
      try { 
        cout << e->evaluate() << endl; 
      }catch(UnsetVarException &instance ){ /* Do the appropriate thing */
        continue;
      }catch(divideByZero &instance ){ /* Do the appropriate thing */
        cout << instance.msg << endl;
        break;
      }
    } else if (s == "set") {
      cin >> s;
      int val;
      cin >> val;
      e->set(s, val);
    }
    else if (s == "unset") {
      cin >> s;
      e->unset(s);
    }
    else if (s == "print") {
     string answer =  e->prettyprint();
     cout << answer << endl;
    }
  }
  delete e;
}

