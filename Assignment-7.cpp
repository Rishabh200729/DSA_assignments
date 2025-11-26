#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Sorter {
public:
    void selectionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min_idx]) min_idx = j;
            }
            swap(arr[min_idx], arr[i]);
        }
    }

    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }

    void merge(vector<int>& arr, int l, int m, int r) {
        int n1 = m - l + 1, n2 = r - m;
        vector<int> L(n1), R(n2);
        for (int i = 0; i < n1; i++) L[i] = arr[l + i];
        for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return;
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }

    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    void improvedSelectionSort(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int min_idx = left, max_idx = right;
            for (int i = left; i <= right; i++) {
                if (arr[i] < arr[min_idx]) min_idx = i;
                if (arr[i] > arr[max_idx]) max_idx = i;
            }
            swap(arr[left], arr[min_idx]);
            if (max_idx == left) max_idx = min_idx;
            swap(arr[right], arr[max_idx]);
            left++;
            right--;
        }
    }
};

int main() {
    Sorter sorter;
    int n, choice;
    cout << "Elements count: "; cin >> n;
    vector<int> original(n);
    cout << "Elements: ";
    for (int i = 0; i < n; i++) cin >> original[i];

    while (true) {
        vector<int> arr = original;
        cout << "\n1.Selection 2.Insertion 3.Bubble 4.Merge 5.Quick 6.Imp Selection 7.Exit: ";
        cin >> choice;
        if (choice == 7) break;

        switch (choice) {
            case 1: sorter.selectionSort(arr); break;
            case 2: sorter.insertionSort(arr); break;
            case 3: sorter.bubbleSort(arr); break;
            case 4: sorter.mergeSort(arr, 0, n - 1); break;
            case 5: sorter.quickSort(arr, 0, n - 1); break;
            case 6: sorter.improvedSelectionSort(arr); break;
        }
        cout << "Sorted: ";
        for (int x : arr) cout << x << " ";
        cout << endl;
    }
    return 0;
}