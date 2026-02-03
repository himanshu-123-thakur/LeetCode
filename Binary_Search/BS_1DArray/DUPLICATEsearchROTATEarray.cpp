/*
FLOW (remember in 3 lines):
1) If nums[low] == nums[mid] == nums[high] → shrink both ends (low++, high--)
2) If left half is sorted → check range, else right half is sorted
3) Narrow search to the half that CAN contain target
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int low = 0, high = (int)arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) return true;

            // duplicates ambiguity
            if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
                low++;
                high--;
                continue;
            }

            // left half sorted
            if (arr[low] <= arr[mid]) {
                if (arr[low] <= target && target < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // right half sorted
            else {
                if (arr[mid] < target && target <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {
        1,1,1,1,1,1,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1
    };
    int target = 13;

    bool found = sol.search(nums, target);

    cout << "Target " << target
         << (found ? " found" : " not found") << endl;

    return 0;
}
