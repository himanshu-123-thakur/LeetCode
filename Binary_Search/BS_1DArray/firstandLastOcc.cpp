//code 
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

int firstInd(vector<int> &nums, int n , int low , int high, int &ans){
    if(low>high){
        return ans;
    }
    int mid = low + (high-low)/2;
    if(nums[mid]>n){
        return firstInd(nums,n,low,mid-1,ans);
    }
    else if(nums[mid]<n){
        return firstInd(nums,n,mid+1,high,ans);
    }
    else{
        if (ans == -1 || mid < ans) ans = mid;
        return firstInd(nums,n , low, mid -1,ans);
    }

    return ans;
}

int endInd (vector<int> &nums, int n , int low, int high, int &ans){
        if(low>high){
        return ans;
    }
    int mid = low + (high-low)/2;
    if(nums[mid]>n){
        return endInd(nums,n,low,mid-1,ans);
    }
    else if(nums[mid]<n){
        return endInd(nums,n,mid+1,high,ans);
    }
    else{
        if (ans == -1 || mid > ans) ans = mid;
        return endInd(nums,n ,mid+1,high,ans);
    }

    return ans;
}
vector<int> searchRange(vector<int>& nums, int target) {
    int ansStart=-1;
    int end=-1;
    int start = firstInd(nums,target,0,nums.size()-1, ansStart);
    int endans = endInd(nums,target,0,nums.size()-1,end);

    return {start,endans};

    
}
};

int main() {
    Solution sol;

    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = sol.searchRange(nums, target);

    cout << "First index: " << result[0] << endl;
    cout << "Last index : " << result[1] << endl;

    return 0;
}