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

int getMaximum(nodePtr startNode) {
    int max = startNode->data;
    for (nodePtr currentNode = startNode; currentNode != nullptr; currentNode = currentNode->next) {
        if (max < currentNode->data) {
            max = currentNode->data;
        }
    }
    return max;
}

int getMinimum(nodePtr startNode) {
    int min = startNode->data;
    for (nodePtr currentNode = startNode; currentNode != nullptr; currentNode = currentNode->next) {
        if (min > currentNode->data) {
            min = currentNode->data;
        }
    }
    return min;
}

int getTotal(nodePtr startNode) {
    int sum = 0;
    for (nodePtr currentNode = startNode; currentNode != nullptr; currentNode = currentNode->next) {
        sum += currentNode->data;
    }
    return sum;
}

double getAverage(nodePtr startNode) {
    double sum = 0;
    int numberOfElements = 0;
    for (nodePtr currentNode = startNode; currentNode != nullptr; currentNode = currentNode->next) {
        sum += currentNode->data;
        numberOfElements += 1;
    }
    return sum / numberOfElements;
}

void printSinValues(nodePtr startNode) {
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
    printAll(startNode);

    cout << "Maximum: " << getMaximum(startNode) << endl;
    cout << "Minimum: " << getMinimum(startNode) << endl;
    cout << "Average: " << getAverage(startNode) << endl;
    cout << "Total: " << getTotal(startNode) << endl;
    printSinValues(startNode);

    return 0;
}
