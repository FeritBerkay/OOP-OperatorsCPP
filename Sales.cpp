/*
  Implementation file for the Sales class.
  Ferit Kabil
*/

#include "Sales.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*~*~*~*~*~*~
 This is the default constructor; it sets everything to 0 or "".
 */
Sales::Sales()
{
   /* Write your code here */
   id = "";
   year=0;
   name = "";
   amountSold = 0;
}

/*~*~*~*~*~*~
This is an overloaded constructor.
 It sets the variables according to the parameters.
*/
Sales::Sales(string initId, int initYear, string initName, int initAmountSold)
{
    /* Write your code here */
    id = initId;
    year = initYear;
    name = initName;
    amountSold = initAmountSold;
}

void Sales::setId(string idN)
{
    id = idN;
}

void Sales::setYear(int Year)
{
    year = Year;
}

void Sales::setName(string Pname)
{
    name = Pname;
}

void Sales::setAmount(int aSold)
{
    amountSold = aSold;
}

string Sales::getId() const
{
    return id;
}

int Sales::getYear() const
{
    return year;
}

string Sales::getName() const
{
    return name;
}

int Sales::getAmount() const
{
    return amountSold;
}

/*~*~*~*~*~*~
This function displays the member variables,
 the commision percent and amount earned
 in a neat format.
*/
void Sales::display() const
{
    /* Write your code here */
    cout << "           ID: " << id << endl;
    cout << "         Year: " << year << endl;
    cout << "         Name: " << name << endl;
    cout << "  Amount Sold: $" << amountSold<< endl;
    cout << "   Commission: " << detCommissionPercent()<<"%"  << endl;
    cout << "Amount Earned: $" << detAmountEarned() << endl;

}

/*~*~*~*~*~*~
 This function determines the commision percent based on the following table:
    Sales        Commission
   $0 - 1000        3%
 1001 - 5000        4.5%
 5001 - 10,000      5.25%
 over 10,000        6%
*/
double Sales::detCommissionPercent() const
{
    double commission = 0;
    
    if ( amountSold > 0)
    {
        /* Write your code here */
        if(amountSold<=1000){
            commission =3;
        }
        else if(amountSold>1000 && amountSold<=5000){
            commission = 4.5;
        }
          else if(amountSold>5000 && amountSold<=10000){
            commission = 5.25;
        }
        else{
            commission = 6;
        }
    }
    
    return commission;
}

/*~*~*~*~*~*~
 This function determines the amount earned:
 it calls the detCommisionPercent) function.
 */
double Sales::detAmountEarned() const
{
    double amountEarned = 0;
    /* Write your code here */
    double commission = detCommissionPercent();

    amountEarned = amountSold * commission * 1/100;
    
    return amountEarned;
}

bool Sales::operator< (const Sales &second)
{
  bool result = false;
  if(this->getName() < second.getName()){
    result = true;
  }
  return result;
}

      
         
ostream &operator<<(ostream &strm, const Sales &result)
{   
    strm << setprecision(2) << fixed;
    strm << setw(20) << left << result.getName() << " ";
    strm << setw(9) << right << result.getAmount() << " ";
    strm << setw(13) << right << result.detAmountEarned();

    return strm;
}

