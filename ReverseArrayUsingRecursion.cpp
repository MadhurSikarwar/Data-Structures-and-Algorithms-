#include<iostream>
using namespace std;
void reverseArray(int arr[], int start, int end) {
    if (start >= end) {
        return; // Base case: when pointers meet or cross
    }

    // Swap elements at start and end
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recursive call
    reverseArray(arr, start + 1, end - 1);
}

int main(){
    int arr[] = {1,2,3,4,5};
    reverseArray(arr,0,4);
    for(int i=0;i<5;i++) cout<<arr[i]<<" "; //printing the reversed array
    cout<<endl;
}