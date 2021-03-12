// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: Coin.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// Coin class:
//   Implements the coin item class holds the definition of this itme 
//   usings the following methods:
//		toString, operator<, operator== , create
//  Assumptions:
//	- Definitions will be gathered from the text file 
//---------------------------------------------------------------------------

#pragma once
#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

//coin
class Coin : public Item
{
protected:
    int grade;          // Grade of the coin
    string type;        // Type of the coin

public:
    // Constructor if nothing passed in
    Coin() : Item('M', 2021), grade(-1), type("?") {} 

    // Constructor with parameters
    Coin(int y, int g, string t) : Item('M', y), grade(g), type(t) {}

    virtual ~Coin() {} // Destructor

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

    ///--------------------------------- Create -----------------------------------------
    // creates a new item and returns it.
    // Preconditions: None
    // Postconditions: Create and returns a new item
    virtual Item* create(ifstream &infile); 


  
};
