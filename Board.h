using namespace std;
#pragma once
#include <iostream>
#include "part.h"
#include "vector"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"
typedef std::vector<int> Coordinate;

class Board {
    
  private:
    
    int length;
    part** board;
    
  public:

    //constructors
    Board(){};
    Board(int size);
    Board(const Board& b);
    
    //distructor
    ~Board();
    
    //operators
    Board& operator=(const Board& b);
    Board& operator=(char c);
    part& operator[](vector<int> v) const;
    friend ostream& operator<< (ostream& os,const  Board& b);
    
    //functions
    void init_Board(int dim);
    int size()const;
    void fill(char c);
    
};



