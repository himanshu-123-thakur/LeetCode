//CODE
#include <iostream>
using namespace std;
int main(){
    int n = 9;
    int x = 2;
    cout<<"After setting ";
    n=n|(1<<(x));
    cout<<n;
    return 0;
}