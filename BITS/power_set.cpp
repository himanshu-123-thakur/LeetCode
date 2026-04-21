//CODE


/*
    BITMASK LOGIC (VERY IMPORTANT):

    For an array of size n:
    total subsets = 2^n = (1 << n)

    Each number i (0 to 2^n - 1) acts as a "mask"
    Binary representation of i tells which elements to include

    Example (arr = [1,2,3,4]):

    i = 5 → binary = 0101

    index:      3  2  1  0
    bits:       0  1  0  1

    Meaning:
    bit 0 = 1 → include arr[0] = 1
    bit 1 = 0 → skip   arr[1] = 2
    bit 2 = 1 → include arr[2] = 3
    bit 3 = 0 → skip   arr[3] = 4

    → subset = [1,3]

    Inner loop checks each bit using:
    (i & (1 << j))

    If result ≠ 0 → bit is ON → include element
    If result = 0 → bit is OFF → skip element
    */


#include <iostream>
#include <vector>

using namespace std;
int main(){
    vector<vector<int>> v;
    vector<int> arr = {1,2,3,4};

    for(int i = 0 ;i< (1<<arr.size()); i++){
        vector<int> v_sub ;
        for(int j =0;j< arr.size();j++){
            if(i&(1<<j)){
                v_sub.push_back(arr[j]);
            }
        }
        v.push_back(v_sub);
    }

        // PRINT ALL SUBSETS
        cout << "All subsets:\n";
        for(auto &subset : v) {
            cout << "[ ";
            for(int x : subset) cout << x << " ";
            cout << "]\n";
        }
    

    return 0;
}