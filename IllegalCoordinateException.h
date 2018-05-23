using namespace std;
#include <iostream>
#include <string>
#include "vector"
#pragma once

class IllegalCoordinateException {
    
private:

    int x;
    int y;
    
public:

    string theCoordinate()const;
    IllegalCoordinateException(int z,int w);
};


