
#include <vector>
#include <iostream>
#include "Item.h"


const int SIZE = 9;

struct HashNode
{
    HashNode() : id('?'), i(nullptr) {}
    HashNode(char i, Item *ptr) : id(i), i(ptr) {}
    char id;
    Item *i;
};

class HashTable
{

public:
    HashTable(){}

    ~HashTable(){
        for(int i = 0; i < hashT.size(); i++){
            if (hashT[i] != nullptr){
                delete hashT[i];
                hashT[i] = nullptr;
            }
        }
    }

    void initHashTable(vector<HashNode*> v) {

        size = v.size();
        hashT.resize(9);

        for (int i = 0; i < v.size(); i++) {
            int index = hashFunction(v[i]->id);
            hashT[index] = new HashNode(v[i]->id, v[i]->i);
        }
    }
    
    int hashFunction(char c)
    {
        int hash = c % SIZE;
        return hash;
    }

    Item* get(char key) {
        int index = hashFunction(key);

        if(hashT[index] != nullptr){
            return hashT[index]->i;
        }

        return nullptr;
    }

private:
    int size;
   // vector<HashNode*> v;
    vector<HashNode*> hashT;
    

};
