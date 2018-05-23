#include "IllegalCharException.h"

IllegalCharException::IllegalCharException(char c) {
    ch=c;
}

char IllegalCharException::theChar()const {
    return ch;
}