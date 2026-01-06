//CODE
//O(NLogN) -> TIME complexity
//O(1) -> Space complexity --> so better than all

#include <iostream>
using namespace std;
int positionLEFTRIGHT (int arr[],int low,int high){
    int pivot = arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while (arr[j]>=pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }

    }
    swap(arr[low],arr[j]);
    return j;
}


void quickSORT (int arr[],int low,int high){

    if(low<high){
        int positionPartition = positionLEFTRIGHT(arr,low,high);
        quickSORT(arr,low,positionPartition-1);
        quickSORT(arr,positionPartition+1,high);
    }
    
}
int main(){
    int arr[9]={9,1,2,4,1,5,2,6,4};
    quickSORT(arr,0,8);
    for(int i =0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}