#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node *nodePtr;
int ListSize = 0;
nodePtr startNode;

nodePtr makeNode(int data) {
    nodePtr newNode = (nodePtr)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void addItem(int data) {
    nodePtr currentNode;

    if (ListSize == 0) {
        startNode = makeNode(data);

        ListSize += 1;
        return;
    }

    for (currentNode = startNode; currentNode->next != nullptr; currentNode = currentNode->next) {
    }

    nodePtr tempNode = makeNode(data);

    currentNode->next = tempNode;
    tempNode->next = nullptr;
    ListSize += 1;
}

void printAll() {
    for (nodePtr currentNode = startNode; currentNode != nullptr; currentNode = currentNode->next) {
        cout << currentNode->data << " ";
    }
    cout << endl;
}

nodePtr findIntermediateNode(int data) {
    if (ListSize == 0) {
        return nullptr;
    }

    if (startNode->data >= data) {
        return nullptr;
    }

    nodePtr tempNode = startNode;
    nodePtr prevNode = startNode;

    while (tempNode != nullptr) {
        if (data <= tempNode->data) {
            return prevNode;
        }
        prevNode = tempNode;
        tempNode = tempNode->next;
    }
    return prevNode;
}

void insertToSorted(int data) {
    nodePtr intermediateNode = findIntermediateNode(data);

    nodePtr newNode = makeNode(data);
    if (intermediateNode == nullptr) {
        newNode->next = startNode;
        startNode = newNode;
        return;
    }

    newNode->next = intermediateNode->next;
    intermediateNode->next = newNode;
    return;
}

int main() {
    addItem(1);
    addItem(2);
    addItem(3);
    addItem(4);
    addItem(4);
    addItem(5);
    addItem(6);
    printf("linked list items: ");
    printAll();

    insertToSorted(0);
    printAll();

    insertToSorted(3);
    printAll();

    insertToSorted(4);
    printAll();

    insertToSorted(10);
    printAll();
    return 0;
}
