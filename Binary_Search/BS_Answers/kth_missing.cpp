//CODE
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // arr[mid] - (mid + 1)
            //
            // Layman explanation:
            // If the array had NO missing numbers, then at index mid,
            // the value should ideally be (mid + 1).
            //
            // Example:
            // Index:  0  1  2  3
            // Ideal:  1  2  3  4
            //
            // But if arr[mid] is bigger than (mid+1),
            // that means some numbers are missing before it.
            //
            // So:
            // missing numbers till this index = arr[mid] - (mid + 1)
            //
            // This tells us how many numbers are missing before arr[mid].
            // That is the key insight which makes binary search possible.

            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
                /*
        Why left + k works (VERY SIMPLE EXPLANATION):

        Think like this:

        If the array was empty,
        the k-th missing number would simply be k.

        But the array has some real numbers in it.
        Those real numbers "take space" on the number line
        and push the missing numbers forward.

        When binary search finishes,
        left tells us how many array elements
        are sitting BEFORE the k-th missing number.

        Those elements push the answer forward by left positions.

        So:

        answer = k (basic position)
                 + left (push caused by existing numbers)
        */

        return left + k;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    int result = obj.findKthPositive(arr, k);

    cout << "Kth missing positive number: " << result << endl;

    return 0;
}