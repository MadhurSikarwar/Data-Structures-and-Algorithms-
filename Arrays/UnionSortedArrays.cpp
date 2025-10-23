#include<iostream>
#include<vector>
#include<set>
#include<algorithm> //for using sort()
using namespace std;
int main(){
    //brute force method here
    vector <int> v1;
    vector <int> v2;
    cout<<"Enter length of first array"<<endl;
    int n1;
    cin>>n1;
    cout<<"Enter elements in the first array"<<endl;
    for(int i=0;i<n1;i++){
        int ele;
        cin>>ele;
        v1.push_back(ele);
    }
    cout<<"Enter length of second array"<<endl;
    int n2;
    cin>>n2;
    cout<<"Enter elements in the second array"<<endl;
    for(int i=0;i<n2;i++){
        int ele;
        cin>>ele;
        v2.push_back(ele);
    }
    //no need for sorting the arrays when we are using sets already
    // sort(v1.begin(),v1.end()); //sorting array 1
    // sort(v2.begin(),v2.end()); //sorting array 2 
    //code for union
    set<int> s1;
    for(int i=0;i<n1;i++){
       s1.insert(v1[i]);
    }
    for(int i=0;i<n2;i++){
       s1.insert(v2[i]);
    }
    cout<<endl<<"Printing Array 1"<<endl;
    for(int x:v1) cout<<x<<" ";
    cout<<endl<<"Printing Array 2"<<endl;
    for(int x:v2) cout<<x<<" ";
    cout<<endl<<"Printing the Union of Array 1 and 2"<<endl;
    for(int x:s1) cout<<x<<" ";

}
