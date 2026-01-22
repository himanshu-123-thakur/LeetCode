//Double negative flip signs
//0 also 

#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int prefix = 1;
    int suffix = 1;

    int maxres = INT_MIN;
    int n = nums.size();

    for(int i = 0; i < n; i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;

        prefix = prefix * nums[i];
        suffix = suffix * nums[n-1-i];

        maxres = max(maxres, max(prefix, suffix));
    }

    return maxres;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};

    int ans = maxProduct(nums);

    cout << "Maximum Product Subarray = " << ans << endl;

    return 0;
}
