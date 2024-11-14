#include <iostream>
using namespace std;

		char board[3][3] = { 
					 {'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'} 
					};

//prints board
void displayBoard(){
    cout << " : Tic-Tac-Toe : "<<endl<<endl;
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++)
		{
            cout<<board[i][j]<<" ";
            if (j<2)cout<<"| ";
        }
        cout<<endl;
        if(i<2)cout<< "--|---|--"<<endl;
    }
    cout<<endl;
}
bool checkWin() {
    for(int i=0;i<3;i++) {
		//horizontal check.
        if (board[i][0]==board[i][1]&&board[i][1]==board[i][2])return true;
		//vertical check.
        if (board[0][i]==board[1][i]&&board[1][i]==board[2][i])return true;
    }
	//First Diagonal Check 
    if(board[0][0]/*top left*/==board[1][1]/*Center*/&&board[1][1]==board[2][2]/*bottom right*/)return true;
	// Second Diagonal Check
    if(board[0][2]/*top right*/==board[1][1]/*Center*/&&board[1][1]==board[2][0]/*bottom left*/)return true;
    return false;
}

bool checkDraw(){
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
        	//check empty or not . if it's empty then game continues.
            if (board[i][j]!='X'&&board[i][j]!='O')return false;
    return true;
}

void makeMove(char player) {
    int choice;
    bool validMove=false;
    while (!validMove) {
        cout<<"Player "<<player<<", Enter the NUMBER of the CELL where you want to PLACE your MARK(0-9): ";
        cin>>choice;
        cout<<endl;
        
        int row=(choice-1)/3;
        int col=(choice-1)%3;
        
        if(choice>= 1&&choice<=9&&board[row][col]!='X'&&board[row][col]!='O') {
            board[row][col]=player;
            validMove=true;
        } 
		else {
            cout<< "Invalid move...! Try again."<<endl;
        }
        cin.clear(); // clear error flags
        cin.ignore(10000, '\n'); // discard values
    }
}

int main() {
    char currentPlayer='X';
    bool gameWon=false,draw=false;
    
    while(!gameWon && !draw){
        displayBoard();
        makeMove(currentPlayer);
        gameWon=checkWin();
        if (gameWon) {
            displayBoard();
            cout<<"Player "<<currentPlayer<< " wins the GAME!"<<endl;
            break;
        }
        draw=checkDraw();
        if(draw){
            displayBoard();
            cout << "It's a DRAW/TIE !"<<endl;
            cout << "Game is Over...!"<<endl;
            break;
        }
        currentPlayer=(currentPlayer=='X')?'O':'X';
    }
    
}

