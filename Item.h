// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: Item.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// Item class:
//   Implements the abstract item class that holds the base line characterstics
//   of an item usings the following methods:
//		toString, operator<, operator== , create
//
//  Assumptions:
//	- Abstract base class
//	- Other items will inherit and update membor variables
//---------------------------------------------------------------------------

#pragma once
#include <iostream>

using namespace std;

class Item
{

protected:
    int year; // integer year

public:
    char id; // Coin (M), Comic (C) or Card (S)

    Item() : id('?'), year(2021) {}         // constructor
    Item(char i, int y) : id(i), year(y) {} // constructor with parameters
    virtual ~Item() {}                      // deconstructor

    ///--------------------------------- toString ------------------------------------
    // Prints the description of the item
    // Preconditions: None
    // Postconditions: Prints the ID, QTY and Year (inheriting classes can update toString)
    virtual void toString() const = 0;

    ///--------------------------------- operator< ------------------------------------
    // Defines Items are < than eachother
    // Preconditions: Two objects of the same class
    // Postconditions: Determines the lesser than obj
    virtual bool operator<(const Item &rhs) const = 0;

    ///--------------------------------- operator== ------------------------------------
    // Define Items are == to eachother
    // Preconditions: Two objects of the smae class
    // Postconditions: Determines if objs are equal reuturn true if so
    virtual bool operator==(const Item &rhs) const = 0;

    ///--------------------------------- Create ------------------------------------
    // creates a new item and returns it.
    // Preconditions: None
    // Postconditions: Create and returns a new item
    virtual Item *create(ifstream &infile) = 0;
};
