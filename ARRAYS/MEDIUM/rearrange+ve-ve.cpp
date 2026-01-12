//code
#include <iostream>
#include <vector>

using namespace std;
// void rearrange(int arr[],int size){
//     int i=0;
//     int j=size-1;
//     while(i<j){
//         while(i < j && arr[i] < 0)
//             i++;

//         while(i < j && arr[j] > 0)
//             j--;
//         if(i<j){
//             swap(arr[i],arr[j]);
//             i++;
//             j--;
//         }
//     }
//     for(int i=0;i<size;i++){
//         cout<<arr[i]<<" ";
//     }
// }


//BETTER O(n)--->Time Complexity
//       o(n)--->Space Complexity

// void rearrangeArray(vector<int>& nums) {
//     vector<int>v(nums.size());
//     int pos=0;
//     int neg=1;
//     for(int i=0;i<nums.size();i++){
//         if(nums[i]>0){
//             v[pos]=nums[i];
//             pos +=2;
//         }
//         else{
//             v[neg]=nums[i];
//             neg +=2;
//         }
//     }
    

//     for(auto &it:v){
//         cout<<it<<" ";
//     }

// }

//OPTIMAL - if -ve and +ve both diff 
//GO BACK TO BRUTE 
// MAKE pos arr and neg array 
//and then result in even and odd remaining afterwards 

int main(){
    vector<int> vec={-3,28,1,4,-5,9,-10,11};
    //rearrangeArray(vec);
    return 0;
}