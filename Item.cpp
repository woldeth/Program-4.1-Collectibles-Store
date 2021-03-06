// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: Item.cpp
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#include "Item.h"

///--------------------------------- toString ------------------------------------
// Prints the description of the item
// Preconditions: None
// Postconditions: Prints the ID, QTY and Year (inheriting classes can update toString)
// void Item::toString()
// {
//     cout << "QTY: " << qty << " ID: " << id << " Year: " << year << endl;
// }

// ///--------------------------------- operator< ------------------------------------
// // Defines have Items are < than eachother
// // Preconditions: Two objects of the same class
// // Postconditions: Determines the lesser than obj
// bool Item::operator<(const Item &rhs) const
// {
//     cout << "using items < " << endl;
//     return true;
// }

//     ///--------------------------------- operator== ------------------------------------
//     // Define Items are == to eachother
//     // Preconditions: Two objects of the smae class
//     // Postconditions: Determines if objs are equal reuturn true if so 
// bool Item::operator==(const Item &rhs) const
// {
//     cout << "using items ==" << endl;
//     return true;
// }