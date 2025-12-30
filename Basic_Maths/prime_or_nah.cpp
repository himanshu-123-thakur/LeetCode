#include <iostream>
using namespace std;
bool checkPrime(int n){
    int a = n/2;
    for(int i =n/2;i>1;i--){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    cin>>n;

    bool b = checkPrime(n);
    cout<<boolalpha;
    cout<<"Statement that "<<n<<" is prime is "<<b<<endl;
    return 0;
}