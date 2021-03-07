// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: Feb 11, 2021
// File Name: Item.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#pragma once
#include <iostream>

using namespace std;

// Base class
class Item
{

protected:
    char id;  // Coin (M), Comic (C) or Card (S)
    int year; // integer year
    int qty;  // amount of this item in inventory

public:
    
    Item() : id('?'), qty(0), year(2021){}
    Item(char i, int q, int y) : id(i), qty(q), year(y){}
    virtual ~Item() {} // deconstructor

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

    // ///--------------------------------- hash ------------------------------------
    // // Creates a unique integer value from data member variables
    // // Preconditions: None
    // // Postconditions: returns a unique value that will be used in hash table for index
    // virtual int hash() const
    // {
    //     //  hash value some integer value calculated from member variables
    //     return 0; // hash value;
    // }
};
