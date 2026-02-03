//Code
//Lower Bound smallest index in which arr[index]>=target
//UB smallest index arr[index]>target


//in lower bound use >=
//in upper only >

//lower_bound(arr,arr+n,target)
//return (lower_bound(arr,arr+n,target) - (iterator that point s to first elemt of array )

#include <bits/stdc++.h>
using namespace std;

int lower_bound_rec(const vector<int>& arr, int target, int low, int high) {
    if (low > high) return low;
    int mid = low + (high - low) / 2;
    if (arr[mid] >= target) return lower_bound_rec(arr, target, low, mid - 1);
    return lower_bound_rec(arr, target, mid + 1, high);
}

int upper_bound_rec(const vector<int>& arr, int target, int low, int high) {
    if (low > high) return low;
    int mid = low + (high - low) / 2;
    if (arr[mid] > target) return upper_bound_rec(arr, target, low, mid - 1);
    return upper_bound_rec(arr, target, mid + 1, high);
}

int main() {
    vector<int> arr{23,12,3421,4,34,32,5,54,255,1};
    sort(arr.begin(), arr.end());

    int target = 15;

    int lb = lower_bound_rec(arr, target, 0, (int)arr.size() - 1);
    int ub = upper_bound_rec(arr, target, 0, (int)arr.size() - 1);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    if (lb == (int)arr.size()) cout << "Lower Bound: not found (would be end)\n";
    else cout << "Lower Bound index = " << lb << ", value = " << arr[lb] << "\n";

    if (ub == (int)arr.size()) cout << "Upper Bound: not found (would be end)\n";
    else cout << "Upper Bound index = " << ub << ", value = " << arr[ub] << "\n";

    return 0;
}
