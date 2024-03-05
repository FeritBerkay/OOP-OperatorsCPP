/*
 CIS 22B: Create and process an array of Sales objects
 
 Overloaded stream insertion operator <<
    - used to display reports and write data to file.
 Overloaded relational operator (<)
    - used to sort the array in ascending order by name (insertion sort)
 
 Name:
 IDE:
*/

#include "Sales.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


const int MAX_SIZE = 30;

/* Write your code here: 
declare the function you are going to call in this program
*/

void readData(string fileName, Sales salesArr[], int &size);

void insertSort(Sales salesArr[], int size);

double calcSalesAvg(Sales salesArr[], int size);

void displayOverAvg(Sales salesArr[], int size, double avg);

void writeReport(Sales salesArr[], int size, string fileName);

void showReport(string fileName);

int main()
{
    Sales salesArr[MAX_SIZE];
    int size = 0;
    
    string fileName;
    cout << "Please enter the input file's name: ";
    getline(cin, fileName);
    readData(fileName, salesArr, size);
    insertSort(salesArr, size);
    double avg = calcSalesAvg(salesArr, size);
    displayOverAvg(salesArr, size, avg);
    writeReport(salesArr, size, fileName);
    
    string option;
    cout << "Show report?" << endl;
    getline(cin, option);
    if (option == "Y" || option == "y")
       showReport(fileName);

    return 0;
}

 /* Write your code here: 
     function definitions
   */
/*This function reads data from the input file into the salesArr array. If the file fails to open, it displays an appropriate message.
Additionally, it calculates the size of the data and sets a reference size parameter to the same, then adds each sale item to the salesArr array. */
void readData(string fileName, Sales salesArr[], int &size)
{
   ifstream inputFile;
      string id;
      int year;
      string name;
      int amountSold; 
      int s = 0;
   inputFile.open(fileName);
    if(inputFile.fail()){
        cout << "Input file: " << fileName << " not found!" << endl;
        exit(101);
    }
    // .eof return true when we reach the end of the file. 
    while (s < MAX_SIZE && inputFile >> id >> year >> ws && getline(inputFile, name, ';') && inputFile >> amountSold) {
        salesArr[s] = Sales(id, year, name, amountSold);
        s++;
    }
   size = s;
   inputFile.close();
}

// This function sorts the sales array in ascending order by name
void insertSort(Sales salesArr[], int size)
{
   for (int i = 1; i <size; i++)
   {
      Sales temp = salesArr[i];
      int j = i - 1;
      while (j>=0 && temp < salesArr[j] )
      {
            salesArr[j + 1] = salesArr[j];
            j--;
      }
      salesArr[j + 1] = temp;
   }
   
}

//This function calculates the average sales among the salers in salasArr.
double calcSalesAvg(Sales salesArr[], int size)
{
   double result = 0;
    for (int i = 0; i < size; i++)
    {
      result += salesArr[i].getAmount();
    }
    return result/size;
}


//This function prints the saler name and their amount of sale which are over average amount of sale. 
void displayOverAvg(Sales salesArr[], int size, double avg)
{
   cout<<"Average Sales: $"<<avg<<endl;
   cout<<"Salespeople with above average sales:"<<endl;
   bool isPrinted = false;
   for (int i = 0; i < size; i++)
   {
      if(salesArr[i].getAmount()>avg){
         isPrinted=true;
         cout<<salesArr[i]<<endl;
      }
   }
   if(!isPrinted){
      cout<<"N/A"<<endl;
   }
   
}


//This function creates a report document which is .txt file.
//This document include the names of the salers and amount earned by these salers.
void writeReport(Sales salesArr[], int size, string fileName)
{
   ofstream outputFile;
   string outputFileName = fileName.insert(fileName.find("."), "Report");
   outputFile.open(outputFileName);
    if(outputFile.fail()){
        cout << "Error opening " << fileName << " for reading." << endl;
        exit(101);
    }
   else{
      outputFile << "Sales Report\n";
      outputFile << "==================== ============= ============= \n";
      outputFile << "Name                 Amount Sold   Amount Earned \n";
      outputFile << "==================== ============= ============= \n";
      for (int i = 0; i < size; i++)
      {
         outputFile << salesArr[i] << endl;
      }
      outputFile<< "==================== ============= ============= \n";
      outputFile<< "Number of salespeople: "<<size<<endl;
   }
      cout<<"Report saved in: "<<outputFileName<<endl;
}


/*
This function receives the name of a file and 
displays its contents to the screen.

*/
void showReport(string fileName)
{
   fileName.insert(fileName.find("."), "Report");
   ifstream in(fileName);
   if (in.fail())
   {
        cout << "Input file: " << fileName << " not found!" << endl;
        exit(EXIT_FAILURE);
   }
   string line;
   while (getline(in, line))
   {
      cout << line << endl;
   }
   in.close();
}

 