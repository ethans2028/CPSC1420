// E. Sue
// lab5.cpp
// 10/15/20

// Purpose: This lab is meant to allow me to practice declaring, implementing,
//          and invoking functions.
// Input: The user inputs a number between 5 and 25. At the end of the program,
//        the user inputs either 'y' or 'n' to restart or end the program.
// Processing: The number is used in the function "summation" and all numbers
//             from 1 to the inputted value are added together.
// Output: The user's inputted value and the summation value.
// Examples: x: 5 Output: 5
//                        15
//                        Would you like to restart the program?
//     runProg: y Output: Please input a number between 5 and 25:
//           x: 2 Output: That is not a valid number. Please input a number
//                        between 5 and 25.
//           x: 6 Output: 6
//                        21
//                        Would you like to restart the program?
//     runProg: n Output: Goodbye!

#include <iostream>
using namespace std;

// function declarations
void welcome();
void goodbye();
int input();
int summation(int);


int main()
{
  char runProg = 'y';

  welcome();

  while (runProg == 'y') {
    int x = input();

    cout << x << endl;
    cout << summation(x) << endl;
    
    cout << "Would you like to restart the program? (y/n)\n";
    cin >> runProg;

  }
  
  goodbye();
}



// welcome function
void welcome ()
{
  cout << "Hello there user!\n";

}

// goodbye function
void goodbye ()
{
  cout << "Goodbye!\n";
}

// input function
int input ()
{
  int num;
  cout << "Input a number between 5 and 25: \n";
  cin >> num;
  
  while (num < 5 || num > 25) {
    cout << "That is not a valid number. Please input a number between 5 and "
         << "25\n";
    cin >> num;
  }
  
  return num;
}

// summation function
int summation (int x)
{
  int sumNum = 0;
  
  for (int i = 1; i <= x; i++){
    sumNum += i;
  }
  return sumNum;
  
}
