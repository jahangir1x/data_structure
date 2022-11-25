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
        startNode->next = nullptr;

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

int getMaximum() {
    int max = startNode->data;
    for (nodePtr currentNode = startNode; currentNode != nullptr; currentNode = currentNode->next) {
        if (max < currentNode->data) {
            max = currentNode->data;
        }
    }
    return max;
}

int getMinimum() {
    int min = startNode->data;
    for (nodePtr currentNode = startNode; currentNode != nullptr; currentNode = currentNode->next) {
        if (min > currentNode->data) {
            min = currentNode->data;
        }
    }
    return min;
}

int getTotal() {
    int sum = 0;
    for (nodePtr currentNode = startNode; currentNode != nullptr; currentNode = currentNode->next) {
        sum += currentNode->data;
    }
    return sum;
}

double getAverage() {
    double sum = 0;
    int numberOfElements = 0;
    for (nodePtr currentNode = startNode; currentNode != nullptr; currentNode = currentNode->next) {
        sum += currentNode->data;
        numberOfElements += 1;
    }
    return sum / numberOfElements;
}

void printSinValues() {
    for (nodePtr currentNode = startNode; currentNode != nullptr; currentNode = currentNode->next) {
        cout << sin(currentNode->data) << " ";
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
    printAll();

    cout << "Maximum: " << getMaximum() << endl;
    cout << "Minimum: " << getMinimum() << endl;
    cout << "Average: " << getAverage() << endl;
    cout << "Total: " << getTotal() << endl;
    printSinValues();

    return 0;
}
