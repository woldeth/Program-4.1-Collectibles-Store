
#pragma once
#include <vector>
#include <iostream>
#include "Item.h"
#include "Transaction.h"

 //class Transaction;

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
    HashTable() {}

    ~HashTable()
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

    void initHashTable(vector<HashNode *> v)
    {

        hashT.resize(SIZE);

        for (int i = 0; i < v.size(); i++)
        {
            int index = hashFunction(v[i]->id);
            hashT[index] = new HashNode(v[i]->id, v[i]->i);
        }
    }

    void initHashTransaction(vector<HashNodeTrans *> v)
    {

        hashTrans.resize(26);

        for (int i = 0; i < v.size(); i++)
        {
            int index = hashFunctionTrans(v[i]->command);
            hashTrans[index] = new HashNodeTrans(v[i]->command, v[i]->trans);
        }
    }

    int hashFunction(char c)
    {
        int hash = c % SIZE;
        return hash;
    }

    int hashFunctionTrans(char c)
    {
        int hash = (c - 'A'); //% 26;
        return hash;
    }

    Item *get(char key)
    {
        int index = hashFunction(key);

        if (hashT[index] != nullptr && hashT[index]->id == key)
        {
            return hashT[index]->i;
        }

        return nullptr;
    }

    Transaction *getTrans(char key)
    {
        int index = hashFunctionTrans(key);

        if (hashTrans[index] != nullptr && hashTrans[index]->command == key)
        {
            return hashTrans[index]->trans;
        }

        return nullptr;
    }

private:
    vector<HashNode *> hashT; // c M s
    vector<HashNodeTrans *> hashTrans; // s b c d h
};
