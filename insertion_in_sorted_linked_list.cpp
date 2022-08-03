#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node *nodePtr;

void printAll(nodePtr startNode)
{
    for (nodePtr currentNode = startNode; currentNode != nullptr; currentNode = currentNode->next)
    {
        cout << currentNode->data << " ";
    }
    cout << endl;
}

nodePtr insertIntoSorted(int numberToInsert, nodePtr startNode)
{
    nodePtr newNode = (nodePtr)malloc(sizeof(struct Node)); // make new node and store new number in the node.
    newNode->data = numberToInsert;

    nodePtr previousNode = nullptr;
    for (nodePtr currentNode = startNode; currentNode != nullptr; currentNode = currentNode->next)
    {
        if (currentNode->data >= numberToInsert)
        {
            if (previousNode == nullptr) // if previous node is nullptr then we need to add number as first element in the list.
            {
                newNode->next = currentNode;
                startNode = newNode;
                return startNode;
            }
            newNode->next = previousNode->next; // link new node to next node
            previousNode->next = newNode;       // link new node to previous node
            return startNode;
        }
        previousNode = currentNode; // set current node to previous node.
    }
    // if execution reached here, that means we need to insert number after last node.
    previousNode->next = newNode; // link new node to last node.
    newNode->next = nullptr;      // link null to new node.
    return startNode;
}

int main()
{
    // take inputs ----------------------------------------------------------------------
    cout << "enter number of elements to store: ";
    int numberOfElements;
    cin >> numberOfElements;

    nodePtr startNode;    // to store head address
    nodePtr previousNode; // to store previously created node
    for (int i = 0; i < numberOfElements; i++)
    {
        nodePtr currentNode = (nodePtr)malloc(sizeof(struct Node)); // create temporary node
        if (i == 0)                                                 // store head address when it's the first input
        {
            startNode = currentNode;
        }
        else
        {
            previousNode->next = currentNode; // link current node with previous node
        }
        int data;
        cout << "input [" << i + 1 << "]: ";
        cin >> data;
        currentNode->data = data;   // store data to the node
        previousNode = currentNode; // prepare node for next input
    }
    previousNode->next = nullptr; // store null pointer in the last node
    // -----------------------------------------------------------------------------------

    cout << "number to insert in the sorted linked list: ";
    int numberToInsert;
    cin >> numberToInsert;
    startNode = insertIntoSorted(numberToInsert, startNode);
    cout << "after inserting: ";
    printAll(startNode);

    return 0;
}
