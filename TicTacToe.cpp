#include "TicTacToe.h"


TicTacToe::TicTacToe(int dim) {
    
    m_board.init_Board(dim);
    win=false;
    turn= true;
    m_winner= nullptr;
}

Board TicTacToe::play( Player& p1,  Player& p2) {
    
    m_board='.';
    win=false;
    
    p1.setChar('X');
    p2.setChar('O');
    
    turn=true;
    m_winner=&p2;
    
    while(!win){
        
        if(isfull())
          return m_board;
        if(turn){
            try {
                vector<int> v;
                v = p1.play(m_board);
                if (m_board[v] == p2.myChar)
                    throw std::string("Illegal Player");
                m_board[v]='X';
                check(v);
                if(win) {
                    m_winner = &p1;
                }
            }
            catch (...){
                m_winner=&p2;
                win=true;
                return m_board;
            }
        }
        else{
            try {
                vector<int> v;
                v = p2.play(m_board);
                if (m_board[v] == p1.myChar)
                    throw std::string("Illegal Player");
                m_board[v]='O';
                check(v);
                if(win){
                    m_winner=&p2;
                }
            }
            catch (...){
                m_winner=&p1;
                win=true;
                return m_board;
            }

        }
    }
    return m_board;
}

void  TicTacToe::check(vector<int> vector1){
    
    char move;
    
    switch (turn){
        case true:
            move='X';
            break;
        case false:
            move='O';
            break;
    }
    int counter =0;
 
    for (int i = 0; i <m_board.size(); i++) {
        vector <int> v={vector1.at(0),vector1.at(1)};
        v.at(0)=i;
        if(move==m_board[v].get_p())counter++;
    }

    if(counter==m_board.size()){
        win=true;
        return;
    }

    counter=0;
    for (int i = 0; i <m_board.size(); i++) {
        vector <int> v={vector1.at(0),vector1.at(1)};
        v.at(1)=i;
        if(move==m_board[v].get_p())counter++;
    }

    if(counter==m_board.size()){
        win=true;
        return;
    }
    
    counter=0;
    for (int i = 0; i <m_board.size(); i++) {
        vector <int> v={0,0};
        v.at(1)=i;
        v.at(0)=i;
        if(move==m_board[v].get_p())counter++;
    }

    if(counter==m_board.size()){
        win=true;
        return;
    }
    counter=0;
    for (int i = 0; i <m_board.size(); i++) {
        vector <int> v={0,0};
        v.at(1)=m_board.size()-1-i;
        v.at(0)=i;
        if(move==m_board[v].get_p())counter++;
    }

    if(counter==m_board.size()){
        win=true;
        return;
    }
    turn=!turn;
}

bool TicTacToe::isfull() const{
    
    for (int i = 0; i <m_board.size() ; ++i) {
        for (int j = 0; j <m_board.size() ; ++j) {
            if(m_board[{i,j}].get_p()=='.')return false;
        }
    }
    return true;
}