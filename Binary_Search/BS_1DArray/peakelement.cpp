//code 
//WE DONT CARE bout mutliple peak and only one peak
//now we check mid if right is greater than mid and only one peak then it exists on right side 
//siimialrly if left is greater then peak on left side 


#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int peakElement(vector<int> &nums){
        int ans=-1;
        int low = 1;
        int high = nums.size()-2;
        if(nums.size()==1){
            ans = nums[nums.size()-1];
        }

        if(nums[0]>nums[1]){
            ans = nums[0];
        }
        if(nums[nums.size()-1] > nums[nums.size()-2]){
            ans = nums[nums.size()-1];
        }

        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid] < nums[mid+1]){
                low = mid+1;
            }
            else if (nums[mid] < nums[mid-1]){
                high = mid -1;
            }
            else{
                ans = nums[mid];
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,2,3,1};
    vector<int> nums2 = {1,2,1,3,5,6,4};

    cout << "Peak (nums1): " << sol.peakElement(nums1) << endl;
    cout << "Peak (nums2): " << sol.peakElement(nums2) << endl;

    return 0;
}