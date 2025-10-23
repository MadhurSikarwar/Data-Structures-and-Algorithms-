#include <iostream>
using namespace std;

void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d;
    cout << "Enter d: ";
    cin >> d;

    d = d % n;  // handle cases where d > n

    // Step 1: Reverse first d elements
    reverse(arr, 0, d - 1);

    // Step 2: Reverse remaining elements
    reverse(arr, d, n - 1);

    // Step 3: Reverse whole array
    reverse(arr, 0, n - 1);

    cout << "Rotated array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
