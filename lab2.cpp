// E. Sue
// lab2.cpp
// 9/23/20

// Purpose: This program helps me practice using input, output, and
// mathematical operations such as division and modulus for various data types.

// Input: one word, two integers, two float numbers. The second integer must
// not be zero

// Processing: Store all inputted data properly. Then, print out the word
// inputted, divide the first integer by the second, use the modulus operation
// on the integers, and divide the first float by the secondd.

// Output: Print the word, the result of dividing and using modulus on the
// integers, and the result of using division on the float values.

// Examples: word: cool, Output: The word you enetered was: cool
//        int1: 4
//        int2: 2, Output: 4, 0
//        float1: 9
//        float2: 4, Output: 2.25



#include <iostream>
#include <string>


using namespace std;


int main()
{
  //creating all my variables
  string word;
  int int1, int2;
  double divisionInt;
  int remainderInt;
  float float1, float2;
  double divisionFloat;

  //Asking the user to input a word
  cout << "Input a word\n";
  getline(cin, word);
  cout << "The word you entered was: " << word << endl;

  //Asking the user to input 2 integers
  cout << "input two integers\n";
  cin >> int1;
  cin >> int2;

  //Division and Modulus operations for the ints
  divisionInt = int1 / int2;
  cout << "The result of dividing " << int1 << " by " << int2 << " is "
       << divisionInt << endl;
  
  remainderInt = int1 % int2;
  cout << "The remainder of dividing " << int1 << " by " << int2 << " is "
       << remainderInt << endl;

  //Asking the user to input 2 float
  cout << "input two float point numbers\n";
  cin >>  float1;
  cin >> float2;

  //Division operation for the floats
  divisionFloat = float1 / float2;
  cout << "The result of dividing " << int1 << " by " << int2 << " is "
       << divisionFloat << endl;
  return 0;
}
