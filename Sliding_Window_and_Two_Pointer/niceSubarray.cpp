#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        unordered_map <int,int> mp;
        mp[0]=1; //CASE OF prefix sum == 0;

        int prefixSum=0;
        int ans = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }
            else{
                nums[i]=1;
            }
        }

        for(int i =0;i<nums.size();i++){
            prefixSum +=nums[i];

            if(mp.find(prefixSum - k)!=mp.end()){
                ans += mp[prefixSum-k];
            }

            mp[prefixSum]++;
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
    int k = 2;

    cout << obj.numberOfSubarrays(nums, k) << endl;

    return 0;
}