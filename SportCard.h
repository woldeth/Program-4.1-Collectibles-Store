// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: SportCard.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#pragma once
#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

//coin
class SportCard : public Item
{
protected:
    string grade;
    string player;
    string manufacturer; 

public:
    SportCard() : Item('S', 2021), grade("?"), player("?"), manufacturer("?") {} // Constructor if nothing passed in

    // Constructor with parameters
    SportCard(int y, string g, string p, string m) : Item('S', y), grade(g), player(p), manufacturer(m) {}

    virtual ~SportCard() {} // Destructor

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
