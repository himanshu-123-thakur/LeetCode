//CODE
#include <iostream>
using namespace std;
int main(){
    int start = 3;
    int goal =4;

    int ans = start^goal;
    //No of set bits in ans are min flip
    int count = 0;
    while(ans>0){
    count++;   //check if odd or add 1
    ans = ans>>1;
    }

    cout<<"No of flip "<<count<<endl;
    return 0;
}