// E. Sue
// lab7.cpp
// 10/28/20

// Purpose: The purpose of this lab is to practice using two-dimensional arrays
//          and iterating through them.
// Input: row, column, and value for the item location. row/column must be
//        between 1 and 3 and cannot be an item location that's value has
//        already been changed.
// Processing: Summing all the inputted values.
// Output: Statements telling user to input row, column, and values.
//         Statements telling user if they inputted an invalid row/column
//         Summation of all values inputted.
// Examples: Input: 1 1 15
//           Output: 15  0  0
//                    0  0  0
//                    0  0  0
//           Input: 0 1 10
//           Output: You've chosen an invalid row or column. Pick again
//           Input: 1 0 10
//           Output: You've chosen an invalid row or column. Pick again


#include <iostream>
#include <iomanip>

using namespace std;

// function checking if the item value has been changed
bool itemChangedCheck(int row,int column,int arr[][3]) {
  if (arr[row-1][column-1] == 0) {
    return true;
  } else {
    cout << "That item already has a value. Pick a different item\n";
    return false;
  }
  return false;
  
}


int main ()
{

  //initializing variables
  const int R = 3;
  const int C = 3;
  int rowChosen, columnChosen, valueChosen, numItemsChanged = 0, arrSum = 0;
  int arr[R][C];
  int arrItemsChanged[R][C];

  // setting up initial values of arrays
  for (int row = 0; row < R; row++) {
    for (int col = 0; col < C; col++) {
      arr[row][col] = 0;
      arrItemsChanged[row][col] = 0;
    }
  }
  
  // running the program
  while(numItemsChanged < R*C) {
    
    cout << "Please input a row and column as well as a value you would like "
         << "to store at that item location: ";
    cin >> rowChosen >> columnChosen >> valueChosen;

    // checking if row and column inputted are valid
    if ( (rowChosen>=1 && rowChosen<=3) && (columnChosen>=1) && (columnChosen<=3)){
      // checking if user has already inputted a value for the item
      if (itemChangedCheck(rowChosen, columnChosen, arrItemsChanged)){ 
        
        arr[rowChosen-1][columnChosen-1] = valueChosen;
        arrItemsChanged[rowChosen-1][columnChosen-1] = 1;
        numItemsChanged++;

        // printing the array after each input
        for (int row = 0; row < R; row++) {
          for (int col = 0; col < C; col++) {
            cout << setw(10) << arr[row][col];
          }
          cout << endl;
        }
      }
      
    }
    else {
      cout << "You've chosen an invalid row or column. Pick again\n";
    }
     
  }  

  // summing the values inputted by the user
  for (int row = 0; row < R; row++) {
    for (int col = 0; col < C; col++) {
      arrSum+=arr[row][col];
    }
  }
  cout << "all items have values now. The sum of these values is: " << arrSum << endl;
  return 0;
}
