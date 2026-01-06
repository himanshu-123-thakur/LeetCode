#include <iostream>
using namespace std;
//WORKS BUT IT IS NOT BUBBLE SORT
// void bubbleRecursion_1(int arr[],int low,int size){
//     if (low>=(size-1))
//     return;

//     if(arr[low]>arr[low+1]){
//         for(int i=low+1;i>0;i--){
//             if(arr[i]<arr[i-1]){
//                 swap(arr[i],arr[i-1]);
//             }
//         }
//     }
//     bubbleRecursion(arr,low+1,size);
// }



void bubbleRecursion (int arr[], int size){
    if(size==1)
    return;

    for(int i= size-2;i>=0;i--){
        if(arr[i]>arr[i+1])
        swap(arr[i],arr[i+1]);
    }
    bubbleRecursion(arr,size-1);
}
int main(){
    int arr[9]={3,1,2,4,1,5,2,6,4};
    // bubbleRecursion_1(arr,0,9);
    bubbleRecursion(arr,9);
    for(int i =0;i<9;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}