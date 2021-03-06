// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: Customer.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#include "Customer.h"

///--------------------------------- operator< ------------------------------------
// Defines lesser than operator for Customer
// Preconditions: Two objects of the same class
// Postconditions: Determines the lesser than Object from customers
bool Customer::operator<(const Customer &rhs) const
{
    if (name < rhs.name)
    {
        cout << name << " < " << rhs.name << ": " << (name < rhs.name) << endl;
        return true;
    }

    if (name > rhs.name)
    {
        cout << name << " < " << rhs.name << ": " << (name > rhs.name) << endl;
        return false;
    }

    cout << "They are the same customer" << endl;
    return false;
}

///--------------------------------- operator== ------------------------------------
//
// Preconditions:
// Postconditions:
bool Customer::operator==(const Customer &rhs) const
{
    return (name == rhs.name && id == rhs.id);
}