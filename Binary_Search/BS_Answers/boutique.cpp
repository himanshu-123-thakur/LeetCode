#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k, int day) {
        int cnt = 0;
        int bouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                cnt++;
                if (cnt == k) {
                    bouquets++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        // BRUTE FORCE
        // set<int> st;
        // for (auto it : bloomDay) {
        //     st.insert(it);
        // }
        //
        // if (1LL * m * k > bloomDay.size()) {
        //     return -1;
        // }
        //
        // for (auto day : st) {
        //     int adj = 0;
        //     int boq = 0;
        //
        //     for (int j = 0; j < bloomDay.size(); j++) {
        //         if (bloomDay[j] <= day) {
        //             adj++;
        //             if (adj == k) {
        //                 boq++;
        //                 adj = 0;
        //             }
        //         } else {
        //             adj = 0;
        //         }
        //     }
        //
        //     if (boq >= m) {
        //         return day;
        //     }
        // }
        //
        // return -1;

        // OPTIMAL: BINARY SEARCH
        if (1LL * m * k > bloomDay.size()) {
            return -1;
        }

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(bloomDay, m, k, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> bloomDay(n);
    for (int i = 0; i < n; i++) {
        cin >> bloomDay[i];
    }

    Solution obj;
    int ans = obj.minDays(bloomDay, m, k);

    cout << ans << endl;
    return 0;
}