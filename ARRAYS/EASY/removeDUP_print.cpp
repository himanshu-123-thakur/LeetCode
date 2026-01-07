//code - remove duplicate and only print the elemtns in a sorted array
//set<int> st(nums.begin(), nums.end()); to put vectors in set OR this map way that is done below ------> O(NlogN)

//OPTIMAL solution - TWO POINTERS approach -------> O(N)






#include <bits/stdc++.h>
using namespace std;

void tow_point_dupl (int arr [], int size ){

    int i=0;
    for(int j = 1;j<size;j++){
        if(arr[i]!=arr[j]){
            arr[i+1]=arr[j];
            i++;
        }
    }
for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
}
}


int main (){
    int size;
    cin>>size;
    int arr[size];
    for(auto &it:arr){
        cin>>it;
    }

    // map <int,int> mp;
    // for(int i=0;i<size;i++){
    //     mp[arr[i]]++;
    // }
    // for(auto &it:mp){
    //     cout<<it.first<<" ";
    // }

    tow_point_dupl(arr,size);
    return 0;
}
