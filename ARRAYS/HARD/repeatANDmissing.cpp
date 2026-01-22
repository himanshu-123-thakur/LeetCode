#include <bits/stdc++.h>
using namespace std;


//BRUTE
// USE HAS ARRAY OF SIZE nums.size()+1 EASIER

// vector<int> findErrorNums(vector<int>& nums) {
//     unordered_map<int,int>mp;
//     int repeat=0;
//     for(int i=0;i<nums.size();i++){
//         mp[nums[i]]++;
//         if(mp[nums[i]]==2){
//             repeat = nums[i];
//             break;
//         }
//     }
//     int n = nums.size();
//      int sum =0;
//     for(int i =0;i<n ;i++){
//         sum+=nums[i];
//     }
//     int expected_sum = n*(n+1)/2;
//     int missing = repeat -(sum-expected_sum);


//     vector<int>r;
//     r.push_back(repeat);
//     r.push_back(missing);

   

//     return r;
    
// }



//OPTIMAL IS UISN MATHS currentSUM - expSUM = res1;
//                      currentSUM(square all no) - expSUM(square all No) = res2;
//                      this can be written as (x-y)(x+y)=res2;
// SOLVE BOTH AND GET SOL

vector<int> findErrorNums(vector<int>nums){
long long n = nums.size();

long long sum = 0, sq = 0;
for (int x : nums) {
    sum += x;
    sq +=  x * x;
}

long long expectedSum = n * (n + 1) / 2;
long long expectedSq  = n * (n + 1) * (2 * n + 1) / 6;

long long S = expectedSum - sum;     // missing - repeating
long long P = expectedSq - sq;       // missing^2 - repeating^2

long long sumMR = P / S;             // missing + repeating

long long missing = (S + sumMR) / 2;
long long repeating = missing - S;

vector<int>res;
res.push_back(repeating);
res.push_back(missing);
return res;
}



// int main() {
//     vector<int> nums = {1, 2, 3, 4};   // Test input

//     vector<int> result = findErrorNums(nums);

//     cout << "Repeated number: " << result[0] << endl;
//     cout << "Missing number: " << result[1] << endl;

//     return 0;
// }

int main() {
    vector<vector<int>> tests = {
        {1,2,2,4},   // repeat 2, miss 3
        {2,2},       // repeat 2, miss 1
        {3,1,2,5,3}  // repeat 3, miss 4
    };

    for (auto &nums : tests) {
        auto ans = findErrorNums(nums);
        cout << "Input: ";
        for (int x : nums) cout << x << " ";
        cout << "\nRepeating: " << ans[0] << ", Missing: " << ans[1] << "\n\n";
    }
}
