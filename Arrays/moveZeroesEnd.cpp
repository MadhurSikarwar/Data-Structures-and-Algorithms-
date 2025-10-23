#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,1,2,0,0,0,0,1,2,2,3,4,0,0,7,7,7,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    // int ans[n];
    cout<<"Printing Original Array: "<<endl;
    for(int x:arr) cout<<x<<" ";
    cout<<endl;
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i] != 0){
            arr[j++] = arr[i];
        }
    } 
    for(int i = j;i<n;i++){
        arr[i] = 0;
    } 
    cout<<"Printing Altered Array: "<<endl;
    for(int x:arr) cout<<x<<" ";
}