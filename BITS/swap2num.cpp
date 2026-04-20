//COde

#include <iostream>
using namespace std;
int main(){
    int a = 5;
    int b = 6;
    cout<<"Before Swap a = "<<a<<" and b = "<<b<<endl;
    //any number XOR with him is 0
    //swap

    a = a^b;
    b = a^b;// (a^b)^b=a^0=a
    a = a^b;// (a^b)^a = b

    cout<<"After Swap a = "<<a<<" and b = "<<b<<endl;
    return 0;
}