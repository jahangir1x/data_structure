#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node *nodePtr;
int ListSize = 0;
nodePtr startNode;

void addItem(int data) {
    nodePtr currentNode;

    if (ListSize == 0) {
        startNode = (nodePtr)malloc(sizeof(struct Node));
        startNode->data = data;
        startNode->next = nullptr;

        ListSize += 1;
        return;
    }

    for (currentNode = startNode; currentNode->next != nullptr; currentNode = currentNode->next) {
    }
    nodePtr tempNode = (nodePtr)malloc(sizeof(struct Node));
    tempNode->data = data;

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
    // print linked list
    printf("linked list items: ");
    printAll(startNode);

    return 0;
}
