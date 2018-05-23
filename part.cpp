#include "part.h"



//constructors
part::part() {
    set_p('.');
}

part::part(char c) {
    set_p(c);
}

//functions
char part::get_p()const {
    return  p;
}

void part::set_p(char c) {
    
    if(c=='.'||c=='O'||c=='X'){
        p=c;
    }else
       throw  IllegalCharException(c);
}

//operators
void part::operator=(const char c) {
    set_p(c);
}

part::operator char() const{
    return get_p();
}

ostream& operator<<(ostream &os, part &p) {
    return os<<p.get_p();
}

