// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: SearchTreeItems.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#include "SearchTreeItems.h"



SearchTreeItems::~SearchTreeItems()
{
    clear(root);
}

void SearchTreeItems::clear(Node *&node)
{
    if (node == nullptr)
    {
        return;
    }

    clear(node->left);
    clear(node->right);

    delete node->item;
    node->item = nullptr;

    delete node;
    node = nullptr;
}

bool SearchTreeItems::insert(Item *ptr)
{
    bool flag = false;
    insertPrivate(ptr, root, flag);
    return flag;
}

void SearchTreeItems::insertPrivate(Item *ptr, Node *&node, bool &flag)
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
        cout << "Item already exist" << endl;
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