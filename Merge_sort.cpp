#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {

    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = low;

    // Compare and merge
    while (i <= mid && j <= high) {

        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements from left part
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements from right part
    while (j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy back to original array
    for (int x = low; x <= high; x++) {
        arr[x] = temp[x];
    }
}

void mergeSort(int arr[], int low, int high) {

    if (low < high) {

        int mid = (low + high) / 2;

        // Divide
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Conquer + Combine
        merge(arr, low, mid, high);
    }
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
