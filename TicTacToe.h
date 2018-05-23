#include "Board.h"
#include "Player.h"

class TicTacToe {
    
   public:
    
    Board m_board;
    bool win;
    bool turn;
    Player* m_winner;

    TicTacToe(int);
    
    Board play(Player&, Player&);
    void check(vector<int>);
    
    Board board()const{
        return m_board;
    }
    const Player& winner() const{
        return *m_winner;
    }
    
    bool isfull()const;
    
};

