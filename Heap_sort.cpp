#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--) {

        int parent = i;

        while (true) {
            int largest = parent;
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;

            if (left < n && arr[left] > arr[largest]) {
                largest = left;
            }

            if (right < n && arr[right] > arr[largest]) {
                largest = right;
            }

            if (largest == parent) {
                break;
            }

            int temp = arr[parent];
            arr[parent] = arr[largest];
            arr[largest] = temp;

            parent = largest;
        }
    }

    // Heap Sort
    for (int i = n - 1; i > 0; i--) {

        // Swap first and last
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify remaining elements
        int parent = 0;

        while (true) {
            int largest = parent;
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;

            if (left < i && arr[left] > arr[largest]) {
                largest = left;
            }

            if (right < i && arr[right] > arr[largest]) {
                largest = right;
            }

            if (largest == parent) {
                break;
            }

            temp = arr[parent];
            arr[parent] = arr[largest];
            arr[largest] = temp;

            parent = largest;
        }
    }

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
