using namespace std;
#include "IllegalCharException.h"
#include <iostream>
#pragma once

class part {
    
  private:
  
    char p;
    
  public:
  
    //constructors
    part();
    part(char c);
    
    //functions
    void set_p(char c);
    char get_p()const;
    
    //operators
    void operator=(char c);
    friend ostream& operator << (ostream& os, part& p);
    operator char() const ;

};
