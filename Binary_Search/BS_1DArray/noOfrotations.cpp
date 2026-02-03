//code 

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int count = 0;

    int findKRotation(vector<int> & nums){
        int mid;
        int ans = INT_MAX;
        int low = 0; 
        int high = nums.size()-1;
        while(low<=high){
            mid = low + (high-low)/2;
            // current mid is a candidate minimum
            if(nums[mid]>nums[high]){
                 ans = min(ans, nums[mid]);
                low = mid+1;
            }
            else{
                 ans = min(ans, nums[mid]);
                high = mid -1;
            }
        }
        return mid;
    }

};
int main() {
    Solution sol;

    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    // array rotated 4 times

    int rotations = sol.findKRotation(arr);

    cout << "Array is rotated " << rotations << " times" << endl;

    return 0;
}
