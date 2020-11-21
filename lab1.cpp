// E. Sue
// lab1.cpp
// 9/18/20

// Purpose: This program asks the user to input their name, favorite color, and
// email. Then, it prints out the data to the terminal.

// Inputs: name, favorite color, email

// Processing: Store the inputs in their corresponding variables
// (name input goes to name variable, favorite color input stored in favColor
// variable, and email input is stored in the email variable)

// Output: Prints the information type followed by the information inputted by
// the user

// Examples: What is your name? John Smith, name: John Smith
//           What is your favorite color? Blue, Favorite Color: Blue
//           What is your email? john2020@gmail.com, Email: john2020@gmail.com


#include <iostream>
#include <string>

using namespace std;

int main()
{
     string name, favColor, email;
     cout << "What is your name?\n" << endl;
     getline(cin, name);
     cout << "What is favorite color?\n" << endl;
     getline(cin, favColor);
     cout << "What is your email?\n" << endl;
     getline(cin, email);
     cout << "Name: " << name << endl;
     cout << "Favorite Color: " << favColor << endl;
     cout << "Email: " << email << endl;
        
}
