#ifndef __io__
#define __io__

#include<bits/stdc++.h>
using namespace std;

#endif

class Player
{
    private:
    int playerId;
    string playerName;
    int playerType; // 1 for O, 0 for X
   
    public:

    Player(){}

    Player(int playerId,string playerName,int playerType)
    {
        this->playerId = playerId;
        this->playerName = playerName;
        this->playerType = playerType;
    }

    void setPlayerId(int playerId) {
        this->playerId = playerId;
    }
    void setPlayerName(string playerName) {
        this->playerName = playerName;
    }
    void setPlayerType(int playerType) {
        this->playerType = playerType;
    }
   
    int getPlayerId() {
        return playerId;
    }
    string getPlayerName() {
        return playerName;
    }
    int getPlayerType() {
        return playerType;
    }
    
};
