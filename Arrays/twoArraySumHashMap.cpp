#include <iostream>
#include <map>
using namespace std;

int main()
{

    // Example array
    int arr[] = {9, 4, 10, 3, 11};

    int target;
    cout << "Enter the target sum" << endl;
    cin >> target;

    // Calculate size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Map to store: key = number, value = index of that number in array
    map<int, int> mp;

    // Loop through every element in the array
    for (int i = 0; i < n; i++)
    {

        int first = arr[i];          // current number
        int remain = target - first; // the number we need to find

        /*
            mp.find(remain) searches for 'remain' in the map.

            - If found → returns an iterator pointing to that element.
            - If NOT found → returns mp.end() (special iterator meaning "not found").

            So the condition (mp.find(remain) != mp.end()) means:
            "Did we find the required number earlier?"
        */
        if (mp.find(remain) != mp.end())
        {

            // If found, we print the pair that adds up to target.
            cout << first << " + " << remain << " = " << target << endl;
        }

        // Store the current number with its index in the map
        // (so we can use it for future matches)
        mp[first] = i;
    }
}
