#include <bits/stdc++.h>

using namespace std;

struct Node {
    char data[24];
    struct Node *next;
};

typedef struct Node *nodePtr;
int ListSize = 0;
nodePtr startNode;

nodePtr makeNode(char *data) {
    nodePtr newNode = (nodePtr)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->next = nullptr;
    return newNode;
}

void addItem(char *data) {
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

nodePtr findIntermediateNode(char *data) {
    if (ListSize == 0) {
        return nullptr;
    }

    if (strcmp(startNode->data, data) >= 0) {
        return nullptr;
    }

    nodePtr tempNode = startNode;
    nodePtr prevNode = startNode;

    while (tempNode != nullptr) {
        if (strcmp(tempNode->data, data) >= 0) {
            return prevNode;
        }
        prevNode = tempNode;
        tempNode = tempNode->next;
    }
    return prevNode;
}

void insertToSorted(char *data) {
    nodePtr intermediateNode = findIntermediateNode(data);

    nodePtr newNode = makeNode(data);
    if (intermediateNode == nullptr) {
        newNode->next = startNode;
        startNode = newNode;
        ListSize = 1;
        return;
    }

    newNode->next = intermediateNode->next;
    intermediateNode->next = newNode;
    ListSize += 1;
    return;
}

int main() {
    addItem((char *)"abc");
    addItem((char *)"def");
    addItem((char *)"ghi");
    addItem((char *)"ghi");
    addItem((char *)"ghi");
    addItem((char *)"jkl");
    addItem((char *)"mno");
    addItem((char *)"pqr");
    addItem((char *)"stu");
    printf("linked list items: ");
    printAll();

    insertToSorted((char *)"aaa");
    printAll();

    insertToSorted((char *)"ghi");
    printAll();

    insertToSorted((char *)"jkl");
    printAll();

    insertToSorted((char *)"vwx");
    printAll();
    return 0;
}
