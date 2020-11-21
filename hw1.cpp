// E. Sue
// hw1.cpp
// 9/23/20

// Purpose: Make a fun game similar to madlib which asks the user to input
// words, then prints out a paragraph including the inputted words.

// Input: words

// Output: A paragraph with certain places filled in using the words inputted
// by the user

// Examples: name: Ethan
//           hobby: swimming
//           friendVerb: sit
//           school: Seattle University
//           year: 2024
//           professorVerb: eats

//           Output: My name is Ethan. One of my favorite hobbies is swimming.
//           I absolutely hate when my friends sit, but that won’t stop me
//           from spending time with them. I currently attend Seattle
//           University, and I am the class of 2024.
//           My professor constantly eats in class. I hope you enjoyed
//           learning about me. Until next time!

#include <iostream>
#include<string>

using namespace std;

int main()
{
  //variables for the words the user will input
  string name, hobby, friendVerb, school, professorVerb;
  int year;
  
  //Welcome Message
  cout << "\n" << "hello player! Welcome to Ethan's word game. To play, input "
       << "words based on the type of word asked. These words will be used to "
       << "fill in the blanks in a paragraph. Afterwards, this paragraph "
       << "including your words will printed. Have fun!\n" << endl;

  //Asking the user to input their words
  cout << "Input your name or any name\n";
  getline(cin, name);
  cout << "Input a hobby\n";
  getline(cin, hobby);
  cout << "Input an adjective\n";
  getline(cin, friendVerb);
  cout << "Input a school\n";
  getline(cin, school);
  cout << "Input a year\n";
  cin >> year;
  cout << "Input another adjective\n";
  cin >> professorVerb;
  

  
   //Printing the paragraph including the words inputted.
  cout << endl << "My name is " << name << ". One of my favorite hobbies is "
       << hobby << ". I absolutely hate when my friends " << friendVerb
       << " , but that won’t stop me from spending time with them. I currently"
       << " attend" << school << ", and I am the class of " << year
       << ". My professor constantly " << professorVerb <<  " in class."
       << "I hope you enjoyed learning about me. Until next time!\n";

  //Goodbye Message
  cout << endl << "I hope you enjoyed the game! Please play again soon."
  << " Goodbye!\n";
}
