/*=========================================================

You are given an integer array `fruits` where fruits[i] represents
the type of fruit produced by the i-th tree.

You are visiting a farm that has a row of fruit trees arranged
from left to right.

RULES:

1. You have ONLY TWO baskets.
2. Each basket can contain ONLY ONE type of fruit.
3. Each basket can hold unlimited quantity of that fruit type.
4. You must start from ANY tree and move only to the RIGHT.
5. You must pick exactly ONE fruit from each tree.
6. If a third fruit type appears that cannot fit in your baskets,
   you must STOP.

GOAL:
Return the maximum number of fruits you can collect.

--------------------------------------------------------------------

Example:

Input:
fruits = [1,2,1]

Output:
3

Explanation:
We can collect all fruits because only two types exist.

--------------------------------------------------------------------

Example:

Input:
fruits = [0,1,2,2]

Output:
3

Explanation:
The longest valid subarray is [1,2,2]

--------------------------------------------------------------------

KEY OBSERVATION:

We need the longest subarray containing AT MOST 2 distinct elements.

This becomes a classic:

    "Longest Subarray with At Most K Distinct Elements"

where K = 2

--------------------------------------------------------------------

APPROACH: SLIDING WINDOW

We maintain:

left pointer  → start of window
right pointer → end of window

unordered_map:
stores fruit type frequency inside current window

Steps:

1. Expand window by moving right pointer
2. Add fruit to hashmap
3. If hashmap size > 2:
       shrink window from left
4. Update maximum window length

--------------------------------------------------------------------

Time Complexity:  O(N)
Each element enters and leaves the window once.

Space Complexity: O(1)
Map stores at most 3 elements.

====================================================================
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:

    int totalFruit(vector<int>& fruits) {

        // Left pointer of sliding window
        int left = 0;

        // Stores maximum fruits collected
        int ans = 0;

        // Map to store frequency of fruit types in window
        unordered_map<int,int> mp;

        for(int right = 0; right < fruits.size(); right++) {

            // Add current fruit to window
            mp[fruits[right]]++;

            // If more than 2 fruit types exist
            while(mp.size() > 2) {

                // Reduce frequency of left fruit
                mp[fruits[left]]--;

                // Remove fruit type if frequency becomes 0
                if(mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }

                // Shrink window
                left++;
            }

            // Update maximum window size
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main() {

    Solution obj;

    // Example test case
    vector<int> fruits = {1,2,1,2,3,2,2};

    int result = obj.totalFruit(fruits);

    cout << "Maximum fruits collected: " << result << endl;

    return 0;
}