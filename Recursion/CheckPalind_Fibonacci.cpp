//CODE 
#include <iostream>
using namespace std;
// void checkPalindrome(int i,string str, int n){
//     if(i>=n/2){
//         return;
//     }
//     else{
//         if(str[i]==str[n-i-1])
//         checkPalindrome(i+1,str,n);
//         else{
//         cout<<"Not Palindrome";
//         }
//     }
// }
bool isPalindrome(int i, const string &str) {
    int n = str.size();
    if (i >= n / 2) return true;
    if (str[i] != str[n - i - 1]) return false;
    return isPalindrome(i + 1, str);
}
int main(){
    string str;
    cin>>str;
    int i = 0;
    isPalindrome(i,str);
    cout<<boolalpha;
    cout<<str<<" is Palindrome : "<<isPalindrome(i,str)<<endl;
    return 0; 
}