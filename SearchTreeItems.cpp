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

bool SearchTreeItems::insert(Item *ptr, int qty)
{
    bool flag = false;
    insertPrivate(ptr, root, flag, qty);
    return flag;
}

void SearchTreeItems::insertPrivate(Item *ptr, Node *&node, bool &flag, int qty)
{

    // Tree is empty
    if (node == nullptr)
    {
        Node *newNode = new Node(ptr);
        newNode->qty = qty;
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
        insertPrivate(ptr, node->left, flag, qty); // traverse left
    }
    else if (*(node->item) < *ptr)
    {
        insertPrivate(ptr, node->right, flag, qty); // traverse right
    }
}

void SearchTreeItems::find(Item *i, bool buy)
{
    findPrivate(root, i, buy);
}

void SearchTreeItems::findPrivate(Node *&node, Item *i, bool buy)
{
    if (node == nullptr)
    {
        return;
    }
    else if (*i == *(node->item)) // char is already in tree
    {
        if (buy == true)
        {
            node->qty = node->qty + 1;
            //cout << "item bought" << endl;
        }
        else if (buy == false && node->qty > 0)
        {
            node->qty = node->qty - 1;
            //cout << "item sold" << endl;
        } else {
            //cout << "not in inventory" << endl;
        }
    }
    else if (*i < *(node->item))
    {
        findPrivate(node->left, i, buy); // traverse left
    }
    else if (*(node->item) < *i)
    {
        findPrivate(node->right, i, buy); // traverse right
    }
}



void SearchTreeItems::display() const {
    displayPrivate(root);
}


void SearchTreeItems::displayPrivate(Node *node) const{

        // node is empty
    if (node == nullptr)
    {
        return;
    }

    //inorder traversal
    displayPrivate(node->left);

    cout << "QTY: " << node->qty << "\t";
    node->item->toString();
    
    displayPrivate(node->right);

}