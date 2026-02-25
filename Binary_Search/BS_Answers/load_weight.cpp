//code 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int days_capacity(vector<int> &weights, int capacity){
        int days=1;
        int load = 0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]+load>capacity){
                days++;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int mini = *max_element(weights.begin(),weights.end());
        int maxi=0;
        for(auto it:weights){
            maxi+=it;
        }
        int ans = INT_MAX;
        while(mini<=maxi){
            int mid = mini + (maxi-mini)/2;
            int days_with_capacity_mid = days_capacity(weights,mid);
            if(days_with_capacity_mid <= days){
                ans = min (ans,mid);
                maxi = mid-1;
            }
            else{
                mini = mid+1;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    Solution obj;
    int result = obj.shipWithinDays(weights, days);

    cout << "Minimum capacity required: " << result << endl;

    return 0;
}