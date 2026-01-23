#include <iostream>
#include <vector>
using namespace std;
int pairs=0;

void sortandpaircount(vector<int>&v, int left,int mid,int end){
    int right = mid+1;
    int aa = left;
    vector<int> temp;

    //FOR OUR PAIRS
    int j = mid + 1;
    for (int i = left; i <= mid; i++) {
        while (j <= end && (long long)v[i] > 2LL * v[j]) j++;
        pairs += (j - (mid + 1));
    }


    while(left<=mid && right<=end){
        if(v[left]<=v[right]){
            temp.push_back(v[left]);
            left++;
        }
        else{
            temp.push_back(v[right]);
            right++;
        }
    }

        // Copy remaining elements from left half
        while (left <= mid) {
            temp.push_back(v[left]);
            left++;
        }
        
        // Copy remaining elements from right half
        while (right <= end) {
            temp.push_back(v[right]);
            right++;
        }


    // copy back to v[start..end]
    for (int i = 0; i < (int)temp.size(); i++) {
        v[aa + i] = temp[i];
    }

}
void mergeandsort(vector<int> &v,int left,int end){
    int mid = (left+end)/2;
    int right = mid+1;
    if(left>=end)return;
    
    mergeandsort(v,left,mid);
    mergeandsort(v,mid+1,end);
    sortandpaircount(v,left,mid,end);
}
int reversePairs(vector<int> &v){
    mergeandsort(v,0,v.size()-1);
    return pairs;
}
int main(){
    vector<int>v={21,32,3,123,213,213,213,4,343,4,35,435,554};
    
    cout<<"Pair = "<<reversePairs(v)<<endl;
    return 0;
}