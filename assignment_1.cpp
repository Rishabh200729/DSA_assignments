#include <iostream>
#include <vector>
using namespace std;

#define MAX 100

vector<int> arr;

// 1. Menu Driven Array Operations
void createArray() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    arr.resize(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void displayArray() {
    if (arr.empty()) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements: ";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";
}

void insertElement() {
    int pos, val;
    cout << "Enter position and value: ";
    cin >> pos >> val;
    if (pos < 0 || pos > arr.size()) {
        cout << "Invalid position!\n";
        return;
    }
    arr.insert(arr.begin() + pos, val);
}

void deleteElement() {
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;
    if (pos < 0 || pos >= arr.size()) {
        cout << "Invalid position!\n";
        return;
    }
    arr.erase(arr.begin() + pos);
}

void linearSearch() {
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i << "\n";
            return;
        }
    }
    cout << "Element not found.\n";
}

// 2. Remove Duplicates
void removeDuplicates() {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size();) {
            if (arr[i] == arr[j]) {
                arr.erase(arr.begin() + j);
            } else j++;
        }
    }
}

// 3. Predict Output of given program
void predictOutput() {
    int arr2[5] = {1};
    cout << "Output of program: ";
    for (int i = 0; i < 5; i++)
        cout << arr2[i];
    cout << "\n";
}

// 4a. Reverse Array
void reverseArray() {
    int i = 0, j = arr.size() - 1;
    while (i < j) {
        swap(arr[i], arr[j]);
        i++; j--;
    }
}

// 4b. Matrix Multiplication
void matrixMultiplication() {
    int r1,c1,r2,c2;
    cout << "Enter rows & cols of matrix1: ";
    cin >> r1 >> c1;
    cout << "Enter rows & cols of matrix2: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible!\n";
        return;
    }

    vector<vector<int>> a(r1, vector<int>(c1)), b(r2, vector<int>(c2)), res(r1, vector<int>(c2));

    cout << "Enter matrix1:\n";
    for (int i=0;i<r1;i++) for (int j=0;j<c1;j++) cin >> a[i][j];

    cout << "Enter matrix2:\n";
    for (int i=0;i<r2;i++) for (int j=0;j<c2;j++) cin >> b[i][j];

    for (int i=0;i<r1;i++) for (int j=0;j<c2;j++) {
        res[i][j]=0;
        for (int k=0;k<c1;k++)
            res[i][j]+=a[i][k]*b[k][j];
    }

    cout << "Result matrix:\n";
    for (int i=0;i<r1;i++){
        for (int j=0;j<c2;j++) cout << res[i][j] << " ";
        cout << "\n";
    }
}

// 4c. Transpose Matrix
void transposeMatrix() {
    int r,c;
    cout << "Enter rows & cols: ";
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c));

    cout << "Enter matrix:\n";
    for (int i=0;i<r;i++) for (int j=0;j<c;j++) cin >> a[i][j];

    cout << "Transpose:\n";
    for (int j=0;j<c;j++){
        for (int i=0;i<r;i++) cout << a[i][j] << " ";
        cout << "\n";
    }
}

// 5. Sum of Rows and Columns
void sumRowsCols() {
    int r,c;
    cout << "Enter rows & cols: ";
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c));

    cout << "Enter matrix:\n";
    for (int i=0;i<r;i++) for (int j=0;j<c;j++) cin >> a[i][j];

    cout << "Row sums:\n";
    for (int i=0;i<r;i++) {
        int sum=0;
        for (int j=0;j<c;j++) sum+=a[i][j];
        cout << "Row " << i << " = " << sum << "\n";
    }

    cout << "Column sums:\n";
    for (int j=0;j<c;j++) {
        int sum=0;
        for (int i=0;i<r;i++) sum+=a[i][j];
        cout << "Col " << j << " = " << sum << "\n";
    }
}

// Main Menu
int main() {
    int choice;
    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1.CREATE\n2.DISPLAY\n3.INSERT\n4.DE
