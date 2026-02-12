#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 1, 1, 0, 0, 0, 2, 2, 1, 0, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int newArr[n];  // New array to store sorted values
    
    int count0 = 0, count1 = 0, count2 = 0;

    // Count occurrences of 0, 1, and 2
    for (int x : arr) {
        if (x == 0) count0++;
        else if (x == 1) count1++;
        else if (x == 2) count2++;
    }
    
    // Fill newArr based on counts of 0, 1, and 2
    for (int i = 0; i < count0; i++) newArr[i] = 0;  // Fill first 'count0' positions with 0
    for (int i = count0; i < count0 + count1; i++) newArr[i] = 1;  // Fill next 'count1' positions with 1
    for (int i = count0 + count1; i < n; i++) newArr[i] = 2;  // Fill remaining positions with 2

    // Output the sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << newArr[i] << " ";
    }
    cout << endl;

    return 0;
}
