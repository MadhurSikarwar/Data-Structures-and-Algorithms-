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
    int sum = 0;
    for(int x:arr){
        sum+=x;
    }
    int ele = (((n)*(n+1))/2)-sum;
    cout<<"Remaining Element is:"<<ele<<endl;
    //can be also done using bit manipulation technique using the XOR gate
    return 0;
}   
    
    