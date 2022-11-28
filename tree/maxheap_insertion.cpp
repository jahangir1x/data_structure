#include <bits/stdc++.h>
using namespace std;

int Heap[100];
int Top = 0;

void insertHeap(int item) {
    Top += 1;
    int currentPos = Top;

    while (currentPos < 1) {
        int parentPos = Top / 2;

        if (Heap[parentPos] >= item) {
            Heap[Top] = item;
            return;
        }

        Heap[Top] = Heap[parentPos];
        Top = parentPos;
    }

    Heap[1] = item;
}

void printSpaces(int spaceCount, bool withNewline = false) {
    // for (int i = 0; i < spaceCount; i++) {
    //     cout << " ";
    // }
    printf("-%d-", spaceCount);
    if (withNewline) {
        cout << endl;
    }
}

void printHeap() {
    for (int i = 1; i <= 31; i++) {
        Heap[i] = i;
    }
    int m = 31;
    int n = 31;
    int itemsPerLine = 1;
    int count = 0;
    for (int i = 1; i <= m; i++) {
        if (count == itemsPerLine) {
            n = n / 2;
            printSpaces(n, true);
            itemsPerLine *= 2;
        } else {
            printSpaces(n / 2, false);
        }

        printf("%2d", Heap[i]);
        count += 1;
    }
    cout << endl;
}

int main() {
    // insertHeap(44);
    // printHeap();
    // insertHeap(30);
    // printHeap();
    // insertHeap(50);
    // printHeap();
    // insertHeap(22);
    // printHeap();
    // insertHeap(60);
    // printHeap();
    // insertHeap(55);
    // printHeap();
    // insertHeap(77);
    // printHeap();
    // insertHeap(55);
    // printHeap();

    printHeap();

    return 0;
}