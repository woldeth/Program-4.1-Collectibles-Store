// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: Coin.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#include "Coin.h"

// Constructor with parameters
Coin::Coin(char i, int q, int y, int g, string t) : grade(g), type(t)
{
    id = i;
    qty = q;
    year = y;
}

///--------------------------------- toString ------------------------------------
// Prints the description of the item
// Preconditions: None
// Postconditions: Prints out the description for a coin
void Coin::toString() const
{
    cout << "QTY: " << qty << " ID: " << id << " YEAR: " << year
         << " GRADE: " << grade << " TYPE: " << type << endl;
}

//Coins are sorted first by type, then by year, then by grade
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