
#include <iostream>
using namespace std;

// 🔹 Bubble Sort Visualizer
void bubbleSortVisualizer() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nStarting Bubble Sort...\n";

    for (int i = 0; i < n - 1; i++) {
        cout << "Pass " << i + 1 << ": ";
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
        if (!swapped) {
            cout << "Array is already sorted. Stopping early.\n";
            break;
        }
    }

    cout << "\nFinal Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// 🔹 Linear Search Visualizer
void linearSearchVisualizer() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    bool found = false;
    for (int i = 0; i < n; i++) {
        cout << "Checking index " << i << ": ";
        if (arr[i] == key) {
            cout << key << " found!\n";
            found = true;
            break;
        } else {
            cout << arr[i] << " != " << key << "\n";
        }
    }
    if (!found) cout << key << " not found in the array.\n";
}

// 🔹 Binary Search Visualizer
void binarySearchVisualizer() {
    int n, key;
    cout << "Enter number of elements (sorted array): ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int low = 0, high = n - 1, mid;
    bool found = false;
    while (low <= high) {
        mid = (low + high) / 2;
        cout << "Checking middle index " << mid << ": ";
        if (arr[mid] == key) {
            cout << key << " found!\n";
            found = true;
            break;
        } else if (arr[mid] < key) {
            cout << arr[mid] << " < " << key << " → search right\n";
            low = mid + 1;
        } else {
            cout << arr[mid] << " > " << key << " → search left\n";
            high = mid - 1;
        }
    }
    if (!found) cout << key << " not found in the array.\n";
}

// 🔹 Quick Sort Visualizer
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        cout << "Pivot placed: " << arr[pi] << " → ";
        for (int k = low; k <= high; k++) cout << arr[k] << " ";
        cout << endl;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quickSortVisualizer() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "\nStarting Quick Sort...\n";
    quickSort(arr, 0, n - 1);

    cout << "\nFinal Sorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

// 🔹 Menu
void showMenu() {
    cout << "\n===== AlgoVisual – Sorting & Searching Visualizer =====\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Quick Sort\n";
    cout << "3. Linear Search\n";
    cout << "4. Binary Search\n";
    cout << "5. Exit\n";
    cout << "Enter your choice (1-5): ";
}

// 🔹 Main
int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                bubbleSortVisualizer();
                break;
            case 2:
                quickSortVisualizer();
                break;
            case 3:
                linearSearchVisualizer();
                break;
            case 4:
                binarySearchVisualizer();
                break;
            case 5:
                cout << "Exiting AlgoVisual...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
