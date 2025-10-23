#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n =sizeof(arr)/sizeof(arr[0]);
    //result array should look like {2,3,4,5,1}
    int temp = arr[0];
    //final implementation of the code 
    for(int i=1;i<n;i++){
        arr[i-1] = arr[i]; 
    }
    arr[n-1] = temp;
    for(int x:arr){
        cout<<x<<" ";
    }
}