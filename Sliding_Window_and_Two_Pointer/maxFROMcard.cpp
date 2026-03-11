//CAN BE any 0 from start k from end 
//           1 from start k-1 from end
//           and so on

// OS WE took left sum till k
// then we remove klast and take one from righ t
// max we give 

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();
        
        int leftSum = 0;

        for(int i = 0; i < k; i++){
            leftSum += cardPoints[i];
        }

        int ans = leftSum;
        int rightSum = 0;

        for(int i = 1; i <= k; i++){

            leftSum -= cardPoints[k - i];
            rightSum += cardPoints[n - i];

            ans = max(ans , leftSum + rightSum);
        }

        return ans;
    }
};

int main(){

    vector<int> cardPoints = {100,40,17,9,73,75};
    int k = 3;

    Solution obj;

    int result = obj.maxScore(cardPoints , k);

    cout << "Maximum Score: " << result << endl;

    return 0;
}