//OPTIMAL
//SIMPLEST APPROACH
//[0,2,4,6,8]
//[5,7,9,10]
//2 pointer one at last of 1st array and ine at starting of second array



//OPTIMAL - 2 
//GAP = ceil(size/2)
//i = 0 , j = gap

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void swapGG(vector<int>& a, vector<int>& b, int i, int j){
        if(a[i] > b[j]) swap(a[i], b[j]);
    }

public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m + n;
        int gap = (len / 2) + (len % 2);

        while(gap > 0){
            int left = 0;
            int right = gap;

            while(right < len){
                if(left >= m){
                    swapGG(nums2, nums2, left - m, right - m);
                }
                else if(right >= m){
                    swapGG(nums1, nums2, left, right - m);
                }
                else{
                    swapGG(nums1, nums1, left, right);
                }
                left++;
                right++;
            }

            if(gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }

        // copy nums2 into nums1 tail
        for(int i = 0; i < n; i++){
            nums1[m + i] = nums2[i];
        }
    }
};

static void printVec(const vector<int>& v, const string& name){
    cout << name << " = [ ";
    for(int x : v) cout << x << " ";
    cout << "]\n";
}

int main(){
    vector<int> nums1 = {-5, -2, 4, 5, 0, 0, 0};
    vector<int> nums2 = {-3, 1, 8};
    int m = 4;
    int n = 3;

    Solution sol;

    cout << "Before:\n";
    printVec(nums1, "nums1");
    printVec(nums2, "nums2");

    sol.merge(nums1, m, nums2, n);

    cout << "\nAfter merge (nums1):\n";
    printVec(nums1, "nums1");

    return 0;
}
