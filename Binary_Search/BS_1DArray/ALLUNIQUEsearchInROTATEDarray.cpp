// 33. Search in Rotated Sorted Array
// Medium
// Topics
// premium lock iconCompanies

// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.


//code

#include <bits/stdc++.h>
using namespace std;

int search_in_rotated_array(vector<int> &nums , int n , int low, int high){
    if(low>high){
        return -1;
    }

    int mid = low + (high-low)/2;
    if(nums[mid]==n){
        return mid;
    }
    //check first
    if(nums[mid]>=nums[low]){
        //sorted Left side 
        if(nums[low]<=n && n<= nums[mid]){
            return search_in_rotated_array(nums,n,low,mid-1);
        }
        else{
            return search_in_rotated_array(nums,n,mid+1,high);
        }
    }
    else{
        //right sorted
        if(nums[mid]<=n && n<=nums[high]){
            return search_in_rotated_array(nums,n,mid+1,high);
        }
        else{
            return search_in_rotated_array(nums,n, low,mid -1);
        }
    }
}

int main(){
    vector<int>nums={4,5,6,7,8,1,2};
    int n = 2;
    
    cout<<"Index is "<<search_in_rotated_array(nums,n,0,nums.size()-1);
    return 0;
}