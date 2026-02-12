#include<iostream>
#include<map>
using namespace std;
int main(){
    int count = 0;
    int arr[] = {2,2,2,1,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    //solution by O[n^2]
    // for(int i=0;i<n;i++){
    //     count = 0;
    //     for(int j=0;j<n;j++){
    //         if(arr[i] == arr[j])
    //         count++;
    //     }
    //     if(count>n/2){
    //         cout<<arr[i]<<endl; //or use return arr[i]
    //     }
    // }
    //using hasing to solve this same problem 
    map <int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++; //incrementing value of arr[i] stored in map 
    }
    for(auto it:mp){ //printing a map by assigning an iterator
        if(it.second > n/2){
            cout<<it.first<<endl;
        }
    }

    //using moore's algorithm 
    int el;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(count == 0){
            el = arr[i];
            cnt = 1;
        }
        else if(arr[i] == el){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int cnt1 = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == el){
            cnt1++;
        }
    }
    if(cnt1 > n/2)
    cout<<el<<" using moore's algo"<<endl;
    else
    cout<<"No element"<<endl;
}