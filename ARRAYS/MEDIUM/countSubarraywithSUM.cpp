//CODE 
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//OPTIMAL --> USING HASH map (subarray given the sum)
//SOLVE

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    mp[0] = 1;

    int result = 0;
    int prefixsum = 0;

    for (int i = 0; i < nums.size(); i++) {
        prefixsum += nums[i];

        if (mp.find(prefixsum - k) != mp.end()) {
            result += mp[prefixsum - k];
        }

        mp[prefixsum]++;  // always update
    }
    return result;
}


int main(){
    vector<int>vv={1,2,3,-3,1,1,1,4,2,-3};
    int sum = 3;
    cout<<"COUNT IS = "<<subarraySum(vv,sum);
    return 0;
}