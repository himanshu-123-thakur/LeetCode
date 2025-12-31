#include<iostream>
using namespace std;
int sum = 0;
int sumN(int n){
    if(n==0)
    return 0;
    else{
    return n+=sumN(n-1);
    }
}
int factorial(int n){
    if(n==1){
        return n;
    }
    else{
        return n*factorial(n-1);
    }
}
int main(){
    int n;
    cin>>n;
    cout<<"Sum of first "<<n<<" terms is "<<sumN(n)<<endl;
    cout<<"Product is "<<factorial(n);
    return 0;
}