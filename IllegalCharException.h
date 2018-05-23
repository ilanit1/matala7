using namespace std;
#include <iostream>
#include <string>
#include "vector"
#pragma once

class IllegalCharException {
    
private:

    char ch;
    
public:

     IllegalCharException(char c);
    char theChar()const;
};

