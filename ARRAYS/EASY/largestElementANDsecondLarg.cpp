//code - // BRUTE Will be sorting an array and priting the last element , O(nlogn)
//       // OPTIMAL - O(n)
#include <iostream>
using namespace std;

int largestElement(int arr[],int size){
    int largest=arr[0];
    for(int i =0;i<size;i++){
        if(largest<arr[i])
        largest = arr[i];
        else
        continue;
    }
    return largest;
}

//code - sort+compare = o(nlogn)+n
//better solution - traverse find largest and again travest so - o(n)+o(n) = O(2n)
//optimal solution - traverse once o(n)

int secondLargestElement_optimal (int arr[],int size){
    if (size < 2) return -1;
    int largest = INT32_MIN;
    int second_largest = INT32_MIN;
    for(int i=0;i<size;i++){
        if(arr[i]>largest){
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > second_largest) {
            second_largest = arr[i];
        }
        // else if(arr[i]>second_largest){
        //     second_largest=arr[i];
        // }
        else
        continue;
    }
    return second_largest;
}

int secondSMALLEST(int arr[],int size){
    int smallest = INT32_MAX;
    int ssmallest = INT32_MAX;
    for(int i=0;i<size;i++){
        if(arr[i]< smallest){
            smallest = arr[i];
            ssmallest = smallest;
        }
        else if(arr[i]>smallest && arr[i]<ssmallest){
            ssmallest = arr[i];
        }
        else{
            continue;
        }
    }
    return ssmallest;
}

// int secondLargestElement(int arr[],int size){
//     int secondlargest=arr[0];
//     int largest = largestElement(arr,size);
//     for(int i =0;i<size;i++){
//         if(secondlargest<arr[i] && arr[i]!=largest){
//             secondlargest=arr[i];
//         }
//         else
//         continue;
//     }
//     return secondlargest;
// }

int main(){
    int size;
    cin >> size;
    int arr[size];
    for(auto &it:arr){
        cin>>it;
    }
    cout<<endl;
    cout<<"Array : ";
    for(auto &it:arr){
        cout<<it<<" ";
    }

    cout<<endl;
    cout<<"Largest is : "<<largestElement(arr,size)<<endl;
    // cout<<"Second Largest is : "<<secondLargestElement(arr,size)<<endl;
    cout<<"Second Largest is : "<<secondLargestElement_optimal(arr,size)<<endl;
    cout<<"Second Samllest is : "<<secondSMALLEST(arr,size);


    return 0;
}