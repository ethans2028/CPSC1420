// E. Sue
// lab4.cpp
// 10/7/20

// Purpose: This code allows me to practice using nested loops. This program
//          will generate a multiplication table and half-diamond based on the
//          numbers given.
// Input: multiplication and half diamond numbers
// Processing: Multiplication: Used the number designated for multiplication
//             and creates a multiplication table by printing out the multiples
//             of all the numbers less than or equal to itself.
//             Half-Diamond: Uses the number given to create a half diamond of
//             numbers from 1 to the given number in ascending then descending
//             order.
// Output:     Multiplication table and half diamond
// Examples: multiplication = 4; Output:    0    0    0    0    0
//                                          0    1    2    3    4
//                                          0    2    4    6    8
//                                          0    3    6    9   12
//                                          0    4    8   12   16
//           halfDiamond = 6; Output:1
//                                    2
//                                     3
//                                      4
//                                       5
//                                        6
//                                       5
//                                      4
//                                     3
//                                    2
//                                   1
#include <iostream>
#include <iomanip>

using namespace std;


int main() {
  //initializing variables
  int multiplication;
  int halfDiamond;

  //asking for integer to be used in the multiplication table
  cout << "input a number for the multiplication table: ";
  cin >> multiplication;

  //multiplication table
  for (int col = 0; col <= multiplication; col++)
  {

    for (int row = 0; row <= multiplication; row++)
    {
      cout << setw(5) << row*col;
    }

    cout <<  endl;

  }
  cout << endl;

  //asking for integer to be used in half-diamond
  cout << "input a number for the half-diamond: ";
  cin >> halfDiamond;

  //half-diamond
  for (int colUpper = 1; colUpper < halfDiamond; colUpper++)
  {

    for (int spacingUpper = 0; spacingUpper < colUpper; spacingUpper++)
    {
      cout << " ";
    }
    
    cout << colUpper << endl;
  }
  
  for (int colLower = halfDiamond; colLower > 0; colLower--)
  {

    for (int spacingLower = colLower; spacingLower > 0; spacingLower--)
    {
      cout << " ";
    }

    cout << colLower << endl;
    
  }
}
