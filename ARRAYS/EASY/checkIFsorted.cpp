//code
#include <iostream>
using namespace std;


//code - this is a O(n)

bool checkIfSorted (int arr[], int size ){
    // if (size<2)
    // return true;

    // return checkIfSorted(arr,size/2);

    // for(int i=1;i<size-1;i++){
    //     //&& arr[i]<=arr[i+1]
    //     if(arr[i]>=arr[i-1])
    //     continue;
    //     else
    //     return false;
    // }
    // return true;

    if (size <= 1) return true;

    if (arr[size - 2] > arr[size - 1])
        return false;

    return checkIfSorted(arr, size-1);
}


int main(){
    int size;
    cin>>size;
    int arr[size];
    for(auto &it:arr){
        cin>>it;
    }
    cout<<boolalpha;
    cout<<"ARRAY is sorted : "<<checkIfSorted(arr,size)<<endl;
    return 0;
}