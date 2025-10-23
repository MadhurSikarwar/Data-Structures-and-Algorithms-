#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v1;
    vector<int> v2;
    
    cout << "Enter length of first array" << endl;
    int n1; cin >> n1;
    cout << "Enter elements in the first array" << endl;
    for(int i=0; i<n1; i++){
        int ele;
        cin >> ele;
        v1.push_back(ele);
    }

    cout << "Enter length of second array" << endl;
    int n2; cin >> n2;
    cout << "Enter elements in the second array" << endl;
    for(int i=0; i<n2; i++){
        int ele;
        cin >> ele;
        v2.push_back(ele);
    }

    // sort both arrays
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    // union logic
    vector<int> uni;
    int i = 0, j = 0;
    while(i < n1 && j < n2) {
        if(v1[i] < v2[j]) {
            if(uni.empty() || uni.back() != v1[i]) 
                uni.push_back(v1[i]);
            i++;
        }
        else if(v1[i] > v2[j]) {
            if(uni.empty() || uni.back() != v2[j]) 
                uni.push_back(v2[j]);
            j++;
        }
        else { // equal
            if(uni.empty() || uni.back() != v1[i]) 
                uni.push_back(v1[i]);
            i++;
            j++;
        }
    }

    // add remaining elements
    while(i < n1) {
        if(uni.empty() || uni.back() != v1[i]) 
            uni.push_back(v1[i]);
        i++;
    }
    while(j < n2) {
        if(uni.empty() || uni.back() != v2[j]) 
            uni.push_back(v2[j]);
        j++;
    }

    // print result
    cout << "Union of the two arrays: ";
    for(int x : uni) cout << x << " ";
    cout << endl;

    return 0;
}
