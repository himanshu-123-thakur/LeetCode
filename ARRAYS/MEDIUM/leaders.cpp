//code
//MAX RIGHT, aNy element greater than maxtright is the leader
//OPTIMAL THIS IS 

//{1,4,2,323,4,4,2}
//o/p: {323,4,8,2};

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void leaders(int arr[],int size){
    vector<int>v;

    int max_right=arr[size-1];
    v.push_back(max_right);

    //MAXRIGHT --> GOOD

    for(int i=size-1;i>=0;i--){
        if(arr[i]>max_right){
            max_right=arr[i];
            v.push_back(arr[i]);
        }
    }

    reverse(v.begin(),v.end());
    for(auto &it:v){
        cout<<it<<" ";
    }

}


int main(){
    int arr[7]={1,4,2,323,8,4,2};
    leaders(arr,10);
    return 0;
}