//CODE
#include <bits/stdc++.h>
using namespace std;

class Solution{

    public:
    //BEAUTIFUL APPROACH
    // SAY WE HAVE TOTAL number of elements in both 12
    //we have to have 6 and 6 each side
    // how will we do that say or vec1 has 1,5,8,12,13 and vec2 has 2,3,4,5,6,7,18
    // WE need 6 each side 
    //we have to take some from vec1 and some from vec2 such that
    /*
    Left Part  |  Right Part
    max(left part) ≤ min(right part)

    vec1: [1, 5, 8 | 12, 13]
                 ↑
    vec2: [2, 3, 4 | 5, 6, 7, 18]
                 ↑

    max(l1,l2) ≤ min(r1,r2)
    max(8,4) = 8
    min(12,5) = 5

    8 ≤ 5 ❌ FALSE




    vec1: [1,5 | 8,12,13]
    vec2: [2,3,4,5 | 6,7,18]

    max(5,5) = 5
    min(8,6) = 6

    5 ≤ 6 ✅ TRUE
    */


    int findMedianSortedArrays(vector<int>& nums1,vector<int> &nums2){

        int size1=nums1.size();
        int size2=nums2.size();
        
        int low = 0;
        int high =0;//maximum elements that we can pick
        if(size1>size2){
            high=size2;
        }
        else{
            high = size1;
        }
        int half = (size1+size2+1)/2;

        while(low<=high){
            int cut1 = (low+(high-low)/2);
            int cut2 = half - cut1;

            int left1, right1, left2, right2;

            if (cut1 == 0)
                left1 = INT_MIN;
            else
                left1 = nums1[cut1 - 1];

            if (cut1 == size1)
                right1 = INT_MAX;
            else
                right1 = nums1[cut1];

            if (cut2 == 0)
                left2 = INT_MIN;
            else
                left2 = nums2[cut2 - 1];

            if (cut2 == size2)
                right2 = INT_MAX;
            else
                right2 = nums2[cut2];

            if (left1 <= right2 && left2 <= right1) {

                if ((size1 + size2) % 2 == 0) {
                    int leftMax;
                    if (left1 > left2)
                        leftMax = left1;
                    else
                        leftMax = left2;

                    int rightMin;
                    if (right1 < right2)
                        rightMin = right1;
                    else
                        rightMin = right2;

                    return (leftMax + rightMin) / 2.0;
                }
                else {
                    if (left1 > left2)
                        return left1;
                    else
                        return left2;
                }
            }
            else if (left1 > right2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }
        }
        return 0.0;
        }
};

int main(){
    vector<int> nums1 = {1,3,3,5,3,4,6,3,2,5,6};
    vector<int> nums2 = {2,65,3,5,2,2,5,7,2,3123,34,4,5346,76,47,43,12,4,6,435321,31,23,6,5,6,2};

    Solution obj;

    double result = obj.findMedianSortedArrays(nums1, nums2);

    cout << "Median is: " << result << endl;
    return 0;
}