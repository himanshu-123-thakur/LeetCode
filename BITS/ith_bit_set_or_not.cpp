//CODE
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main(){

    int num = 8;
    int x = 3;




    // if((num>>x)&x){
    //     cout<<"SET";
    // }
    // else{
    //     cout<<"not Set";
    // }

    if((1<<x)&num){
        cout<<"SET";
    }
    else{
        cout<<"not Set";
    }





















    // string s ="";
    // int n = num;

    // cout<<"Binary form of "<<n<<" is ";
    // while(n>0){
    //     if(n%2!=0){
    //         s+='1';
    //     }
    //     else{
    //         s+='0';
    //     }
    //     n=n/2;
    // }
    // reverse(s.begin(),s.end());
    // cout<<s<<endl;

    // cout<<"Is the "<<x<<" th bit set ? "<<endl;

    // num = num>>x;
    // if(num == 0){
    //     cout << "Not set";
    //     return 0;
    // }

    // s ="";
    // while(num>0){
    //     if(num%2!=0){
    //         s+='1';
    //     }
    //     else{
    //         s+='0';
    //     }
    //     num=num/2;
    // }
    // reverse(s.begin(),s.end());
    // cout<<s<<endl;

    // if(s[s.size()-1]=='0'){
    //     cout<<"Not set";
    // }
    // else{
    //     cout<<"Set";
    // }
    
    return 0;
}