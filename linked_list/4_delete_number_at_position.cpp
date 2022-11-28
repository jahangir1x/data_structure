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

void deleteAt(int position) {
    if (ListSize <= position) {
        cout << "Error position not available !" << endl;
        exit(1);
    }

    if (ListSize == 0) {
        cout << "Error no item is present in list." << endl;
        exit(1);
    }

    if (position == 0) {
        startNode = startNode->next;
        ListSize -= 1;
        return;
    }

    int nodeCount = 0;

    nodePtr prevNode = startNode;
    nodePtr currentNode = startNode;

    while (currentNode != nullptr) {
        if (nodeCount == position) {
            prevNode->next = currentNode->next;
            ListSize -= 1;
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
        nodeCount += 1;
    }
}

int main() {
    addItem(1);
    addItem(2);
    addItem(3);
    addItem(4);
    addItem(5);
    addItem(6);
    addItem(7);
    printf("linked list items: ");
    printAll();

    deleteAt(0);
    printAll();

    deleteAt(3);
    printAll();

    deleteAt(1);
    printAll();

    return 0;
}
