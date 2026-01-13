//CODE 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//BRUTE --> Generate all permulattions , do a linear search where input lies print the next one, if last then print index 0
//BETTER ??
//INBUILT FUNCTION 

// void inbFunc(vector <int> &v){
//     next_permutation(v.begin(),v.end());
//     for(auto &it:v){
//         cout<<it;
//     }
// }



//OPTIMAL 
//CONCEPT IS PREFIX MATCH // LAST VALA PART SE START
//LAST SE CHALU KAR WE NEED A BREAKPOINT jiske age the element s are greater than him 
//eg 2154300 -> breakpoint is 1 one ke ae number are greater 
//we pick the number which is greater than 2b ut smaller than all which is 3  so --> 23|
//now uske bad again peeche sechalo and the number when numbr is greater than breakooint vala number vaaha place kae ---> 2300145
//ANSWER !!!!!!

void optimal_NEXTpermutation(vector<int> &v) {
    int size = v.size();
    int i = size-2;

    while(i>=0 && v[i]>=v[i+1]){
        i--;
    }

    if(i<0){
        reverse(v.begin(),v.end());
        for(auto &it:v){
            cout<<it<<" ";
        }
        return;
    }

    int j = size -1;
    while(v[j]<v[i]){
        j--;
    }
    swap(v[i],v[j]);
    reverse(v.begin()+i+1,v.end());

    for(auto &it:v){
        cout<<it<<" ";
    }

}


int main(){
    // vector <int> v={1,2,3};
    //123,132,213,231,312,321; //ORDER

    // vector<int>v={2,1,5,4,3,0,0};
    vector<int>v = {1, 3, 2};

    optimal_NEXTpermutation(v);

}