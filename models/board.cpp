#ifndef __io__
#define __io__

#include<bits/stdc++.h>
using namespace std;

#endif


class Board
{
    private:
    int boardId;
    int boardSize;
    vector<vector<int>> board;
    
    public:
    Board(){}

    Board(int boardId,int boardSize)
    {
        this->boardId = boardId; 
        this->boardSize = boardSize; 
        board.resize(boardSize,vector<int>(boardSize,-1)); //-1 means empty
    }

    void setBoardId(int boardId) {
        this->boardId = boardId;
    }
    void setBoardSize(int boardSize) {
        this->boardSize = boardSize;
        board.resize(boardSize,vector<int>(boardSize,-1)); //-1 means empty
    }
    
    int getBoardId() {
        return boardId;
    }
    int getBoardSize() {
        return boardSize; // n*n total size of board
    }

    void setBoard(vector<vector<int>> gameBoard) {board = gameBoard;}

    vector<vector<int>> getBoard() {return board;}

};
