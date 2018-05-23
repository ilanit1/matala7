#include "Board.h"
#pragma once

class Player{
    
public:

    char myChar;
    
    virtual const std::string name() const=0; 
    virtual const std::vector<int> play(const Board& board)=0; 
    
    
    char getChar()const{
        return myChar;
    }
    void setChar(char c) {
        myChar=c;
        
    }
};
