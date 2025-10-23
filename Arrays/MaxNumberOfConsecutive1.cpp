    #include<iostream>
    using namespace std;
    int main(){
        int n;
        cout<<"Enter the length of the array"<<endl;
        cin>>n;
        int arr[n];
        cout<<"Enter the elements in the array only 1 and 0"<<endl;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int count = 0;
        int max = 0;
        for(int i=0;i<n;i++){
            if(arr[i] == 1){
                count++;
                if(count>max)
                max = count;
            }
            else
                count = 0;
        }
        cout<<"The max number of 1's appearing are "<<max<<endl;
    }   