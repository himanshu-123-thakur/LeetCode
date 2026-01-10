//SORT 0,1,2 in the arrays in a sorted manner
//CODE


//BRUTE FORCE --> sort using mergesort , quicksort
//BETTER APPROACH --> count number of 0 1 2 in array and put that number of 0 1 2 in same array;

//OPTIMAL approach ==> DUTCH NATIONAL FLAG ALGORITHM
//triple pointer approach
// 0 to low-1  ---->STORES 0
// low to mid -1  ----> STORES 1
//mid to high   -----> STORES UNSORTED ANYTHING
//high+1 to n-1  -----> STORES 2



#include <iostream>
using namespace std;

class dnf{
    public:
    void sort(int arr[], int size){
        int low=0;
        int mid = 0;
        int high = n-1;

        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else{
                swap(arr[mid],arr[high]);
                high --;
            }

        }
    }
};

int main(){
    int arr[11]={0,1,2,2,2,0,2,1,1,0,1};
    dnf algo;
    algo.sort(arr,11);
    return 0;
}