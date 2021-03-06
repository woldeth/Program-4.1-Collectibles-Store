// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: SearchTreeCustomers.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#include "SearchTreeCustomers.h"

SearchTreeCustomers::SearchTreeCustomers() : root(nullptr) {}

SearchTreeCustomers::~SearchTreeCustomers()
{
}

bool SearchTreeCustomers::insert(Customer *ptr)
{
    bool flag = false;
    insertPrivate(ptr, root, flag);
    return flag;
}

void SearchTreeCustomers::insertPrivate(Customer *ptr, Node *&node, bool &flag)
{

    // Tree is empty
    if (node == nullptr)
    {
        Node *newNode = new Node(ptr);
        node = newNode;
        flag = true;
        return;
    }
    else if (*ptr == *(node->item)) // char is already in tree
    {
        cout << "customer already exist" << endl;
        return;
    }
    else if (*ptr < *(node->item))
    {
        insertPrivate(ptr, node->left, flag); // traverse left
    }
    else if (*(node->item) < *ptr)
    {
        insertPrivate(ptr, node->right, flag); // traverse right
    }
}