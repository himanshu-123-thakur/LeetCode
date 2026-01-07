//code - remove duplicate and only print the elemtns in a sorted array
//set<int> st(nums.begin(), nums.end());



#include <bits/stdc++.h>
using namespace std;
int main (){
    int size;
    cin>>size;
    int arr[size];
    for(auto &it:arr){
        cin>>it;
    }
    map <int,int> mp;
    for(int i=0;i<size;i++){
        mp[arr[i]]++;
    }
    for(auto &it:mp){
        cout<<it.first<<" ";
    }

    
    return 0;
}
