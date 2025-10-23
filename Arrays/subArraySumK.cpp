#include<iostream>
#include<vector>
#include<map>
using namespace std;
int longestSubArrayWithSumK(vector<int> a, long long k){
    // map<sum,index> for hashing 
    map<long long,int> mp;
    long long sum = 0;
    int maxLen = 0;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        if(sum == k){
            maxLen = max(maxLen,i+1);
        }
        int rem = sum - k;
        if(mp.find(rem) != mp.end()){ //the rem should not be pointing to the end of the map meaning to the last element in the map 
            int len = i - mp[rem];
            maxLen = max(maxLen, len);
        }
        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }

    }
    return maxLen;  
}
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5,6};
    int k = 6;
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxLen = 0;
    //brute force
    for(int i = 0;i < n;i++){
        int sum = 0;
        for(int j = i;j<n;j++){
            sum+=arr[j];
            if(sum == k){
                maxLen = max(maxLen,j-i+1);
            }
        }
    }
    cout<<"The longest subarray with sum k = "<<k<<" is of length: "<<maxLen<<endl; 
    //optimizing brute 
}