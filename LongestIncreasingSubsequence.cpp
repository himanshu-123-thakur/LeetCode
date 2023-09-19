class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        int maxi=1;
        vector<int>dp(size,1);
        for(int i=0;i<size;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            maxi=max(dp[i],maxi);
        }
        return maxi;
    }

};
