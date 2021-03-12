
// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: HashTable.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// HashTable class:
//   Implements the hashtable class uses to store dummmy ptr to support
//   factory design patterns for create and excute calls. The hashtable class
//   has two seperate vactors for the commands and the items.
//---------------------------------------------------------------------------

#include "HashTable.h"

///--------------------------------- HashTable ------------------------------------
// Constructor
// Preconditions: None
// Postconditions: Initalizes the hashtable class
HashTable::HashTable() {}

///--------------------------------- ~HashTable ------------------------------------
// Destructor
// Preconditions: None
// Postconditions: Clears all dynamically allocated memory
HashTable::~HashTable()
{
    for (int i = 0; i < hashT.size(); i++)
    {

        if (hashT[i] != nullptr)
        {
            delete hashT[i]->i;
            hashT[i]->i = nullptr;

            delete hashT[i];
            hashT[i] = nullptr;
        }
    }

    for (int i = 0; i < hashTrans.size(); i++)
    {

        if (hashTrans[i] != nullptr)
        {
            delete hashTrans[i]->trans;
            hashTrans[i]->trans = nullptr;

            delete hashTrans[i];
            hashTrans[i] = nullptr;
        }
    }
}
///--------------------------------- initHashTable ------------------------------------
// initializes the local vector for the coins, comicbooks, sports cards
// Preconditions: Must be passed in to initiatilizes the class
// Postconditions: The private vectors of the hash table class are initialized with dummy ptr
void HashTable::initHashTable(vector<HashNode *> v)
{

    hashT.resize(SIZE);

    for (int i = 0; i < v.size(); i++)
    {
        int index = hashFunction(v[i]->id);
        hashT[index] = new HashNode(v[i]->id, v[i]->i);
    }
}

///--------------------------------- initHashTransactions ------------------------------------
// initializes the local vector for the various commands
// Preconditions: Must be passed in to initiatilizes the class
// Postconditions: The private vectors of the hash table class are initialized with dummy ptr
void HashTable::initHashTransaction(vector<HashNodeTrans *> v)
{

    hashTrans.resize(26);

    for (int i = 0; i < v.size(); i++)
    {
        int index = hashFunctionTrans(v[i]->command);
        hashTrans[index] = new HashNodeTrans(v[i]->command, v[i]->trans);
    }
}

///--------------------------------- hashFunction ------------------------------------
// Creates a hash index for quick access and storage
// Preconditions: None
// Postconditions: returns an integer value based on char/key passed in
int HashTable::hashFunction(char c)
{
    int hash = c % SIZE;
    return hash;
}

///--------------------------------- hashFunctionTrans ------------------------------------
// Creates a hash index for quick access and storage
// Preconditions: None
// Postconditions: returns an integer value based on char/key passed in
int HashTable::hashFunctionTrans(char c)
{
    int hash = (c - 'A');
    return hash;
}

///--------------------------------- get ------------------------------------
// Returns the dummy ptr for factory
// Preconditions: The vectors must be initalized with dummy ptrs
// Postconditions: returns a dummy ptr for factory calls
Item *HashTable::get(char key)
{
    int index = hashFunction(key);

    if (hashT[index] != nullptr && hashT[index]->id == key)
    {
        return hashT[index]->i;
    }

    return nullptr;
}

///--------------------------------- getTransaction ------------------------------------
// Returns the dummy ptr for factory
// Preconditions: The vectors must be initalized with dummy ptrs
// Postconditions: returns a dummy ptr for factory calls
Transaction *HashTable::getTrans(char key)
{
    int index = hashFunctionTrans(key);

    if (hashTrans[index] != nullptr && hashTrans[index]->command == key)
    {
        return hashTrans[index]->trans;
    }

    return nullptr;
}
