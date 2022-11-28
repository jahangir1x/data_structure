#include <bits/stdc++.h>
using namespace std;

class LinkedList {
   private:
    class Node {
       public:
        int data;
        Node *next;

        Node() {
            this->data = 0;
            this->next = nullptr;
        }

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
    };

   public:
    Node *lastNode = nullptr;
    Node *startNode = nullptr;

    void getValuesFrom(LinkedList other) {
        
    }

    void add(int data) {
        if (startNode == nullptr) {
            startNode = new Node(data);
            lastNode = startNode;
            return;
        }

        Node *newNode = new Node(data);
        lastNode->next = newNode;
        lastNode = newNode;
    }

    void printList() {
        for (Node *currentNode = startNode; currentNode != nullptr; currentNode = currentNode->next) {
            cout << currentNode->data << " ";
        }
        cout << endl;
    }

    void merge(LinkedList other) {
        for (Node *currentNode = other.startNode; currentNode != nullptr; currentNode = currentNode->next) {
            add(currentNode->data);
        }
    }
};

int main() {
    cout << "Number of items to store in list 1: ";
    int list1Size;
    cin >> list1Size;
    LinkedList list1;
    for (int i = 0; i < list1Size; i++) {
        int data;
        printf("List1 (%d): ", i + 1);
        cin >> data;
        list1.add(data);
    }

    cout << "Number of items to store in list 2: ";
    int list2Size;
    cin >> list2Size;
    LinkedList list2;
    for (int i = 0; i < list2Size; i++) {
        int data;
        printf("List2 (%d): ", i + 1);
        cin >> data;
        list2.add(data);
    }

    cout << "List 1 items: ";
    list1.printList();

    cout << "List 2 items: ";
    list2.printList();

    LinkedList mergedList;
    

    return 0;
}