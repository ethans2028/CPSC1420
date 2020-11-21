// E. Sue
// lab3.cpp
// 9/30/20

// Purpose: This lab is teaching us to practice using if and while loops.
//          The program tells the user if one of the numbers inputted is
//          a multiple of the other number and, if so, what the other factor is
// Input: two integers
// Processing: Check if int1 is greater than int2 and int1%int2 is equal to 0.
//             If both are true, then calculate int1/int2 to find the other
//             factor.
// Output: If true, a statement saying yes int1 is a multiple of int2 along
//         with the other factor. If false, a statement will print saying that
//         int1 is not a multiple of int2
// Examples: int1: 9
//           int2: 3 Output: Yes, 9 is a multiple of 3, and the other factos is
//                           3.
//           int1: 9
//           int2: 5 Output: No, 9 is not a multiple of 5.

#include <iostream>

using namespace std;

int main()
{
  // initializing variables
  int int1, int2;
  int factor = 0;
  char continueProgram = 'y';
  

  while (continueProgram == 'y') {

    // asking for the user to input 2 integers
    cout << "Input 2 integers: ";
    cin >> int1 >> int2;
    cout << endl;

    // checking if int1 is multiple of int2
    if ((int1 > int2) && ((int1%int2)==0)) {
      factor = int1/int2;
      cout << "Yes, " <<  int1 << " is a multiple of " << int2
           << ", and the other factor is " << factor << "." << endl;
    } else {  
      cout << "No, " << int1 << " is not a multiple of " << int2 << "."
           << endl;
    }
    
    //continue to check numbers?
    cout << "Do you want to continue (y/n): ";
    cin >> continueProgram;
    cout << endl;

  }
}
