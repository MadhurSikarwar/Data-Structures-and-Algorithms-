#include<iostream>
#include<vector> //for using vector
#include<math.h> //for using sqrt()
#include <algorithm> //for using sort() 
using namespace std;
void printDivisor(int n){ //unoptimized code with O(n) time complexity
    for(int i = 1;i <= n;i++){
        if(n%i == 0)
        cout<<i<<" ";
    }
}
void printDivisorOptimized(int num){
    vector<int> ls;
    for(int i = 1;i<=sqrt(num);i++){
        if(num%i == 0)
        ls.push_back(i);
        if(num/i != i){
            ls.push_back(num/i);
        }
    }
    // O(n log n) for n = no of factors 
    sort(ls.begin(),ls.end());
    for(auto it:ls) cout<< it << " ";
}
int main(){
    int num1;
    int num2;
    cout<<"Enter value of num 1 and num 2"<<endl;
    cin>>num1>>num2;
    printDivisor(num1);
    cout<<endl;
    printDivisorOptimized(num2);
}