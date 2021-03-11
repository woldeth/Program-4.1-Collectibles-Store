// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 6th, 2021
// File Name: SearchTreeCustomers.h
// Title: PROGRAM 4
// -------------------------------------------------------------------------

#include "SearchTreeCustomers.h"

SearchTreeCustomers::~SearchTreeCustomers()
{
    clear(root);
}

void SearchTreeCustomers::clear(Node *&node)
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

void SearchTreeCustomers::history(customerNode custTransactionList[]) const
{
    historyPrivate(root, custTransactionList);
}

void SearchTreeCustomers::historyPrivate(Node *node, customerNode custTransactionList[]) const
{

    if (node == nullptr)
    {
        return;
    }

    //inorder traversal
    historyPrivate(node->left, custTransactionList);
    if (custTransactionList[node->item->getID()].head == nullptr) { 
        node->item->toString();
        cout << "- no transactions" << endl;
        cout << endl;
        return;
    } 
   
    node->item->toString();
    transactionNode *cur = custTransactionList[node->item->getID()].head;
    while (cur != nullptr)
    {
        cout << "transaction type: " << cur->transType << " --> ";
        cur->item->toString();
        cur = cur->next;
    }
    cout << endl;

    historyPrivate(node->right, custTransactionList);
}