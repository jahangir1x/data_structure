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

void printAll(nodePtr startNode) {
    for (nodePtr currentNode = startNode; currentNode != nullptr; currentNode = currentNode->next) {
        cout << currentNode->data << " ";
    }
    cout << endl;
}

void insertAtNode(nodePtr givenNode, int data) {
    nodePtr newNode = makeNode(data);
}

void insertAt(int position, int data) {
    if (ListSize < position) {
        cout << "Overflow !" << endl;
        exit(1);
    }

    if (position == 0) {
        nodePtr newNode = makeNode(data);
        newNode->next = startNode;
        startNode = newNode;
        ListSize += 1;
        return;
    }

    int nodeCount = 0;
    for (nodePtr currentNode = startNode; currentNode != nullptr; currentNode = currentNode->next) {
        if ((nodeCount + 1) == position) {
            nodePtr newNode = makeNode(data);
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            ListSize += 1;
            return;
        }
        nodeCount += 1;
    }
}

int main() {
    cout << "enter number of elements to store: ";
    int numberOfElements;
    cin >> numberOfElements;

    for (int i = 0; i < numberOfElements; i++) {
        int data;
        cout << "input [" << i + 1 << "]: ";
        cin >> data;
        addItem(data);
    }
    printf("linked list items: ");
    printAll(startNode);

    insertAt(2, 99);
    printAll(startNode);
    insertAt(3, 999);
    printAll(startNode);
    insertAt(5, 9999);
    printAll(startNode);

    return 0;
}
