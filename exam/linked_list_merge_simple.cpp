#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* next;
};

void add(Node* startNode, int data) {
    Node* currentNode;
    for (currentNode = startNode; currentNode->next != nullptr; currentNode = currentNode->next) {
    }
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    currentNode->next = newNode;
}

void printList(Node* startNode) {
    for (Node* currentNode = startNode; currentNode != nullptr; currentNode = currentNode->next) {
        cout << currentNode->data << " ";
    }
    cout << endl;
}

int main() {
    // list 1
    cout << "Number of items to store in list 1: ";
    int list1Size;
    cin >> list1Size;
    Node* startNode1 = new Node();

    for (int i = 0; i < list1Size; i++) {
        int data;
        printf("List1 (%d): ", i + 1);
        cin >> data;
        if (i == 0) {
            startNode1->data = data;
            startNode1->next = nullptr;
        } else {
            add(startNode1, data);
        }
    }

    // list 2
    cout << "Number of items to store in list 2: ";
    int list2Size;
    cin >> list2Size;
    Node* startNode2 = new Node();

    for (int i = 0; i < list2Size; i++) {
        int data;
        printf("List1 (%d): ", i + 1);
        cin >> data;
        if (i == 0) {
            startNode2->data = data;
            startNode2->next = nullptr;
        } else {
            add(startNode2, data);
        }
    }

    // merge
    Node* mergedList = new Node();

    mergedList->data = startNode1->data;
    mergedList->next = nullptr;
    for (Node* currentNode = startNode1->next; currentNode != nullptr; currentNode = currentNode->next) {
        add(mergedList, currentNode->data);
    }

    for (Node* currentNode = startNode2; currentNode != nullptr; currentNode = currentNode->next) {
        add(mergedList, currentNode->data);
    }

    cout << "List 1: ";
    printList(startNode1);

    cout << "List 2: ";
    printList(startNode2);

    cout << "List 3: ";
    printList(mergedList);

    return 0;
}