// E. Sue
// hw5.cpp
// 11/16/20

// Purpose: This program creates an inventory program which tracks all items
//          sold by Everything Electronics! The program stores the name,
//          manufacturer, quantity in stock, minimum quantity, and cost of each
//          item. The user can ask the system to print either an inventory or
//          reorder report.
// Input: file name, reportType/quit, and whether to order another report
// Processing: opening the designated file, reading the file's data to the
//             struct array, sorting the items in alphabetical order, totalling
//             the number of items in the inventory/reorder lists, computing
//             the total value of each item (totalVal = quant*cost), finding
//             the total order quantity (totalQuant += quant), 
//             finding the total value of all items (valAll += totalVal),
//             finding the total quantity needed to order of each item
//             (orderAmt = min-quant), finding the total cost of ordering
//             the quantity needed for each item (itemOrderCost=orderAmt*cost),
//             finding the total cost of a reorder(totalCost += itemOrderCost),
//             and checking if the user wants another report or quit.
// Output: Welcome message, goodbye message, inventory list with statistics,
//         and reorder report with statistics.
// Example: 
// Welcome to Everything Electronic!
//
// This inventory program stores the name, manufacturer, quantitity,
// minimum quantity, and individual cost of each item sold by
// Everything Electronic! You may request an inventory report listing
// the inventory information and total value of all items.
// You may also request a reorder report which lists items which must
// be restocked.
//
// input your file's name: p5input.dat
// list after ordering:
//            Capacitor              Ohmite        70        80                0.73
//         Oscilloscope              EBrand         2         1              100.00
//             Resistor              Ohmite       100       250                0.05
// Would you like an inventory report, reorder report, or quit the program? (i/r/q): r
//
//
//                                    Reorder Report
//
// Item        Manufacturer       Quantity   Minimum     Order   Cost($)
// Capacitor           Ohmite         70        80        10        7.30
// Resistor            Ohmite         100       250       150       7.50
//
// Number of different items to order: 2
// Total number to order: 160
// total value of all items: $14.80
//
//
// Would you like another report? (y/n): y
// Would you like an inventory report, reorder report, or quit the program? (i/r/q): i
//
//
// Inventory Report
//
// ItemManufacturer        Quantity       Cost Each($)   Total Value($)
// Capacitor           Ohmite         70        0.73           51.10
// Oscilloscope        EBrand         2         100.00         200.00
// Resistor            Ohmite         100       0.05           5.00
//
// Number of different items: 3
// Total quantity: 172
// total value of all items: $256.10
//
//
// Would you like another report? (y/n): y
// Would you like an inventory report, reorder report, or quit the program? (i/r/q): q
//
// Goodbye!


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// item struct
struct Item
{
  string name;
  string manufacturer;
  int quant, min;
  double cost;
};

// constant for inventory array
const int ARRSIZE = 150;


// Welcome function
void welcome()
{
  cout << endl << endl
       << "Welcome to Everything Electronic! " << endl << endl
       << "This inventory program stores the name, manufacturer, quantitity, "
       << endl
       << "minimum quantity, and individual cost of each item sold by "
       << endl
       << "Everything Electronic! You may request an inventory report listing "
       << endl
       << "the inventory information and total value of all items. "
       << endl
       << "You may also request a reorder report which lists items which must "
       << endl
       << "be restocked." << endl << endl;
}


// Goodbye Function
void goodbye()
{
  cout << endl << "Goodbye!\n" << endl;
}


// Alphabet sort function
void sortItems(Item arr[],int arrSize)
{
  int startScan, minIndex;
  string minValName;
  Item itemInfo;

  cout << "list after ordering: " << endl;

  for (startScan = 0; startScan < arrSize; startScan++) {
    minIndex = startScan;
    minValName = arr[startScan].name;
    itemInfo = arr[startScan];

    for (int i = startScan+1; i < arrSize; i++) { //gets min value
      if(arr[i].name < minValName) {
        minValName = arr[i].name;
        itemInfo = arr[i];
        minIndex = i;
      }
    } // exchange smallest element of this path w/ element at start position
    arr[minIndex] = arr[startScan];
    arr[startScan] = itemInfo;

  }

  for (int i = 0; i < arrSize; i++){
    cout << setw(20) << arr[i].name // prints name
         << setw(20) << arr[i].manufacturer // prints manufacturer
         << setw(10) << arr[i].quant // prints quantity
         << fixed << showpoint << setprecision(2)
         << setw(10) << arr[i].min
         << setw(20) << arr[i].cost // prints cost for one item
         << endl;
  }
}


// Inventory Report Function
void invReport(Item arr[],int arrSize)
{
  double totalVal, totalAll = 0;
  int totalQuant = 0;

  // print headers
  cout << endl << endl << setw(45) << "Inventory Report\n" << endl;
  cout << setw(20) << left << "Item"
       << setw(15) << "Manufacturer"
       << setw(10) << right << "Quantity"
       << setw(10) << "Cost($)"
       << setw(20) << "Total Value($)"
       << endl;

  // print information for each item
  for (int i = 0; i < arrSize; i++) { // for all items
    totalVal = arr[i].quant*arr[i].cost; // gets the total value for the item
    totalQuant += arr[i].quant; // total quantity of all items in stock
    totalAll += totalVal;
    
    cout << setw(20) << left << arr[i].name // prints name
         << setw(15)  << arr[i].manufacturer // prints manufacturer
         << setw(10) << right << arr[i].quant // prints quantity
         << fixed << showpoint << setprecision(2)
         << setw(10) << arr[i].cost // prints cost for one item
         << setw(20) << totalVal // total value of item's stock
         << endl;
  }

  // other statistics
  cout << endl
       << "Number of different items: " << arrSize << endl
       << "Total quantity: " << totalQuant << endl
       << "total value of all items: $" << totalAll << endl << endl;
}

  
// Reorder Report Function
void reorderReport(Item arr[], int arrSize)
{
  int orderAmt, numItems = 0, totalQuant = 0;
  double itemOrderCost, totalCost = 0;
  // print headers
  cout << endl << endl << setw(45) << "Reorder Report\n" << endl;
  cout << setw(20) << left << "Item"
       << setw(15) << "Manufacturer"
       << setw(10) << right << "Quantity"
       << setw(10) << "Minimum"
       << setw(10) << "Order"
       << setw(10) << "Cost($)"
       << endl;

  for (int i = 0; i < arrSize; i++) { // for all items
    if (arr[i].min > arr[i].quant) { // if item's quantity is low
      orderAmt = arr[i].min-arr[i].quant; // order amount
      itemOrderCost = (orderAmt)*arr[i].cost; // order cost for item
      numItems++; // adds one to number of items that are ordered
      totalQuant += orderAmt; // adds all item orders together
      totalCost += itemOrderCost; // adds total cost of orders
      
      cout << setw(20) << left << arr[i].name // prints name
           << setw(15) << arr[i].manufacturer // prints manufacturer
           << setw(10) << right << arr[i].quant // prints quantity
           << setw(10) << arr[i].min // prints minimum amount of item
           << setw(10) << orderAmt // prints amount to be ordered
           << fixed << showpoint << setprecision(2)
           << setw(10) << itemOrderCost // prints order cost for an item
           << endl;
    }
  }

  // other statistics
  cout << endl
       << "Number of different items to order: " << numItems << endl
       << "Total number to order: " << totalQuant << endl
       << "total value of all items: $" << totalCost << endl << endl;
}




int main()
{
  welcome(); // welcome message
  
  // initializing inFile
  ifstream inFile;
  string fileName;
  cout << "input your file's name: ";
  cin >> fileName;
  inFile.open(fileName);

  //initializing inventory array
  Item inventList[ARRSIZE];

  // variables needed
  string tempName, tempManufact;
  int tempQuant, tempMin, numItem = 0;
  double tempCost;
  char displayMenu = 'y';
  char reportType;

  // reading in inventory data to array
  while(inFile >> tempName >> tempManufact >> tempQuant >> tempMin >> tempCost)
  {
    inventList[numItem].name = tempName;
    inventList[numItem].manufacturer = tempManufact;
    inventList[numItem].quant = tempQuant;
    inventList[numItem].min = tempMin;
    inventList[numItem].cost = tempCost;
    numItem++;
  }
  inFile.close();

  
  // alphabetical sort
  sortItems(inventList, numItem);

  while(displayMenu == 'y') { // display menu
    cout << "Would you like an inventory report, reorder report, or quit "
         << "the program? (i/r/q): ";
    cin >> reportType;

    // checks which report the user asked for
    if(reportType == 'i') { // user wants inventory report
      invReport(inventList, numItem);
      cout << endl << "Would you like another report? (y/n): ";
      cin >> displayMenu;
    }
    else if (reportType == 'r') { // user wants reorder report
      reorderReport(inventList, numItem);
      cout << endl << "Would you like another report? (y/n): ";
      cin >> displayMenu;
    }    
    else if (reportType == 'q')
      displayMenu = 'n';
    else // invalid option is chosen
      cout << "That is not an option. Please pick a valid option\n" << endl;
  }
  
  goodbye();
}
