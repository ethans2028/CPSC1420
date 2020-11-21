// E. Sue
// hw2.cpp
// 9/29/20

// Purpose: This program plays a random number game with the user. It chooses a
//          random number based on the upper and lower limits inputted by the
//          user. The user can decide whether or not to 
// Input: upperLim, lowerLim, playAgain
// Processing: Uses the upperLim and lowerLim values to create a random number
//             which the user must try to guess.
//             Function used: rand()%(upperLim - lowerLim + 1) + lowerLim;
//             
// Output: It outputs whether the player's guess was too high, low, or correct.
// Examples:
//         upperLim: 100
//         lowerLim: 0
//         randomNum: 40
//         guessedNum: 30 Output: Your guess was too high. Guess again!
//         guessedNum: 50 Output: Your guess was too low. Guess again!
//         guessedNum: 40 Output: You're correct!
//                                Do you want to play again?
//         playAgain: n Output: Thanks for playing! Goodbye.


#include <iostream>
#include <cstdlib>

using namespace std;

int main ()
{
  //initialize variable 
  int upperLim, lowerLim, randomNum, guessedNum;
  char playAgain;
  bool guessCorrect = false;
  bool play = true;

  while (play == true){
    guessCorrect = false; 
    //Welcome
    cout << endl
         << "Welcome to Ethan's guessing game! Your mission, if you choose to "
         << "accept it, is to guess the random number I've generated based on "
         << "the lower and upper limit numbers you will specify. Don't worry, "
         << "I'll let you know whether your number is too high or low and you "
         << "have an unlimited number of guesses. Have fun!\n" << endl; 


    //Asking for a the limits
    cout << "Enter the lower and upper limits (in this order) here: ";
    cin >> lowerLim >> upperLim;
    cout << endl; 
 
    //generate random number to be guessed
    randomNum = rand()%(upperLim - lowerLim + 1) + lowerLim; 
 
    while (guessCorrect == false){
      //user guesses the number
      cout << "What number do you think I've chosen? ";
      cin >> guessedNum;

      //checking if guessed number is correct
      if (guessedNum > randomNum){
        cout << "Your guess was too high. Guess again!\n";
             
      } else if (guessedNum < randomNum){
        cout << "Your guess was too low. Guess again!\n";

      } else{
        cout << "You're correct!\n";
        
        cout << "Would you like to play again? (y/n): ";
        cin >> playAgain;
                                                \
        //play again loop
        if (playAgain == 'n'){ 
          cout << endl << "Thanks for playing! Goodbye.\n";
          guessCorrect = true;
          play = false;

        } else{
          guessCorrect = true;
        }
         
      }
    }
  }  
}
