// E. Sue
// lab9.cpp
// 11/13/20

// Purpose: The purpose of this lab is to practice using structs and an array
//          of structs to store data. I will also be practicing using
//          selection sort. 
// Input: None
// Processing: Print out records, find student records with highest gpa, and
//             sort records alphabetically
// Output: Student records with highest gpa, all student records before
//         sorting, and all student records after sorting
// Example: Students who have the highest GPA are:
//                 Jon s980469026 145 3.85
//               Helen s124598670  60 3.85
//
//          records before sorting:
//              Wesley s012980520  30 3.50
//               Allen s094589012 120 3.29
//                 Jon s980469026 145 3.85
//                Luck s098419346 180 3.60
//               Helen s124598670  60 3.85
//               Chloe s123309870  60 3.00
//
//          records after sorting the names in alphabetical order:
//               Allen s012980520  30 3.50
//               Chloe s012980520  30 3.50
//               Helen s980469026 145 3.85
//                 Jon s098419346 180 3.60
//                Luck s098419346 180 3.60
//              Wesley s012980520  30 3.50



#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct Student // Student struct to group variables for every students
{
    string name;
    string stuID;
    int credits;
    double gpa;
};

const int ARRSIZE = 150;

// Print Student Function
void printStudent(Student arr[], int studentNum)
{
  cout << setw(10) << arr[studentNum].name // prints student name
       << setw(11) << arr[studentNum].stuID // prints student id
       << setw(4) << arr[studentNum].credits // prints student credits
       << fixed << showpoint << setprecision(2) 
       << setw(5) << arr[studentNum].gpa << endl; // prints student gpa
}

// Highest GPA function
void highestGPA(Student arr[], int arrSize)
{
  double highestGPA = arr[0].gpa; // set initial highest gpa
  for (int i = 1; i <= arrSize; i++) { // for all designated students
    if (arr[i].gpa > highestGPA) { // checks if current student gpa > highest
      highestGPA = arr[i].gpa; // set new highest if true
    }
  }

  cout << "Students who have the highest GPA are:\n"; 
  for (int i = 0; i <= arrSize; i++) { // for all designated students
    if (arr[i].gpa == highestGPA){
      printStudent(arr, i); // print records
    }
  }
  cout << endl;
}

// list before sort
void beforeSort(Student arr[],int arrSize)
{
  cout << "records before sorting: \n";
  for (int i = 0; i < arrSize; i++) { // for all designated students
    printStudent(arr, i); // print records for current student
  }
  cout << endl;
}

// Alphabet sort function
void sortStudents(Student arr[],int arrSize)
{
  int startScan, minIndex;
  string minValue;
  cout << "records after sorting the names in alphabetical order: \n";

  for (startScan = 0; startScan < arrSize; startScan++) {
    minIndex = startScan;
    minValue = arr[startScan].name;
    for (int i = startScan+1; i < arrSize; i++) { //gets min value
      if(arr[i].name < minValue) {
        minValue = arr[i].name;
        minIndex = i;
      }
    } // exchange smallest element of this path w/ element at start position
    arr[minIndex] = arr[startScan];
    arr[startScan].name = minValue;
  }

}

int main()
{
  ifstream inFile;
  
  // to store all data for a student before data is sorted into a struct
  string tempStuData;
  Student stuList[ARRSIZE];

   //read in the file
  inFile.open("lab9input.dat");

  // initializing variables
  int numStudent = 0;
  string tempName;
  string tempStuID;
  int tempCredits;
  double tempGPA;

  // reading in student data to array
  while(inFile >> tempName >> tempStuID >> tempCredits >> tempGPA) {
    stuList[numStudent].name = tempName;
    stuList[numStudent].stuID = tempStuID;
    stuList[numStudent].credits = tempCredits;
    stuList[numStudent].gpa = tempGPA;
    numStudent++;
  }
  inFile.close();
  
  // call function to find and print student(s) with highest GPA
  highestGPA(stuList, numStudent);
  
  // Print entire list of records before sort
  beforeSort(stuList, numStudent);
  
  // sort list
  sortStudents(stuList, numStudent);

  // print sorted list
  for (int i = 0; i < numStudent; i++) { // for all designated students
    printStudent(stuList, i); // print records for current student
  }
  cout << endl;

}
