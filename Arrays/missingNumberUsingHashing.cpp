#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr;
    int n;
    cout<<"Enter the length of the array: ";
    cin>>n;

    cout<<"Enter the elements (n-1) in the array: ";
    for(int i = 0; i < n-1; i++) {
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }

    // Created an hash array where all elements found are to be said false
    bool hash[n] = {false};  //all elements of the array hash have been initialized to false

    for(int i = 0; i < n-1; i++) {
        hash[arr[i]] = true; //if element found make it's index to true
    }

    // Find the missing number
    for(int i = 1; i <= n; i++) {
        if(hash[i] == false) {
            cout << "The missing number is: " << i << endl;
            break;  // We found the missing number, no need to continue the loop
        }
    }

    return 0;
}
