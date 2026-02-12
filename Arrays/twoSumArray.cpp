#include<iostream>
#include<map>
using namespace std;
int main(){
    //brute force method
    int arr[] = {2,11,4,9,10};
    int target;
    cout<<"Enter the target"<<endl;
    cin>>target;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(i==j)continue;
            else if(arr[i] + arr[j] == target){
                cout<<arr[i]<<" + "<<arr[j]<<endl;
                cout<<i<<" "<<j<<endl;
            }
        }
    }
}