//CODE
//EASY MORE VARIATION in DP
#include <iostream>
using namespace std;
void buyandsell(int arr[],int size, int j){
    int minI =arr[0];
    int miniINDEX=0;
    int i=0;
    while(i<j){
        minI = min(minI,arr[i]);
        miniINDEX=i;
        i++;
    }

    cout<<"Buy it on "<<minI<<"rd day and sell it on "<<j<<endl;

}
int main(){
    int arr[5]={21,32,32,3,23};
    int j;
    cout<<" I want to sell on : ";
    cin>>j;
    buyandsell(arr,5,j);
    return 0;
}