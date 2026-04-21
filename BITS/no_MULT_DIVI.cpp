#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {

        // Edge case: overflow
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine sign
        bool sign = true;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            sign = false;

        // Convert both to negative to avoid overflow
        int m = dividend > 0 ? -dividend : dividend;
        int n = divisor > 0 ? -divisor : divisor;

        int ans = 0;

        while(m <= n) {   // both are negative

            int temp = n;
            int multiple = 1;

            // prevent overflow during shifting
            while(temp >= (INT_MIN >> 1) && m <= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            m -= temp;
            ans += multiple;
        }

        return sign ? ans : -ans;
    }
};

int main() {

    Solution obj;

    int dividend = 10;
    int divisor = 3;

    int result = obj.divide(dividend, divisor);

    cout << "Result: " << result << endl;

    return 0;
}