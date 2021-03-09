// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: SportCard.cpp
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#include "SportCard.h"

///--------------------------------- toString ------------------------------------
// Prints the description of the item
// Preconditions: None
// Postconditions: Prints out the description for a coin
void SportCard::toString() const
{
    cout << "QTY: " << qty << ", ID: " << id << ", YEAR: " << year
         << ", GRADE: " << grade << ", Player: " << player
         << ", Manufacturer: " << manufacturer << endl;
}

// player, then by year, then by manufacturer, then by grade
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
        cout << "we are the same SportCard" << endl;
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


Item* SportCard::create(ifstream &infile){
    int qty;
    int year;
    string grade;
    string  player;
    string manufacturer;

    string stringQTY;
    string stringYear;

    getline(infile, stringQTY, ','); //get QTY
    qty = atoi(stringQTY.c_str());
    infile.get(); //discard space

    getline(infile, stringYear, ','); //get Year
    year = atoi(stringYear.c_str());
    infile.get(); //discard space

    getline(infile, grade, ','); //get Grade
    infile.get();                //discard space

    getline(infile, player, ','); //get type
    infile.get();

    getline(infile, manufacturer, '\n'); //get Grade

    cout << qty << " " << year << " " << grade << " " << player << " " << manufacturer << endl;
  

    return new SportCard(qty, year, grade, player, manufacturer);
}