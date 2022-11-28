#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pathMatrix;
int nodeCount;

void showPathMatrix() {
    for (int k = 0; k < nodeCount; k++) {
        for (int i = 0; i < nodeCount; i++) {
            for (int j = 0; j < nodeCount; j++) {
                pathMatrix[i][j] = pathMatrix[i][j] || pathMatrix[i][k] && pathMatrix[k][j];
            }
        }
    }

    cout << endl << "Path matrix:" << endl;
    for (int i = 0; i < nodeCount; i++) {
        for (int j = 0; j < nodeCount; j++) {
            cout << pathMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Enter number of nodes: ";
    cin >> nodeCount;

    cout << "Enter adjacency matrix:" << endl;
    pathMatrix = vector<vector<int>>(nodeCount, vector<int>(nodeCount, 0));

    for (int i = 0; i < nodeCount; i++) {
        for (int j = 0; j < nodeCount; j++) {
            cin >> pathMatrix[i][j];
        }
    }

    showPathMatrix();

    return 0;
}