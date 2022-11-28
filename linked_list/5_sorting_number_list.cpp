#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node *nodePtr;
int ListSize = 0;
nodePtr StartNode;

nodePtr makeNode(int data) {
    nodePtr newNode = (nodePtr)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void addItem(int data) {
    if (ListSize == 0) {
        StartNode = makeNode(data);
        ListSize += 1;
        return;
    }

    nodePtr currentNode;
    for (currentNode = StartNode; currentNode->next != nullptr; currentNode = currentNode->next) {
    }

    nodePtr tempNode = makeNode(data);
    currentNode->next = tempNode;
    ListSize += 1;
}

void printAll() {
    for (nodePtr currentNode = StartNode; currentNode != nullptr; currentNode = currentNode->next) {
        cout << currentNode->data << " ";
    }
    cout << endl;
}

void sortList() {
    for (nodePtr outerNode = StartNode; outerNode->next != nullptr; outerNode = outerNode->next) {
        for (nodePtr innerNode = StartNode; innerNode->next != nullptr; innerNode = innerNode->next) {
            if (innerNode->data > innerNode->next->data) {
                int temp = innerNode->data;
                innerNode->data = innerNode->next->data;
                innerNode->next->data = temp;
            }
        }
    }
}

int main() {
    addItem(3);
    addItem(2);
    addItem(1);
    addItem(5);
    addItem(4);

    printAll();
    sortList();
    printAll();

    return 0;
}