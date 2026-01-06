#include <iostream>
using namespace std;

//THIS IS NOT INSERTION SORT
// void insertionRecursion(int arr[], int size,int key){
//     if(key>=size)
//     return;

//     for(int i = 0;i<=key;i++){
//         int temp = arr[key];
//         if(arr[i]>arr[key]){
//             swap(arr[i],arr[key]);
//         }
//     }
//     insertionRecursion(arr,size,key+1);
// }

// THIS IS INSERTION WE DONT SWAP WE INSERT THE ELEMENT WE TAKE ARRAY ONE SIZE AT A TIME 
// GO forward and put the element in the correct opostion by right swiping

void insert(int arr[], int j) {
    if (j == 0 || arr[j - 1] <= arr[j])
        return;

    swap(arr[j], arr[j - 1]);
    insert(arr, j - 1);
}

void insertionRecursion(int arr[], int size, int key) {
    if (key >= size)
        return;

    insert(arr, key);
    insertionRecursion(arr, size, key + 1);
}
int main(){
    int arr[9]={9,1,2,4,1,5,2,6,4};
    insertionRecursion(arr,9,0);
    for(int i =0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}