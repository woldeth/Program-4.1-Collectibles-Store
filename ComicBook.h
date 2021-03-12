// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: ComicBook.h
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

#pragma once
#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

class ComicBook : public Item
{
protected:
    string grade;
    string title;
    string publisher;

public:
    ComicBook() : Item('C', 2021), grade("?"), title("?"), publisher("?") {} // Constructor

    // Constructor with parameters
    ComicBook(int y, string g, string t, string p) : Item('C', y), grade(g), title(t), publisher(p) {}

    virtual ~ComicBook() {} // Destructor

    ///--------------------------------- toString ------------------------------------
    // Prints the description of the item
    // Preconditions: None
    // Postconditions: Prints out the description for a comicbook
    virtual void toString() const;

    ///--------------------------------- operator< ------------------------------------
    // Defines lesser than operator for coin
    // Preconditions: Two objects of the same subclass
    // Postconditions: Determines the lesser than Object from Comicbook
    virtual bool operator<(const Item &rhs) const;

    ///--------------------------------- operator== ------------------------------------
    // Define Items are == to eachother
    // Preconditions: Two objects of the smae class
    // Postconditions: Determines if objs are equal reuturn true if so
    virtual bool operator==(const Item &rhs) const;

    ///--------------------------------- Create -----------------------------------------
    // creates a new item and returns it.
    // Preconditions: None
    // Postconditions: Create and returns a new item
    virtual Item *create(ifstream &infile);
};
