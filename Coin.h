// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: Coin.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#pragma once
#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

//coin
class Coin : public Item
{
protected:
    int grade;
    string type;

public:
    Coin() : Item('M', 2021), grade(-1), type("?") {} // Constructor if nothing passed in

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


    virtual Item* create(ifstream &infile); 


  
};
