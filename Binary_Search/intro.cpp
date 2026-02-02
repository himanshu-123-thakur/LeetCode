//BINARY SEARCH --> Applied only on sorted array/vector/seq

//o(log base2 N)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(vector<int> arr, int n,int low,int high){
    if(low>high){
        return -1;
    }
    int size = arr.size();
    int mid = low + (high-low)/2;

    if(arr[mid]==n){
        return mid;
    }
    else{
    
    if(n<arr[mid]) return binary_search(arr,n,low,mid-1);
    else return binary_search(arr,n,mid+1,high);
    }


}

int main(){
    vector <int> arr{23,12,3421,4,34,32,5,54,255,1};
    sort(arr.begin(),arr.end());
    for(auto it: arr){
        cout<<it<<" ";
    }
    cout<<endl;
    int n = 12;
    cout<<"The value "<<n<< " is present at Index = "<<binary_search(arr,n,0,arr.size()-1);
    cout<<endl;
    return 0;
}