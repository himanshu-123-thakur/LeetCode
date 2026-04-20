// (7)base10 --> (111)base2
// (13)base10 --> (1101)base2

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string base_to_dec(int n){
    string s="";

    while(n>0){
        if(n%2!=0){
            s+='1';
        }
        else{
            s+='0';
        }
        n = n/2;
    }

    reverse(s.begin(),s.end());
    return s;
}

int binary_to_decimal(string s){
    int res = 0;
    for(char c:s){
        res = res * 2 + (c-'0');
    }
    return res;
    
}

int main (){
    int n,m;
    cout<<"Enter Number you want to convert from BASE to decimal = ";
    cin>>n;

    string s = base_to_dec(n);

    for(auto it:s){
        cout<<it;
    }
    cout<<endl;

    cout<<"Now the other way around : ";
    cout<< binary_to_decimal(s);

    return 0;
}