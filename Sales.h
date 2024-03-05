/*
 Specification file for the Sales class
  - Overloaded stream insertion operator (<<)
  - Overloaded relational operator (<)
 */

#ifndef SALES_H
#define SALES_H
#include <string>
#include <iostream>
using std::ostream;
using std:: string;

class Sales; // Forward Declaration
// Function Prototypes for Overloaded Stream Operators
ostream &operator << (ostream &, const Sales &);

class Sales
{
    private:
    /* Write your code here */
    string id;
    int year;
    string name;
    int amountSold;
    
    
    public:
    // constructors
    /* Write your code here */
    Sales();
    Sales(string initId, int initYear, string initName, int initAmountSold);
    // setters
    /* Write your code here */
    void setId(string idN);
    void setYear (int Year);
    void setName (string Pname);
    void setAmount (int aSold);
    
    // getters
    /* Write your code here */
    string getId () const;
    int getYear () const;
    string getName () const;
    int getAmount () const;
    
    // other functions
    /* Write your code here */
    void display() const;
    double detCommissionPercent() const;
    double detAmountEarned() const;
    
    // overloaded operators
    bool operator < (const Sales &);                                   // Overloaded <
    friend ostream &operator << (ostream &, const Sales &);                   // Overloaded <<
};

#endif
