#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    char arr[n];
    cout << "Enter the characters in the array " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // pre computing
    map<char, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    } 
    // printing the map (iterating through it)
    for (auto it : mpp)
    {
        cout << it.first << "->" << it.second << endl;
    }
}