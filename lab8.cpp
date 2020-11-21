// E. Sue
// lab8.cpp
// 11/4/20

// Purpose: To practice searching arrays using linear search
// Input: Word to be searched and whether the program should be repeated
// Processing: read in the data from the file to the array. searchList function
//             to search the list for the word
// Output: The words from the file in order. Index of the first instance
//         of the word searched or a statement that the word wasn't found if
//         the word does not exist.
// Examples: Input: rain
//           Output: The index of the first instance of your word is: 10;
//                   do you want search for another word? (y/n): y
//                   Please input a lowercase word to search for:
//           Input: cool
//           Output: This word does not exist.
//                   do you want to search for another word? (y/n): n

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


// function to search the list
int searchList(string wordList[], int numElems, string val)
{
  int index = 0;
  int pos = -1;
  bool found = false;

  while (index < numElems && !found) {
    if (wordList[index] == val) {
      found = true;                             \
      pos = index;
    }
    index++;
  }
  
  return pos;
}


int main()
{
  //initializing variables
  ifstream inFile;
  const int ARRSIZE = 75;
  string wordList[ARRSIZE];
  int numWords = 0;
  int indOfWord;
  string word;
  string searchFor;
  char runProg = 'y';


  //reading the file data in to the array;
  inFile.open("lab8input.dat");

  if (inFile) {
    while (inFile >> word) {
      wordList[numWords] = word;
      numWords++;
    }

    inFile.close();

    // prints out wordList
    for (int i = 0; i < numWords; i++) {
      cout << wordList[i] << endl;
    }
  
    // program starts
    while (runProg == 'y') {

      // user inputs word to be searched
      cout << endl
           << "Please input a lowercase word to search for: " ;
      cin >> searchFor;

      // searches array for word
      indOfWord = searchList(wordList, numWords, searchFor);
    
      if (indOfWord == -1) { // if word does not exist in the file
        cout << "This word does not exist in this file. \n" << endl;
      } else { // if word does exist in the file
        cout << "The index of the first instance of your word is: " << indOfWord
             << endl << endl;
      }
    
      // asking if the user wants to repeat program
      cout << endl << "do you want search for another word? (y/n): ";
      cin >> runProg;
    }      
  } else {
    cout << "Error opening file." << endl;
  }
  
  return 0;
}
