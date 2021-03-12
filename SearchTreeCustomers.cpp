// ------------------------------------------------------------------------
// Name: Tomas H Woldemichael
// Date: March 11, 2021
// File Name: SearchTreeCustomers.cpp
// Title: PROGRAM 4
// -------------------------------------------------------------------------
// SearchTreeCustomers class:
//   Implements the search tree specifcally for customers using the following
//   methods: insert(), clears(), histoy()
//
//  The search tree is used to keep the customer during traversal. The customer
//  search tree will be use with other items to perfrom various commands
//---------------------------------------------------------------------------

#include "SearchTreeCustomers.h"

///--------------------------------- ~SearchTreeCustomer ------------------------------------
// Constructor
// Preconditions: None
// Postconditions: Clears all dynamicaly allocated nodes
SearchTreeCustomers::~SearchTreeCustomers()
{
    clear(root);
}

///--------------------------------- clear ------------------------------------
// clears all dynamicall allocated memory
// Preconditions: none
// Postconditions: bst is cleared out completely
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

///--------------------------------- Insert ------------------------------------
// Takes ptr to customer and creates node to put in BST
// Preconditions: unique customer in bst
// Postconditions: Nodes is inseerted in bst if not found in bst
bool SearchTreeCustomers::insert(Customer *ptr)
{
    bool flag = false;
    insertPrivate(ptr, root, flag);
    return flag;
}

///--------------------------------- InsertPrivate ------------------------------------
// Private helper method takes ptr to customer and creates node to put in BST
// Preconditions: unique customer in bst
// Postconditions: Nodes is inserted in bst if not found in tree
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
    else if (*ptr == *(node->item))  // customer is already in the tree
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

///--------------------------------- history ------------------------------------
// Traverse the customer tree to print out all transactions
// Preconditions: custTransactionList is populated with transactions
// Postconditions: All transactions will be printed inorder of alpha numeric of customer
void SearchTreeCustomers::history(customerNode custTransactionList[]) const
{
    historyPrivate(root, custTransactionList);
}

///--------------------------------- historyPrivate ------------------------------------
// Traverse the customer tree to print out all transactions
// Preconditions: custTransactionList is populated with transactions
// Postconditions: All transactions will be printed inorder of alpha numeric of customer
void SearchTreeCustomers::historyPrivate(Node *node, customerNode custTransactionList[]) const
{

    if (node == nullptr)
    {
        return;
    }

    //inorder traversal
    historyPrivate(node->left, custTransactionList);

    if (custTransactionList[node->item->getID()].head == nullptr)
    {
        node->item->toString();
        cout << "- no transactions" << endl;
        cout << endl;
    }
    else
    {

        node->item->toString();
        transactionNode *cur = custTransactionList[node->item->getID()].head;
        while (cur != nullptr)
        {
            cout << "transaction type: " << cur->transType << " --> ";
            cur->item->toString();
            cur = cur->next;
        }
        cout << endl;
    }

    historyPrivate(node->right, custTransactionList);
}