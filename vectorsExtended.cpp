#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

int main() {

    // 1. Declaration + push_back
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    cout << "Vector v1: ";
    for(int x : v1) cout << x << " ";
    cout << "\n\n";

    // 2. Access elements
    cout << "Accessing elements in v1 -> ";
    cout << "First (v1[0]) = " << v1[0] 
         << ", Second (v1.at(1)) = " << v1.at(1) << "\n\n";

    // 3. Basic functions
    vector<int> v2 = {1,2,3,4,5};
    cout << "Vector v2 size = " << v2.size() << "\n";
    cout << "First = " << v2.front() << ", Last = " << v2.back() << "\n";
    v2.pop_back(); // removes 5
    cout << "After pop_back, new last = " << v2.back() 
         << " (size = " << v2.size() << ")\n\n";

    // 4. Traversal
    cout << "Traversal of v2 -> Normal loop: ";
    for(int i=0;i<v2.size();i++) cout << v2[i] << " ";
    cout << "\nRange-based loop: ";
    for(int x:v2) cout << x << " ";
    cout << "\n\n";

    // 5. Insert & Erase
    vector<int> v3 = {23,45,12,90};
    cout << "v3 before insert: ";
    for(int x:v3) cout << x << " ";
    v3.insert(v3.begin(),100);       // insert at beginning
    v3.insert(v3.begin()+2,198);     // insert at index 2
    cout << "\nv3 after insert: ";
    for(int x:v3) cout << x << " ";
    v3.erase(v3.begin()+1);          // erase element at index 1
    cout << "\nv3 after erase: ";
    for(int x:v3) cout << x << " ";
    cout << "\n\n";

    // 6. Clear
    vector<int> v4 = {1,2,3};
    cout << "v4 before clear, size = " << v4.size() << "\n";
    v4.clear();
    cout << "v4 after clear, size = " << v4.size() 
         << " (empty? " << v4.empty() << ")\n\n";

    // 7. Size vs Capacity
    vector<int> v5;
    cout << "Size vs Capacity in v5:\n";
    for(int i=1;i<=10;i++){
        v5.push_back(i);
        cout << "Size = " << v5.size() << ", Capacity = " << v5.capacity() << "\n";
    }
    cout << "\n";

    // 8. Swap
    vector<int> a = {1,2,3};
    vector<int> b = {4,5};
    cout << "Before swap -> a: ";
    for(int x:a) cout << x << " ";
    cout << " b: ";
    for(int x:b) cout << x << " ";
    a.swap(b);
    cout << "\nAfter swap -> a: ";
    for(int x:a) cout << x << " ";
    cout << " b: ";
    for(int x:b) cout << x << " ";
    cout << "\n\n";

    // 9. Sorting
    vector<int> v6 = {30,10,20,50,40};
    sort(v6.begin(), v6.end()); // ascending
    cout << "v6 ascending sort: ";
    for(int x:v6) cout << x << " ";
    sort(v6.rbegin(), v6.rend()); // descending
    cout << "\nv6 descending sort: ";
    for(int x:v6) cout << x << " ";
    cout << "\n\n";

    // 10. 2D Vector
    vector<vector<int>> mat;
    mat.push_back({1,2,3});
    mat.push_back({4,5,6});
    mat.push_back({7,8,9});
    cout << "2D Vector (matrix):\n";
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
