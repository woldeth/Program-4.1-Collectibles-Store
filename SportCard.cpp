// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: SportCard.cpp
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// SportCards class:
//   Implements the sport cards item class holds the definition of this itme
//   usings the following methods:
//		toString, operator<, operator== , create
//   Inheirts from the base class items
//  Assumptions:
//	- Definitions will be gathered from the text file
//---------------------------------------------------------------------------

#include "SportCard.h"

///--------------------------------- toString ------------------------------------
// Prints the description of the item
// Preconditions: None
// Postconditions: Prints out the description for a coin
void SportCard::toString() const
{
    cout << id << ", " << year << ", " << grade << ", " << player << ", " << manufacturer << endl;
}

///--------------------------------- operator< ------------------------------------
// Defines lesser than operator for coin
// Preconditions: Two objects of the same subclass
// Postconditions: Determines the lesser than Object from Coins
bool SportCard::operator<(const Item &rhs) const
{
    const SportCard &rhsS = static_cast<const SportCard &>(rhs);

    if (player < rhsS.player)
    {
        return true;
    }
    else if ((player == rhsS.player) && (year < rhsS.year))
    {
        return true;
    }
    else if ((player == rhsS.player) && (year == rhsS.year) && (manufacturer < rhsS.manufacturer))
    {
        return true;
    }
    else if ((player == rhsS.player) && (year == rhsS.year) && (manufacturer == rhsS.manufacturer) && (grade < rhsS.grade))
    {
        return true;
    }
    else if ((player == rhsS.player) && (year == rhsS.year) && (manufacturer == rhsS.manufacturer) && (grade == rhsS.grade))
    {
        cout << "Same SportCard" << endl;
        return false;
    }

    return false;
}

///--------------------------------- operator== ------------------------------------
// Define Items are == to eachother
// Preconditions: Two objects of the smae class
// Postconditions: Determines if objs are equal reuturn true if so
bool SportCard::operator==(const Item &rhs) const
{
    const SportCard &rhsS = static_cast<const SportCard &>(rhs);

    return (player == rhsS.player) && (year == rhsS.year) && (manufacturer == rhsS.manufacturer) && (grade == rhsS.grade);
}

///--------------------------------- Create -----------------------------------------
// creates a new item and returns it.
// Preconditions: None
// Postconditions: Create and returns a new item
Item *SportCard::create(ifstream &infile)
{

    int year;
    string grade;
    string player;
    string manufacturer;

    string stringYear;

    getline(infile, stringYear, ','); //get Year
    year = atoi(stringYear.c_str());
    infile.get(); //discard space

    getline(infile, grade, ','); //get Grade
    infile.get();                //discard space

    getline(infile, player, ','); //get player
    infile.get();

    getline(infile, manufacturer, '\n'); //get manufacturer

    return new SportCard(year, grade, player, manufacturer);
}