#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        // int singleNonDuplicate(vector<int>& nums) {
        //     unordered_map <int,int> mp;
        //     for(auto it: nums){
        //         mp[it]++;
        //     }
        // int ans;
        //     for(auto it: mp){
        //         if(it.second==1){
        //             ans = it.first;
        //         }
            
        //     }
    
        //     return ans;
            
        // }
    
         int singleNonDuplicate(vector<int>& nums) {
            int ans = -1;
            int low = 1;
            int high = nums.size()-2;
            if(nums.size()==1) return nums[0];
            if(nums[0]!=nums[1]){
                ans = nums[0];
                return ans;
            }
            if(nums[nums.size()-1]!=nums[nums.size()-2]){
                ans = nums[nums.size()-1];
                return ans;
            }
    
    
            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]){
                    ans = nums[mid];
                    break;
                }
                else{
                    if(mid%2==0 && nums[mid]==nums[mid+1]){
                        //Number lies on right side
                        low = mid +1;
                    }
                    else if (mid % 2 ==0 && nums[mid]==nums[mid-1]){
                        //Number lies on left side 
                        high = mid -1;
                    }
                    else if (mid % 2 == 1 && nums[mid]==nums[mid-1]){
                        //Number lies on right 
                        low = mid +1;
                    }
                    else{
                        //Number lies on left
                        high = mid -1;
                    }
                }
            }
            return ans;
            
         }
    };


int main() {
    Solution sol;

    vector<int> nums1 = {1,1,2,3,3,4,4,8,8};
    vector<int> nums2 = {3,3,7,7,10,11,11};
    vector<int> nums3 = {1};
    vector<int> nums4 = {0,0,1};

    cout << "Single element (nums1): " << sol.singleNonDuplicate(nums1) << endl;
    cout << "Single element (nums2): " << sol.singleNonDuplicate(nums2) << endl;
    cout << "Single element (nums3): " << sol.singleNonDuplicate(nums3) << endl;
    cout << "Single element (nums4): " << sol.singleNonDuplicate(nums4) << endl;

    return 0;
}