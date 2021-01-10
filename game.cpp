#ifndef __io__
#define __io__

#include<bits/stdc++.h>
using namespace std;

#endif

#include "models/board.cpp"
#include "models/player.cpp"
class Game{
    // move
    // board
    // players
    // status
    private:
    Board board;
    vector<Player> players;
    string status;  // running, draw, A win, B win, draw
    public:

    Game(){}

    Game(Board board, vector<Player> players) 
    {
        this->board = board;
        this->players = players;
        status = "running..";
    }

    bool makeMove(int row,int col,int playerType)
    {
        vector<vector<int>> gameBoard = board.getBoard();
        if(row<0 || col<0 || row>=board.getBoardSize() || col>=board.getBoardSize() || gameBoard[row][col]!=-1) return 0;

        gameBoard[row][col]=playerType;
        board.setBoard(gameBoard);
        return 1;
    }

    string getStatus()
    {
        return status;
    }

    void showUpdatedBoard()
    {
        vector<vector<int>> myBoard = board.getBoard();

        for(int i=0;i<myBoard.size();i++)
        {
            for(int j=0;j<myBoard.size();j++)
            {
                cout<<myBoard[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    bool checkStatus(int r,int c,int playerType)
    {
        vector<vector<int>> gameBoard = board.getBoard();

        int rowCount=0,colCount=0,diag1Count=0,diag2Count=0;

        //checking same playerType in row and col
        //checking same playerType in diagonals
        //diag1-> top left to bottom right
        //diag2-> bottom left to top right
        int boardSize = board.getBoardSize();
        boardSize--;

        for(int index=0;index<board.getBoardSize();index++)
        {
            if(gameBoard[index][c]==playerType) colCount++;
            if(gameBoard[r][index]==playerType) rowCount++;
            if(gameBoard[index][index]==playerType) diag1Count++;

            if(gameBoard[boardSize--][index]==playerType) diag2Count++;
        }
        

        return rowCount==board.getBoardSize() || colCount==board.getBoardSize() || diag1Count==board.getBoardSize() || diag2Count==board.getBoardSize();

    }
    
    void updateStatus(string result)
    {
        status = result;
    }
};