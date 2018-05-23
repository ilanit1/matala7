#include "Board.h"

//constructors
Board::Board(int s) {

    length = s;
    board = new part*[length];
    for (int i = 0; i < length; ++i) {
        board[i] = new part[length];
    }
}

Board::Board(const Board &b) {
    
    length=b.length;
    board=new part*[length];
    for (int i = 0; i < length; ++i) {
        board[i] = new part[length];
    }
    for (int i = 0; i <length ; ++i) {
        for (int j = 0; j < length; ++j) {
            board[i][j].set_p(b.board[i][j].get_p());
        }
    }
}

//distructor
Board::~Board(){
    for (int i = 0; i <length ; ++i) {
            delete[] board[i];
    }

}

//operators
Board& Board::operator=( char c) {
    fill(c);
    return *this;
}

Board& Board::operator=(const Board& b) {
    
    length=b.length;
    board=new part*[length];
    for (int i = 0; i < length; ++i) {
        board[i] = new part[length];
    }
    for (int i = 0; i <length ; ++i) {
        for (int j = 0; j < length; ++j) {
            board[i][j].set_p(b.board[i][j].get_p());
        }
    }
    return *this;
}

part& Board::operator[]( vector<int> v) const {
    
    if(0<=v.at(1)&&v.at(1)<length&&0<=v.at(0)&&v.at(0)<length) {
        return board[v.at(0)][v.at(1)];
    }
    else {
        throw IllegalCoordinateException(v.at(0),v.at(1));
    }
}

ostream& operator<< (ostream& os,const Board& b){
    
    for (int i = 0; i <b.length ; ++i) {
        for (int j = 0; j <b.length ; ++j) {
            os<<(b.board[i][j].get_p());
        }
        os<<'\n';
    }
    return os;
}

//functions
void Board::fill( char c){
    
    if(c=='.'||c=='X'||c=='O'){
        for (int i = 0; i <length ; ++i) {
            for (int j = 0; j < length; ++j) {
                board[i][j]=c;
            }
        }
    }else throw IllegalCharException(c);

}

int Board::size() const {
    return length;
}

void Board::init_Board(int dim) {
    
    length=dim;
    board = new part*[length];
    for (int i = 0; i < length; ++i) {
        board[i] = new part[length];
    }
}