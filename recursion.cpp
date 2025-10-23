#include<iostream>
using namespace std;

// Infinite recursive function
void print(){
    cout << "Good morning!" << endl;
    print(); // No base case, will cause stack overflow eventually
}

// Recursive function to print numbers in reverse from num to 0
void printTillNumReverse(int num){
    if(num >= 0){
        cout << num << endl;
        printTillNumReverse(num - 1); // Only subtract once here
    }
}

// Recursive function to print numbers from i to n
void printNumberForward(int i, int n){
    if(i <= n){
        cout << i << endl; // Corrected to print i, not i+1
        printNumberForward(i + 1, n); // Add braces to control recursion
    }
}

// Recursive function to print a name n times
void printNameNTimes(int n, string name){
    if(n >= 1){
        cout << name << endl;
        printNameNTimes(n - 1, name);
    }
}
int sumOfNumbers(int n){
    if (n == 0) {
        return 0;
    } else {
        // Recursive case: sum(n) = n + sum(n-1)
        return n + sumOfNumbers(n - 1);
    }

}
int factorial(int n){
    if(n == 0)
    return 1;
    else 
    return n*factorial(n-1);
}
int main(){
    // Uncomment to test each function:
    // print(); // Warning: Infinite recursion
    // printTillNumReverse(12);
    // printNameNTimes(5, "Madhur");

    // int i, n;
    // cin >> i >> n;
    // if(i < n)
    //     printNumberForward(i, n);
    // else
    //     cout << "Enter i lesser than n" << endl;
    cout<<"Sum of numbers till 10 is "<<sumOfNumbers(10)<<endl<<"and factorial of 5 is "<<factorial(5)<<endl;

    return 0;
}
