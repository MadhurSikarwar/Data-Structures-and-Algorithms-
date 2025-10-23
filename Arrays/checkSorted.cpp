#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i+1]) {
            return false; // found a violation
        }
    }
    return true; // no violations, sorted
}

int main() {
    cout << "Enter the length of the array: ";
    int n;
    cin >> n;

    vector<int> v(n);
    cout << "Enter elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    if (isSorted(v)) {
        cout << "The array is sorted in non-decreasing order.\n";
    } else {
        cout << "The array is NOT sorted.\n";
    }

    return 0;
}
