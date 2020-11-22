// E. Sue
// hw4.cpp
// 10/27/20

// Purpose: Allow user to play the Memory Game. 
// Input: row and column of card they want to flip. y/n if they want to
//        start the game over
// Processing: randomNum function picks a random number which is used to
//             choose one of the card sets available
//             wait function sets a clock to give the player a short time
//             period to memorize the cards
//             Initializing cardStatus array values and changing the values
//             if they are matched, flipped, or unflipped
// Output: Welcome Message, Goodbye message, card layouts, messages letting
//         player know if their cards matched or did not match, timer message,
//         and values of the cards flipped
// Examples: Input: 1 1
//          Output: F * * *
//                  * * * *
//                  * * * *
//           Input: 1 2
//          Output: F D * *
//                  * * * *
//                  * * * *
//                  The two cards aren't a match
//                  Pausing for 5 seconds
//                  * * * *
//                  * * * *
//                  * * * *
//           Input: 2 1
//          Output: * * * *
//                  D * * *
//                  * * * *
//           Input: 1 2
//          Output: * D * *
//                  D * * *
//                  * * * *
//                  The two cards are a match!
//                  * _ * *
//                  _ * * *
//                  * * * *

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

// card layout variables
const int RSIZE = 3;
const int CSIZE = 4;

// welcome function
void welcome()
{
  cout << endl
       << "Welcome to the matching game! Your goal is to match all the cards "
       << "in as few rounds as possible. To play, choose the row and column "
       << "of the card you want to flip. After you have flipped 2 cards, a "
       << "5 second timer will start before flipping the cards back over, "
       << "ending that turn ends. Cards that can be picked are denoted by an "
       << "asterick, while cards that can no longer be chosen due to being "
       << "matched are denoted by an understore. When you win the game, the "
       << "number of turns it took you to win is displayed on the screen. You "
       << "can play this game as many times as you like. Good Luck Player!\n"
       << endl;
  
  cout << "the game is starting!\n" << endl;
    
}

// wait function
void wait(int seconds)
{
  clock_t endwait;
  endwait = clock() + seconds * CLOCKS_PER_SEC;

  while (clock() < endwait) {
    
  }
}

// randomizer to tell program which card order to choose
int randomNum()
{
  int upperLim = 2;
  int lowerLim = 1;
  int randomNum = rand()%(upperLim - lowerLim + 1) + lowerLim;
  return randomNum;

}

// Function Printing the Cards
void printLayout (char status[][4], char cardVals[][4])
{
  for (int r = 0; r < RSIZE; r++) {
    for (int c = 0; c < CSIZE; c++) {
      if (status[r][c] == '*') { // if true, card has not been flipped
        cout << " * ";
      } else if (status[r][c] == '_') { // if true, card has been matched
        cout << " _ ";
      } else {
        cout << " " << cardVals[r][c] << " "; // if true, player flipped card
      }
    }
    cout << endl;
  }
  cout << endl;
}

int main()
{
  ifstream inFile;
  int randomFile, turnsTaken = 0, cardsRemaining = 12;
  int rChosen1, cChosen1, rChosen2, cChosen2;
  char startGame = 'y';
  char cards[RSIZE][CSIZE];
  char cardStatus[RSIZE][CSIZE];

  // welcome message
  welcome();
  
  // code running the game
  while (startGame == 'y') {

    // deciding which file to use
    randomFile = randomNum();
    if (randomFile == 1) { 
      inFile.open("p4data1.dat");
    } else {
      inFile.open("p4data2.dat");
    }

    // reading the file's data into the array and sets all card statuses to
    // unflipped. '*' for cardStatus array represents an unflipped variable
    for (int r = 0; r < 3; r++) {
      
      for (int c = 0; c < 4; c++) {
        
        inFile >> cards[r][c];
        cardStatus[r][c] = '*';
      }
    }
    
    // printing the function
    printLayout(cardStatus, cards);

    // game continues only if all cards have not been chosen
    while (cardsRemaining > 0) {
      // ask user to choose a card
      cout << "choose the row and column of the card you would like to flip: ";
      cin >> rChosen1 >> cChosen1;
      cardStatus[rChosen1 - 1][cChosen1 - 1] = 'f';
      printLayout(cardStatus, cards);

      cout << "choose the row and column of the card you would like to flip: ";
      cin >> rChosen2 >> cChosen2;
      cardStatus[rChosen2 - 1][cChosen2 - 1] = 'f';
      printLayout(cardStatus, cards);
    
      // check to see if equal
      if (cards[rChosen2-1][cChosen2-1] == cards[rChosen1-1][cChosen1-1]) {
        cardStatus[rChosen1 - 1][cChosen1 - 1] = '_';
        cardStatus[rChosen2 - 1][cChosen2 - 1] = '_';
        cout << "The two cards are a match!\n" << endl;

        cardsRemaining-=2; // if equal, subtract two cards from cardsRemaining
      
      }
      else { // set a timer, if not equal
        cout << "The two cards aren't a match\n"
             << "Pausing for 5 seconds" << endl;
        wait(5);

        // when timer finishes I need to flip both over and start over
        cardStatus[rChosen1 - 1][cChosen1 - 1] = '*';
        cardStatus[rChosen2 - 1][cChosen2 - 1] = '*';
      
      }
      printLayout (cardStatus, cards);
    
      // add one to turnsTaken after the turn ends
      turnsTaken++;
    }

    // if no cards remain, congratulate user ask if they want to play again
    cout << "Congratulations, you won the game!\n";
    cout << "Your final score (turns taken) is: " << turnsTaken << endl << endl;
    cout << "Would you like to play again? (y/n): ";
    cin >> startGame;

  }
    
  cout << endl << "thanks for playing! Goodbye!" << endl;
}
