#include <iostream>
#include <string>
 
//using namespace std; 

int main() {
    char board[3][3]= {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '},
        
    };

    std::string moveVert;
    std::string moveHori; 
    
    const char playerX = 'X';
    const char playerO = 'O'; 
    char winner = ' ';

    char currentPlayer = playerX;
     
    int j = 9;

    while (j <= 9 && j >= 0) {
        int row = -1;
        int column = -1;
        for (int i = 0; i < 3; i++) {
            std::cout << "              " << "   " << "|" << "   " << "|" << "   " << std::endl;
            std::cout << "              " << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " " << std::endl;
            std::cout << "              " << "   " << "|" << "   " << "|" << "   " << std::endl;
            if (i != 2) {
                std::cout << "              " << "---" << "|" << "---" << "|" << "---" << std::endl;
            }
        }

        if (winner != ' ') {
            std::cout << "The winner is: Player " << winner << std::endl;
            break;
        } 

        std::cout << "Current player is:" << currentPlayer << std::endl; 
        while(true){
            std::cout << "Enter position using (Upper/Middle/Lower) (Left/Middle/Right): "; 
            std::cin >> moveVert >> moveHori;
            
            if (moveVert == "Upper"){
                row = 0;
            } else if (moveVert == "Middle") {
                row = 1;
            } else if (moveVert == "Lower") {
                row = 2;
            }
            if (moveHori == "Left") {
                column = 0;
            } else if (moveHori == "Middle") {
                column = 1; 
            } else if (moveHori == "Right") {
                column = 2; 
            }

            if ((moveHori != "Right" && moveHori != "Left" && moveHori != "Middle") || (moveVert != "Upper" && moveVert != "Middle" && moveVert != "Lower")) {
                   std::cout << "Invalid input. Try again" << std::endl; 
            } 
            else if (board[row][column] != ' ') {
                std::cout << "You cheater, this tile is full >:[" << std::endl; 
            } 
            else {break;}
            
        }   

        board[row][column] = currentPlayer;
        j -= 1;
        currentPlayer = (currentPlayer == playerX)  ? playerO: playerX;

        //row

        //diagonal 
        if (((board[0][0] == board[1][1] &&  board[0][0] == board[2][2]) && board[1][1] != ' ') || ((board[2][0] == board[1][1] && (board[2][0] == board[0][2]) && board[1][1] != ' '))) {
                winner = board[1][1];
            }  

        for (int horizontal = 0; horizontal < 3; horizontal++){
            if (board[horizontal][0] == board[horizontal][1] && board[horizontal][0] == board[horizontal][2] && board[horizontal][0] != ' '){
                winner = board[horizontal][0];
            }  
        }

        //column
        for (int vertical = 0; vertical < 3; vertical++){
            if ((board[vertical][0] == board[vertical][1] && board[vertical][0] == board[vertical][2]) && board[vertical][0] != ' '){
                winner = board[vertical][0];
            }  
        }
        
    }
   
}