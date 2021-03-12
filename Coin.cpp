// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: Coin.cpp
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// Coin class:
//   Implements the coin item class holds the definition of this itme
//   usings the following methods:
//		toString, operator<, operator== , create
//  Assumptions:
//	- Definitions will be gathered from the text file
//---------------------------------------------------------------------------

#include "Coin.h"

///--------------------------------- toString ------------------------------------
// Prints the description of the item
// Preconditions: None
// Postconditions: Prints out the description for a coin
void Coin::toString() const
{
    cout << id << ", " << year << ", " << grade << ", " << type << endl;
}

///--------------------------------- operator< ------------------------------------
// Defines lesser than operator for coin
// Preconditions: Two objects of the same subclass
// Postconditions: Determines the lesser than Object from Coins
bool Coin::operator<(const Item &rhs) const
{
    const Coin &rhsS = static_cast<const Coin &>(rhs);

    if (type < rhsS.type)
    {
        return true;
    }
    else if ((type == rhsS.type) && (year < rhsS.year))
    {
        return true;
    }
    else if ((type == rhsS.type) && (year == rhsS.year) && (grade < rhsS.grade))
    {
        return true;
    }
    else if ((type == rhsS.type) && (year == rhsS.year) && (grade == rhsS.grade))
    {
        cout << "Same coin" << endl;
        return false;
    }

    return false;
}

///--------------------------------- operator== ------------------------------------
// Define Items are == to eachother
// Preconditions: Two objects of the smae class
// Postconditions: Determines if objs are equal reuturn true if so
bool Coin::operator==(const Item &rhs) const
{
    const Coin &rhsS = static_cast<const Coin &>(rhs);

    return (type == rhsS.type) && (year == rhsS.year) && (grade == rhsS.grade);
}

///--------------------------------- Create -----------------------------------------
// creates a new item and returns it.
// Preconditions: None
// Postconditions: Create and returns a new item
Item *Coin::create(ifstream &infile)
{

    int year;
    int grade;
    string type;

    string stringYear;
    string stringGrade;

    getline(infile, stringYear, ','); //get Year
    year = atoi(stringYear.c_str());
    infile.get(); //discard space

    getline(infile, stringGrade, ','); //get Grade
    grade = atoi(stringGrade.c_str());
    infile.get(); //discard space

    getline(infile, type, '\n'); //get type

    return new Coin(year, grade, type);
}