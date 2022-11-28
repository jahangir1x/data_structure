#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data[24];
    struct Node *next;
};

typedef struct Node *nodePtr;
int ListSize = 0;
nodePtr StartNode;

nodePtr makeNode(char *data) {
    nodePtr newNode = (nodePtr)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->next = nullptr;
    return newNode;
}

void addItem(char *data) {
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
            if (strcmp(innerNode->data, innerNode->next->data) > 0) {
                char temp[24];
                strcpy(temp, innerNode->data);
                strcpy(innerNode->data, innerNode->next->data);
                strcpy(innerNode->next->data, temp);
            }
        }
    }
}

int main() {
    addItem((char *)"baa");
    addItem((char *)"aaa");
    addItem((char *)"aab");
    addItem((char *)"cab");
    addItem((char *)"caa");

    printAll();
    sortList();
    printAll();

    return 0;
}