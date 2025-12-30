//Code 
#include<iostream>
#include <math.h>
using namespace std;
int main(){
    int n;
    int rev=0;
    int armstrong=0;
    cin>>n;
    int a =n;
    int b = n;
    int count = 0;
    while(n>0){
        rev = rev*10 + (n%10);
        n = n/10;
        count++;
    }
    cout <<"Number of digits is = "<<count<<endl;

    while(a>0){
        armstrong+= pow(a%10 , count);
        a = a/10;
    }
    cout <<"reversed number is = "<<rev<<endl;
    cout <<"Number after armstrong check = "<<armstrong<<endl;
    if (armstrong==b){
        cout<<"Number is a armstrong"<<endl; 
    }
    else
    cout<<"Not armstrong"<<endl;
    return 0;
}