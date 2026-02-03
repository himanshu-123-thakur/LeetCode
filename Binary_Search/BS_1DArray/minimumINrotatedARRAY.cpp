//code
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    
        int findSol (vector<int> nums , int low, int high , int &ans){
    
            while(low<=high){
                int mid = low + (high-low)/2;
                // current mid is a candidate minimum
                ans = min(ans, nums[mid]);
                if(nums[mid]>nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid -1;
                }
            }
            return ans;
    
        }
        int findMin(vector<int>& nums) {
            int ans = INT_MAX;
            int result = findSol(nums,0,nums.size()-1,ans);
            return result;
        }
    };
    
int main() {
    Solution sol;

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    // try also: {11,13,15,17} or {3,4,5,1,2}

    int result = sol.findMin(nums);

    cout << "Minimum element is: " << result << endl;

    return 0;
}
