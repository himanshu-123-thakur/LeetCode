//code 
#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
    
        int searchorReturn (vector<int> &nums, int n , int low, int high, int &ans){
    
            if(low>high){
                return low;
            }
            int mid = low + (high-low)/2;
            if(nums[mid]>n){
                ans = mid;
                return searchorReturn(nums,n,low,mid-1,ans);
            }
            else if(nums[mid]<n){
                ans = mid +1;
                return searchorReturn(nums,n,mid+1,high,ans);
            }
            else{
                return mid;
            }
    
            return ans;
            
    
        }
        int searchInsert(vector<int>& nums, int target) {
            int ans = 0;
            return searchorReturn(nums,target,0,nums.size()-1,ans);
            
        }
    };

int main() {
    Solution sol;

    vector<int> nums = {1, 3, 5, 6};
    int target = 2;

    int result = sol.searchInsert(nums, target);

    cout << "Insert position: " << result << endl;

    return 0;
}
