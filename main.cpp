#include <bits/stdc++.h>
#include <unistd.h> // sleep
using namespace std;

// ----------- UTILITIES -----------

void clearScreen() {
    system("clear"); // use "cls" for Windows
}

void printArray(vector<int>& arr, int i = -1, int j = -1) {
    for (int k = 0; k < arr.size(); k++) {
        if (k == i || k == j)
            cout << "[" << arr[k] << "] ";
        else
            cout << arr[k] << " ";
    }
    cout << endl;
}

// ----------- BUBBLE SORT -----------

void bubbleSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        cout << "\n=== Pass " << i + 1 << " ===\n";

        for (int j = 0; j < n - i - 1; j++) {

            cout << "Comparing index " << j << " and " << j + 1 << endl;
            printArray(arr, j, j + 1);
            sleep(1);

            if (arr[j] > arr[j + 1]) {
                cout << "Swapping...\n";
                swap(arr[j], arr[j + 1]);

                printArray(arr, j, j + 1);
                sleep(1);
            }

            clearScreen();
        }
    }

    cout << "\nFinal Sorted Array:\n";
    printArray(arr);
}

// ----------- SELECTION SORT -----------

void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            cout << "Comparing " << arr[j] << " with current min " << arr[minIndex] << endl;
            printArray(arr, j, minIndex);
            sleep(1);

            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }

            clearScreen();
        }

        cout << "Swapping " << arr[i] << " and " << arr[minIndex] << endl;
        swap(arr[i], arr[minIndex]);

        printArray(arr, i, minIndex);
        sleep(1);
        clearScreen();
    }

    cout << "\nFinal Sorted Array:\n";
    printArray(arr);
}

// ----------- BINARY SEARCH -----------

void binarySearch(vector<int>& arr, int target) {
    int l = 0, r = arr.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;

        cout << "Range: [" << l << ", " << r << "]\n";
        cout << "Checking index " << mid << " (value = " << arr[mid] << ")\n";

        printArray(arr, mid);
        sleep(1);

        if (arr[mid] == target) {
            cout << "✅ Found at index " << mid << endl;
            return;
        }
        else if (arr[mid] < target) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }

        clearScreen();
    }

    cout << "❌ Not found\n";
}

// ----------- MAIN -----------

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int choice;
    cout << "\nChoose Algorithm:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Binary Search\n";
    cin >> choice;

    if (choice == 1) {
        bubbleSort(arr);
    }
    else if (choice == 2) {
        selectionSort(arr);
    }
    else if (choice == 3) {
        sort(arr.begin(), arr.end());
        int target;
        cout << "Enter target: ";
        cin >> target;
        binarySearch(arr, target);
    }

    return 0;
}