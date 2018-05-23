#include <vector>
#include "IllegalCoordinateException.h"

string IllegalCoordinateException::theCoordinate() const{
    string coordinates=to_string(x)+","+to_string(y);
    return coordinates;
}

IllegalCoordinateException::IllegalCoordinateException(int z,int w) {
    x=z;
    y=w;

}