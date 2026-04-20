//CODE
#include <iostream>
using namespace std;
int main(){
    int n = 13;
    int count;
    while(n>0){
        // if(n%2==1){
        //     count++;
        // }

        count +=n&1;
        n = n>>1;
    }

    // if(n==1){
    //     count+=1;
    // }
    cout<<"Set bits = "<<count<<endl;
}