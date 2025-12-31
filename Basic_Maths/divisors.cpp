//CODE
#include <iostream>
#include <math.h>
using namespace std;
void better_appr (int n){
    for(int i = 1; i<sqrt(n);i++){
        if(n%i==0){
            cout<<i<<" ";
            if(n/i!=i)
            cout<<n/i<<" ";
        }
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
