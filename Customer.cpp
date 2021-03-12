// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: Customer.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// Customer class:
//   Defines a the characteristic of a customer within this system.
//---------------------------------------------------------------------------

#include "Customer.h"

///--------------------------------- operator< ------------------------------------
// Defines lesser than operator for Customer
// Preconditions: Two objects of the same class
// Postconditions: Determines the lesser than Object from customers
bool Customer::operator<(const Customer &rhs) const
{
    if (name < rhs.name)
    {
        return true;
    }

    if (name > rhs.name)
    {
        return false;
    }

    return false;
}

///--------------------------------- operator== ------------------------------------
// Defines if two customers are equal
// Preconditions: None
// Postconditions: Returns a boolean to determine if two obj are equal
bool Customer::operator==(const Customer &rhs) const
{
    return (name == rhs.name && id == rhs.id);
}

///--------------------------------- toString ------------------------------------
// toString method to print out the contents of the customer
// Preconditions: None
// Postconditions: Prints the customer content to the screen
void Customer::toString() const
{
    cout << "Customer ID: " << id << " "
         << "Name: " << name << endl;
}

///--------------------------------- getID ------------------------------------
// returns the interger id of the customer
// Preconditions: customer must have an id
// Postconditions: Returns the interger value of the customers id
int Customer::getID() const
{
    return id;
}