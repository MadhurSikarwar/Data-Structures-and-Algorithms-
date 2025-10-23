#include<iostream>
#include<vector>
#include<climits>  // for INT_MIN, INT_MIN would give us the smallest value the integer holds, so that we would be lesser than any number in the array
//INT_MIN would store some value like the lowest integer value -2,147,483,648
using namespace std;

int main(){
    vector<int> v1;
    cout<<"Enter the length of the array: ";
    int n;
    cin >> n;

    cout<<"Enter elements in the array"<<endl;
    for(int i = 0; i < n; i++) {
        int ele;
        cin >> ele;
        v1.push_back(ele);
    }

    int first = INT_MIN, second = INT_MIN; //stored the lowest possible number in these variables

    for(int x : v1) {
        if (x > first) {
            second = first;
            first = x;
        }
        else if (x > second && x != first) {
            second = x;
        }
    }

    cout << "Largest element in the array is " << first << endl;
    if (second == INT_MIN)
        cout << "No second largest element exists (all elements are equal)." << endl;
    else
        cout << "The second largest element is " << second << endl;

    return 0;
}
