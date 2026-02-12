// hashing defination: Used using implementing maps by counting the values of the frequencies of each element repeating in the array
// map stores all the values in sorted manner
#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;
    cout << "Enter the length of the array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements in the array" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // pre-compute all of the indices
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    for (auto it : mpp)
    {
        cout << it.first << "->" << it.second << endl;
    }
    int q;
    cout << "Enter the value of q : ";
    cin >> q;
    while (q--)
    {
        cout << "Enter the number :";
        int number;
        cin >> number;
        cout << number << " repeats " << mpp[number] << " times " << endl;
    }

    // iterating in the map

    return 0;
}