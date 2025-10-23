#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
using namespace std;
int main(){
    //brute force method here
    vector <int> v1 = {1,1,1,1,2,2,3,4,5,6,7,7,8};
    unordered_set <int> s1; //created an unordered set as it stores numbers in random order
    set <int> s2; //created a set that stores number in ascending order
    for(int i=0;i<v1.size();i++){
        s1.insert(v1[i]); //inserting elements in unordered set 
        s2.insert(v1[i]); //inserting elements in ordered set
    }
    for(auto x:s1){
        cout<<x<<" ";   //printing elements of unordered set
    }
    cout<<endl;
    for(auto x:s2){
        cout<<x<<" ";   //printing elements of ordered set
    }
    // two pointer method for an already sorted array 
    int arr[] = {1,1,1,2,2,3,4,4,5,5,5,6,6,6,6,7,7,8,8,8,8,8,8,8,9,9,9,9,9,9,10,10,10,10,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int newArr[n]; 
    int j = 0; 
    // First element always goes in
    newArr[j++] = arr[0];  
    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[i-1]) {   // compare with previous element
            newArr[j++] = arr[i];
        }
    }
    cout << "\nArray after removing duplicates:\n";
    for(int i = 0; i < j; i++) {
        cout << newArr[i] << " ";
    }
}

