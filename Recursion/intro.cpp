//CODE //MIGHT CAUSE STACK OVERFLOW therfore properly use recursion the condition statement is mandatory; (BASE CONDITION)
//FUNCTIONS ARE STORED IN STACKKKKKK
#include <iostream>
using namespace std;
int a = 0;
void rec(int n){
    // if(a>n)
    // return;
    // ++a;
    // cout <<a<<" ";
    // rec(n-1);

    if(n<=0)
    return;
    cout<<n<<" ";
    rec(n-1);
    cout<<endl;
    cout<<n<<" ";
}
int main(){
    int n;
    cin>>n;
    rec(n);
    return 0;
}
