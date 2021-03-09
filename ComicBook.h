// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: ComicBook.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#pragma once
#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

//coin
class ComicBook : public Item
{
protected:
    string grade;
    string title;
    string publisher; 

public:
    ComicBook() : Item('C', 0, 2021), grade("?"), title("?"), publisher("?") {} // Constructor if nothing passed in

    // Constructor with parameters
    ComicBook(int q, int y, string g, string t, string p) : Item('C', q, y), grade(g), title(t), publisher(p) {}

    virtual ~ComicBook() {} // Destructor

    ///--------------------------------- toString ------------------------------------
    // Prints the description of the item
    // Preconditions: None
    // Postconditions: Prints out the description for a coin
    virtual void toString() const;

    ///--------------------------------- operator< ------------------------------------
    // Defines lesser than operator for coin
    // Preconditions: Two objects of the same subclass
    // Postconditions: Determines the lesser than Object from Coins
    virtual bool operator<(const Item &rhs) const;

    ///--------------------------------- operator== ------------------------------------
    // Define Items are == to eachother
    // Preconditions: Two objects of the smae class
    // Postconditions: Determines if objs are equal reuturn true if so
    virtual bool operator==(const Item &rhs) const;


    virtual Item* create(ifstream &infile);
};
