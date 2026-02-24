//Code
#include <bits/stdc++.h>
using namespace std;

int hours_at_speed_mid(vector<int>& arr , int mid){
    int hour=0;
    for(auto it: arr){
        hour+= (it + mid-1)/mid;//ceil
    }
    return hour;
}

int  koko_slow_but_all(vector<int> arr, int hours){
    int low = 1;
    int max = *max_element(arr.begin(),arr.end());
    int ans = INT_MAX;
    while(low<=max){
        int mid = low +(max-low)/2;
        int time = hours_at_speed_mid(arr,mid);

        if(time>hours){
            low = mid+1;
        }
        else{
            ans = min(ans,mid);
            max = mid-1;
        }
    }
    return ans;
}

int main(){
    cout<<"KOKO has these many pairs to finish : ";
    vector<int> arr{12,2,1,8,6,9,10,11};
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"Time KOKO got : ";
    int hours = 0;
    cin>>hours;
    cout<<endl;
    cout<<" KOKO Since he likes to eat slow but want to finish all the piles his speed BANANAS/HOUR should be "<<koko_slow_but_all(arr,hours)<<endl;
}