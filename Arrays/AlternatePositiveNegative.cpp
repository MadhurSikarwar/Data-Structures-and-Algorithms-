#include<iostream>
using namespace std;
int main(){
    int arr[] = {3,4,-1,-2,4,-5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int newArr[n];
    //here we need to rearrange arr in newArr where all +ve and -ve numbers are alternative
    // int j = 0;
    // for(int i=0;i<n;i++){
    //     if(arr[i]>=0)
    //     newArr[j] = arr[i];
    //     j+=2;
    // }
    // j = 1;
    // for(int i=0;i<n;i++){
    //     if(arr[i] < 0){
    //         newArr[j] = arr[i];
    //         j+=2;
    //     }
    // }
    int pos = 0;
    int neg = 1;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            newArr[pos] = arr[i];
            pos+=2;
        }
        else {
            newArr[neg] = arr[i];
            neg+=2;
        }
    }
    for(int x:arr){
        cout<<x<<" ";
    }
    cout<<endl;
    for(int x:newArr){
        cout<<x<<" ";
    }
    cout<<endl;
}