#include <iostream>
using namespace std;
void nonzeroesatEnd(int nums[], int size){
    //BRUTE FORCE USES o(n square)

    int n = size;
    // for(int i =0;i<n;i++){
    //     if(nums[i]==0){
    //         for(int j=i+1;j<n;j++){
    //             if(nums[j]!=0){
    //                 swap(nums[i],nums[j]);
    //                 break;
    //             }
    //         }
    //     }
    // }



    //OPTIMAL SOLUTION - o(n)
    int insert =0;
    for (int i = 0; i < size; i++) {
    if (nums[i] != 0) {
        swap(nums[insert], nums[i]);
        insert++;
    }


    //OPTIMAL - two pointer  --> Striver could not understand properly
    //Finds the first 0 element
    // int j =-1;
    // for(int i=0;i<size;i++){
    //     if(nums[i]==0){
    //         j=i;
    //         break;
    //     }
    // }

    // //all non zero ahead of the zeroeth element
    // for(int i=j+1;i<size;i++){
    //     if(nums[j]!=0){
    //     swap(nums[i],nums[j]);
    //     j++;
    //     }

    // }
}
}

int main (){
    int arr[5]={0,1,0,3,12};
    nonzeroesatEnd(arr,5);
    for(auto &it:arr){
        cout<<it<<" ";
    }

}