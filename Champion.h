#include "Player.h"

class Champion : public Player{
    
public:

    const string name() const override { return "ilanit dadon"; }
    const vector<int> play(const Board &board)override;

};

