//CODE - Merge Sort
//NOT O(n square)
//O(n log n) ----> TIME
//O(n) ----> SPACE
//DIVIDE AND MERGE 

#include <iostream>
#include <vector>

using namespace std;

vector<int> sort2array(int arr[], int left,int mid,int right){
    vector<int> temp;
    int n = mid+1;
    while(left<=mid && n<=right){
        if(arr[left]<=arr[n]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
        temp.push_back(arr[n]);
        n++;
        }
    }

    // Copy remaining elements from left half
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    
    // Copy remaining elements from right half
    while (n <= right) {
        temp.push_back(arr[n]);
        n++;
    }

    return temp;
}

void merge(int arr[], int size,int low , int high){
    int mid = (high+low)/2;
    if(low>=high)
    return;

    merge (arr,size,low,mid);
    merge (arr,size,mid+1,high);

    // FIX: get merged array
    vector<int> merged = sort2array(arr, low, mid, high);

    // FIX: copy back into original array
    for (int i = 0; i < merged.size(); i++) {
        arr[low + i] = merged[i];
    }

}
int main(){
    int arr[9]={3,1,2,4,1,5,2,6,4};
    merge(arr,9,0,8);
    cout<<"Sorted Array :[ ";
    for(int i =0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    cout<<" ]";
    return 0;
}