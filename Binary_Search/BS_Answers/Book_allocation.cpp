#include <bits/stdc++.h>
using namespace std;
bool allocatePossible(vector<int>books,int barrier,int mx){
    // Time Complexity:O(N log N) Space Complexity:O(1)
    int pages = 0,student = 1;
    for(int i=0;i<books.size();i++){
        if(pages + books[i]>barrier){
            pages = books[i];
            student++;
        }else{
            pages += books[i];
        }
    }if(student>mx) return false;
    return true;
}
int maximumBookAllocation(vector<int>&books,int mx){
    int low = *max_element(books.begin(),books.end());
    int high = accumulate(books.begin(),books.end(),0);
    while(low<=high){
        int mid = low+(high-low)/2;
        if(allocatePossible(books,mid,mx)){
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}
int main() {
    // case 1
    // vector<int>arr={12,34,67,90};
    // int m = 2;
    // case 2
    vector<int>arr={25, 46, 28, 49, 24};
    int m = 4;
    int ans = maximumBookAllocation(arr,m);
    cout<<"The Maximum Pages assigned is "<<ans;
    return 0;
}