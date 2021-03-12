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


#pragma once
#include <vector>
#include <iostream>
#include "Item.h"
#include "Transaction.h"

const int SIZE = 9;

struct HashNode
{
    HashNode() : id('?'), i(nullptr) {}
    HashNode(char i, Item *ptr) : id(i), i(ptr) {}
    char id;
    Item *i;
};

struct HashNodeTrans
{
    HashNodeTrans() : command('?'), trans(nullptr) {}
    HashNodeTrans(char c, Transaction *ptr) : command(c), trans(ptr) {}
    char command;
    Transaction *trans;
};

class HashTable
{

public:
    ///--------------------------------- HashTable ------------------------------------
    // Constructor
    // Preconditions: None
    // Postconditions: Initalizes the hashtable class
    HashTable();

    ///--------------------------------- ~HashTable ------------------------------------
    // Destructor
    // Preconditions: None
    // Postconditions: Clears all dynamically allocated memory
    ~HashTable();
    ///--------------------------------- initHashTable ------------------------------------
    // initializes the local vector for the coins, comicbooks, sports cards
    // Preconditions: Must be passed in to initiatilizes the class
    // Postconditions: The private vectors of the hash table class are initialized with dummy ptr
    void initHashTable(vector<HashNode *> v);
    
    ///--------------------------------- initHashTransactions ------------------------------------
    // initializes the local vector for the various commands
    // Preconditions: Must be passed in to initiatilizes the class
    // Postconditions: The private vectors of the hash table class are initialized with dummy ptr
    void initHashTransaction(vector<HashNodeTrans *> v);
   
    ///--------------------------------- hashFunction ------------------------------------
    // Creates a hash index for quick access and storage
    // Preconditions: None
    // Postconditions: returns an integer value based on char/key passed in
    int hashFunction(char c);
  

    ///--------------------------------- hashFunctionTrans ------------------------------------
    // Creates a hash index for quick access and storage
    // Preconditions: None
    // Postconditions: returns an integer value based on char/key passed in
    int hashFunctionTrans(char c);
  

    ///--------------------------------- get ------------------------------------
    // Returns the dummy ptr for factory
    // Preconditions: The vectors must be initalized with dummy ptrs
    // Postconditions: returns a dummy ptr for factory calls
    Item *get(char key);


    ///--------------------------------- getTransaction ------------------------------------
    // Returns the dummy ptr for factory
    // Preconditions: The vectors must be initalized with dummy ptrs
    // Postconditions: returns a dummy ptr for factory calls
    Transaction *getTrans(char key);

private:
    vector<HashNode *> hashT;          // vector to store dummy ptr for items
    vector<HashNodeTrans *> hashTrans; // vector to store dummy ptr for transaction
};
