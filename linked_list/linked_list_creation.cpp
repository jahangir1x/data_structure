#include <iostream>
#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    cout << "enter number of elements to store: ";
    int numberOfElements;
    cin >> numberOfElements;

    nodePtr head;         // to store head address
    nodePtr previousNode; // to store previously created node
    for (int i = 0; i < numberOfElements; i++)
    {
        nodePtr currentNode = (nodePtr)malloc(sizeof(struct Node)); // create temporary node
        if (i == 0)                                                 // store head address when it's the first input
        {
            head = currentNode;
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

    // print linked list
    printf("linked list items: ");
    printAll(head);

    return 0;
}
