// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: Coin.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#include "ComicBook.h"

///--------------------------------- toString ------------------------------------
// Prints the description of the item
// Preconditions: None
// Postconditions: Prints out the description for a coin
void ComicBook::toString() const
{
    cout << "QTY: " << qty << ", ID: " << id << ", YEAR: " << year
         << ", GRADE: " << grade << ", Title: " << title
         << ", PUBLISHER: " << publisher << endl;
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
        cout << "we are the same ComicBook" << endl;
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

Item *ComicBook::create(ifstream &infile)
{
    int qty;
    int year;
    string grade;
    string type;
    string publisher;

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

    getline(infile, type, ','); //get type
    infile.get();

    getline(infile, publisher, '\n'); //get Grade

    cout << qty << " " << year << " " << grade << " " << type << " " << publisher << endl;
  

    return new ComicBook(qty, year, grade, type, publisher);
}