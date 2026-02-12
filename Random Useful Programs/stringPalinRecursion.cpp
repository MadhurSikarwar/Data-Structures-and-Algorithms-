#include<iostream>
using namespace std;
int checkPalin(string str, int start, int end) {
    if (start >= end) {
        return 1;
    }
    if (str[start] != str[end]) {
        return 0;
    }
    return checkPalin(str, start + 1, end - 1);
}
int main(){
    string str = "madam";
    if (checkPalin(str, 0, str.length() - 1))
        cout << "Palindrome String";
    else
        cout << "Not a Palindrome String";
    return 0;
}