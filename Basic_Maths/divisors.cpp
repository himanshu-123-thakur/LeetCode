//CODE
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
void better_appr (int n){
    list <int> list;
    for(int i = 1; i<sqrt(n);i++){
        if(n%i==0){
            cout<<i<<" ";
            list.push_back(i);
            if(n/i!=i){
            cout<<n/i<<" ";
            list.push_back(n/i);
            }
        }
    }
    cout<<endl;
    list.sort();
    for(auto i:list){
        cout<<i<<" ";

    }
}
int main(){
    int n;
    cin>>n;
    cout<<"Divisors of n are : ";
    for(int i=1;i<=n/2;i++){
        if (n%i==0){
            cout<<i<<" ";
        }
    }
    cout<<endl;

    better_appr(n);


}
