
#include<bits/stdc++.h>
using namespace std;


#include "game.cpp"

int main()
{
    Player player1(1,"babu bhaiya",1);
    Player player2(2,"raju bhai",0);

    Board board;
    board.setBoardSize(3);
    
    Game game(board,{player1,player2});
    
    int flag=1; //player 1 turn first
    int totalTurns = board.getBoardSize()*board.getBoardSize();

    while(1)
    {
        if(!totalTurns) 
        {
            game.updateStatus("Draw!!");
            break;
        }
        
        Player player = flag ? player1 : player2;

        cout<<player.getPlayerName()<<" turn..\n Please enter row and col number to make a move \n";
        int r,c; cin>>r>>c;

        if(!game.makeMove(r,c,player.getPlayerType()))
        {
            cout<<"Please make a valid move!\n";
        }
        else
        {
            game.showUpdatedBoard();
            if(!game.checkStatus(r,c,player.getPlayerType()))
            flag=!flag;
            else
            {
                cout<<player.getPlayerName()<<" wins!!";
                game.updateStatus(player.getPlayerName()+" wins!!");
                break;
            }
            
        }
        totalTurns--;
        
    }

    return 0;
}