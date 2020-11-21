// E. Sue
// hw3.cpp
// 10/21/20

// Purpose:
// Input:
// Processing:
// Output:
// Examples:

#include <iostream>
#include <string>

using namespace std;



// Welcome function
void welcome ()
{
  // Welcome message
  cout << "Welcome players to the Chutes and Ladders game! This is a two "
       << "player game. Each player starts at block 0 and tries to get to "
       << "block 100 before the other player. Each player spins a spinner "
       << "which can land on any number between 1 and 6. That player then "
       << "moves the corresponding number of blocks. However, if you land on "
       << "a chute, then you will fall down to a lower block, where as "
       << "landing on a ladder will allow you to skip a certain amount of "
       << "blocks. In order to win, you must land exactly on block 100. "
       << "Good luck player!\n" << endl;
}

// checking if the player landed on a ladder
int ladderCheck(int playerPos)
{

  bool landsOnLadder = true;
  
  if ( playerPos == 1) {
    playerPos+=37;
    
  } else if ( playerPos == 4) {
    playerPos+=10;
    
  } else if ( playerPos == 9) {
    playerPos+=12;

  } else if ( playerPos == 23) {
    playerPos+=21;

  } else if ( playerPos == 28) {
    playerPos+=56;

  } else if ( playerPos == 36) {
    playerPos+=8;

  } else if ( playerPos == 51) {
    playerPos+=15;

  } else if ( playerPos == 71) {
    playerPos+=19;
    
  } else if ( playerPos == 80) {
    playerPos+=20;

  } else {
    landsOnLadder = false;
  }
  // checking if player landed on a ladder
  if (landsOnLadder == true) {
    cout << "You landed on a ladder!" << "You're new position is " << playerPos;
    return playerPos;
  } else {
    cout << "You landed on " << playerPos;
    return playerPos;
  }

}

// checking if the player landed on a chute
int chuteCheck(int playerPos)
{
  
  bool landsOnChute = true;

  if ( playerPos == 98) {
    playerPos-=20;
    
  } else if ( playerPos == 95) {
    playerPos-=20;

  } else if ( playerPos == 93) {
    playerPos-=20;

  } else if ( playerPos == 87) {
    playerPos-=63;

  } else if ( playerPos == 64) {
    playerPos-=4;

  } else if ( playerPos == 62) {
    playerPos-=43;

  } else if ( playerPos == 56) {
    playerPos-=3;

  } else if ( playerPos == 49) {
    playerPos-=38;

  } else if ( playerPos == 48) {
    playerPos-=22;

  } else if ( playerPos == 16) {
    playerPos-=10;

  } else {
    landsOnChute = false;
  }

  // checking if player landed on a chute
  if (landsOnChute == true) {
    cout << "You landed on a chute!" << "You're new position is " << playerPos;
    return playerPos;
  } else {
    cout << "You landed on " << playerPos;
    return playerPos;
  }
  
}

// Spin function
int spin (int block) {
  int randomNum = rand() % (6-1) + 1;
  cout << "your spin was " << randomNum << endl;
  if ((block+randomNum) > 100) {
    cout << "Your spin landed you above 100. Try again\n";
    return block;
  } else {
    block+=randomNum;
    cout << "your new position is " << block;
    return block;
  }
}

int main()
{

  //initializing variables for use
  string player1;
  string player2;
  int player1Block = 0, player2Block = 0, currentPlayer = 1;

  // Welcome message
  welcome();

  // Getting player names
  cout << "Input the name of Player 1: ";
  cin >> player1;
  cout << "Input the name of Player 2: ";
  cin >> player2;

  // Actually Running the Game
  if (currentPlayer == 1) { // Player1's Turn
    cout << "It is " << player1 << "'s turn\n";

    player1Block += spin(player1Block);

    // Checking if current player won the game
    if (player1Block == 100) {
      cout << "player1 won the game! Congratulations\n";
      return 0;
    } else { //if player did not win, continue with the game
      currentPlayer++; // sets current player to 2
    }

   } else { // Player2's Turn
     cout << "It is " << player1 << "'s turn\n";

     player2Block += spin(player2Block);

    // Checking if current player won the game
    if (player1Block == 100) {
      cout << "player2 won the game! Congratulations\n";
      return 0;;
    } else { //if player did not win, continue with the game
      currentPlayer--; // sets current player to 1
    }

   }

   return 0;
 }
