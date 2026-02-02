//Code
//Lower Bound smallest index in which arr[index]>=target
//UB smallest index arr[index]>target


//in lower bound use >=
//in upper only >

//lower_bound(arr,arr+n,target)
//return (lower_bound(arr,arr+n,target) - (iterator that point s to first elemt of array )

#include <iostream>
#include <vector>
using namespace std;

int lower_bound_using_bs(vector<int> &arr, int n, int low , int high){
    int ans = -1;
    int mid = low + (high-low)/2;
    if(low>high){
        return -1;
    }
    
    if(arr[mid]>=n){
        ans = mid;
        return lower_bound_using_bs(arr,n,low,mid-1)
    }
    else (arr[mid]<n){
        return lower_bound_using_bs(arr,n,mid+1,high);
    }


    
}
int main() {
    vector<int> arr{23,12,3421,4,34,32,5,54,255,1};
    sort(arr.begin(), arr.end());
    int n = 15;

    if(arr[0]>=n){
        cout<<"0"<<endl;
        break;
    }
    else if(arr[arr.size()-1]<n){
        cout<<"-1 No Index"<<endl;
        break;
    }
    else lower_bound_using_bs(arr,n,0,arr.size()-1);
    return 0;
}
