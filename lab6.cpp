// E. Sue
// lab6.cpp
// 10/21/20

// Purpose: I am practicing using one-dimensional arrays.
// Input: filename
// Processing: checks if number being read is an even, odd, or negative
//             number using if else statements. Then, it stores
//             the number in the corresponding array.
// Output: Inputs from each array.
// Examples: Input: lab6input.dat
//           Output: evenNum array inputs: 20 18 4 30 100 70 4 20
//                   oddNum array inputs:15 3 35 35 101 11
//                   negNum array inputs: -9 -6 -24 -15 -40 -6 -9 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  //initializing file to be read from
  ifstream inputFile;
  string fileName;

  cout << "Input your file name: ";
  cin >> fileName;
  inputFile.open(fileName);

  int evenInd = 0, oddInd = 0, negInd = 0, currentNum;

  //initializing the arrays
  int evenNum[30];
  int oddNum[30];
  int negNum[30];

  if (inputFile){

    while (inputFile >> currentNum) {

      //checking which array to put the current number in
      if ((currentNum > 0) && (currentNum % 2 == 0)){

        evenNum[evenInd] = currentNum;
        evenInd++;
        
      } else if (currentNum > 0){

        oddNum[oddInd] = currentNum;
        oddInd++;

      } else if (currentNum < 0){

        negNum[negInd] = currentNum;
        negInd++;
        
      }
      
    }

    inputFile.close();
  } else {
    cout << "Error opening the file\n";

  }
  
  //printing evenNum array inputs
  cout << "evenNum array inputs: " << endl;
  for (int i = 0; i < evenInd; i++) {
    
    cout << evenNum[i] << ", " << i << endl;
    
  }
  cout << endl;

  //printing oddNum array inputs
  cout << "oddNum array inputs: " << endl;
  for (int i = 0; i < oddInd; i++) {

    cout << oddNum[i] << ", " << i << endl;


  }
  cout << endl;


  //printing negNum array inputs
  cout << "negNum array inputs: " << endl;
  for (int i = 0; i < negInd; i++) {
    cout << negNum[i] << ", " << i << endl;

  }
  cout << endl;


  return 0;
}
