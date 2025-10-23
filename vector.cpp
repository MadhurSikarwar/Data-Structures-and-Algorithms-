
//learning vectors in cpp
// A vector is a dynamic array provided by the standard library template in c++
// unlike normal arrays, vectors can resize automatically when elements are inserted or deleted they store elements in contiguos memory locations  
#include<iostream>
#include<vector> //header file needed for importing vectors 
using namespace std;
int main(){
    vector<int> v; //syntax for declaring a vector 
    // vector<data_type> variable_name; 
    v.push_back(10); //{10}
    v.push_back(20); //{10,20}
    v.push_back(30); //{10,20,30}
    int len = v.size(); //will give the length of the vector
    for(int i=0;i<len;i++){
        cout<<v[i]<<"\t";
    }
    cout<<"\n";
    //accessing element 
    int ele1 = v[0]; //normal array indexing 
    int ele2 = v.at(1); //using function at() safer does bound checking 
    cout<<ele1<<"\t"<<ele2<<endl;
    //imortant function to be remembered and used for vectors 
    // v.size(); returns the size or length of the vector 
    // v.push_back(n) will push n to the end of the vector 
    // v.pop_back() will remove the last element from the vector 
    // v.back() will return the last element in the vector 
    // v.empty() checks if the vector is is empty
    cout<<v.empty()<<endl; //will return 0 as the vector is not empty 
    vector<int> v1;
    v1 = {1,2,3,4,5};
    cout<<"The size of the vector is "<<v1.size()<<endl;
    cout<<"The first element of the vector is "<<v1.front()<<endl;
    cout<<"The last element of the vector is "<<v1.back()<<endl;
    v1.pop_back(); ///will pop 5 out of the vector 
    cout<<"The size of the vector after alternating is "<<v1.size()<<endl;
    cout<<"The last element of the vector after alternating is "<<v1.back()<<endl;
    // traversing along the vector 
    // --> using the normal array traversal method 
    for(int i = 0;i<v1.size();i++){
        cout<<v1.at(i)<<"\t";
    }
    cout<<"\n";
    // range based for loop 
    for(int x:v1){
        cout<<x<<"\t";
    }
    //inserting and erasing elements 
    vector<int> v2 = {23,45,12,90};
    cout<<"\nElements before insertion in list"<<endl;
    for(int x:v2) cout<<x<<"\t";
    cout<<"Printing after insertion"<<endl;
    //inserting elements 
    v.insert(v2.begin(),100); //100 will be inserted in the beginning of the vector
    v.insert(v2.begin()+2,198); //198 will be inserted at the index 2 of the vector
    cout<<"\n";
    for(int x:v2) cout<<x<<"\t";
}