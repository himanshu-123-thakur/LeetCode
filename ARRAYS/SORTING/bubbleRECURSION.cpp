#include <iostream>
using namespace std;
//WORKS BUT IT IS NOT BUBBLE SORT
// void bubbleRecursion_(int arr[],int low,int size){
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


//THIS ONE FIXES THE SMALLEST ELEMENT IN THE BEGINNNING 
void bubbleRecursion_1 (int arr[], int size,int start){
    if(start>=size)
    return;

    for(int i= size-2;i>=0;i--){
        if(arr[i]>arr[i+1])
        swap(arr[i],arr[i+1]);
    }
    bubbleRecursion_1(arr,size,start+1);
}


//THIS ONE FIXES THE LARGEST ELEMENT IN THE END
// void bubbleRecursion(int arr[], int size) {
//     if (size == 1) return;
    
//     // Go from left to right to bubble the largest element to the end
//     // This is what you NEED to fix the largest element
//     for (int i = 0; i < size - 1; i++) {
//         if (arr[i] > arr[i + 1]) {
//             swap(arr[i], arr[i + 1]);
//         }
//     }
    
//     // Then recur for the remaining array (size-1)
//     bubbleRecursion(arr, size - 1);
// }
int main(){
    int arr[9]={9,1,2,4,1,5,2,6,4};
    bubbleRecursion_1(arr,9,0);
    // bubbleRecursion(arr,9,0);
    for(int i =0;i<9;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}