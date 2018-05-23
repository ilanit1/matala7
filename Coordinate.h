#include <iostream>

struct Coordinate{
    
    uint x;
    uint y;
    
    friend std::ostream& operator<<(std::ostream& os, Coordinate const &c);
    
};