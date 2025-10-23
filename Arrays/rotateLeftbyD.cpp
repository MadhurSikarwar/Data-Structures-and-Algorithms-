#include<iostream>
using namespace std;
int main(){
    int n=5;
    int arr[] = {1,2,3,4,5};
    int d;
    cout<<"Enter d:";
    cin>>d;
    if(d>n){
        cout<<"Enter d<=n"<<endl;
    }
    else{
        int ans[n];
        int temp[d];
        for(int i=0;i<d;i++){
            temp[i] = arr[i];
        }
        int index = 0;
        for(int i=d;i<n;i++){
            ans[index] = arr[i];
            index++;
        }
        for(int i=0;i<d;i++){
            ans[index++] = temp[i];
        }
        cout<<"Printing the original Array"<<endl;
        for(int x:arr){
            cout<<x<<" ";
        }
        cout<<endl<<"Printing the rotated array"<<endl;
        for(int x:ans){
            cout<<x<<" ";
        }
    }
}