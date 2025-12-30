//CODE
#include <bits/stdc++.h>
using namespace std;
class mathFun{
    public:
    void palindrome(int n){
        int i =1;
        //REVERSE a number 
        int a  =n;
        int rev = 0;
        while(n>0){
            rev = rev*10 +(n%10);
            n = n/10;
        }
        if(rev==a){
            cout<<"Number is Palindrome ";
        }
        else
        cout<<"it's Not "<<rev<<endl;

        }
};
int main(){

    int n;
    cout<<"Enter number : ";
    cin >>n;
    mathFun sol;

    sol.palindrome(n);
    return 0;

}