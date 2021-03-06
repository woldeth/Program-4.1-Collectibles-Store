// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: ComicBook.cpp
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// CommicBook class:
//   Implements the comic book item class holds the definition of this itme
//   usings the following methods:
//		toString, operator<, operator== , create
//   Inherirts from the base class items
//  Assumptions:
//	- Definitions will be gathered from the text file
//---------------------------------------------------------------------------

#include "ComicBook.h"

///--------------------------------- toString ------------------------------------
// Prints the description of the item
// Preconditions: None
// Postconditions: Prints out the description for a coin
void ComicBook::toString() const
{
    cout << id << ", " << year << ", " << grade << ", " << title << ", " << publisher << endl;
}

//Comics are sorted first by publisher, then by title, then by year, then by grade
///--------------------------------- operator< ------------------------------------
// Defines lesser than operator for coin
// Preconditions: Two objects of the same subclass
// Postconditions: Determines the lesser than Object from Coins
bool ComicBook::operator<(const Item &rhs) const
{
    const ComicBook &rhsS = static_cast<const ComicBook &>(rhs);

    if (publisher < rhsS.publisher)
    {
        return true;
    }
    else if ((publisher == rhsS.publisher) && (title < rhsS.title))
    {
        return true;
    }
    else if ((publisher == rhsS.publisher) && (title == rhsS.title) && (year < rhsS.year))
    {
        return true;
    }
    else if ((publisher == rhsS.publisher) && (title == rhsS.title) && (year == rhsS.year) && (grade < rhsS.grade))
    {
        return true;
    }
    else if ((publisher == rhsS.publisher) && (title == rhsS.title) && (year == rhsS.year) && (grade == rhsS.grade))
    {
        cout << "Same ComicBook" << endl;
        return false;
    }

    return false;
}

///--------------------------------- operator== ------------------------------------
// Define Items are == to eachother
// Preconditions: Two objects of the smae class
// Postconditions: Determines if objs are equal reuturn true if so
bool ComicBook::operator==(const Item &rhs) const
{
    const ComicBook &rhsS = static_cast<const ComicBook &>(rhs);

    return ((publisher == rhsS.publisher) && (title < rhsS.title) && (year == rhsS.year) && (grade == rhsS.grade));
}

///--------------------------------- Create -----------------------------------------
// creates a new item and returns it.
// Preconditions: None
// Postconditions: Create and returns a new item
Item *ComicBook::create(ifstream &infile)
{

    int year;
    string grade;
    string type;
    string publisher;

    string stringYear;

    getline(infile, stringYear, ','); //get Year
    year = atoi(stringYear.c_str());
    infile.get(); //discard space

    getline(infile, grade, ','); //get grade
    infile.get();                //discard space

    getline(infile, type, ','); //get type
    infile.get();

    getline(infile, publisher, '\n'); //get publisher

    return new ComicBook(year, grade, type, publisher);
}