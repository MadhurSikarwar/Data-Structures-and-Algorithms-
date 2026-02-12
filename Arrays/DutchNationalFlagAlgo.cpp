//for sorting the array of 0s 1s and 2s 
//used only for three distinct entities 
#include<iostream>
using namespace std;
void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int arr[] = {2,2,1,1,0,1,2,0,0,0,1,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int low = 0 , mid = 0, high = n-1;
    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    //printing 
    for(int x:arr){
        cout<<x<<" "; 
    }
}