//CODE 
//>n/3

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//BETTER SOLUTION
// vector<int> greaterthanNby3(int arr[], int size){
//     int k = size/3;
//     vector<int>res;
//     unordered_map <int,int>unMp;
//     for(int i=0;i<size;i++){
//         unMp[arr[i]]++;
//     }
//     int result = -1;
//     for(auto it:unMp){
//         if(it.second>k){
//             res.push_back(it.first);
//         }
//     }
//     return res;
// }


//OPTIMAL --> Cancellation logic 
vector<int> majorityElement(vector<int>& nums) {
    // int k = nums.size()/3;
    // vector<int>res;
    // unordered_map <int,int>unMp;
    // for(int i=0;i<nums.size();i++){
    //     unMp[nums[i]]++;
    // }
    // int result = -1;
    // for(auto it:unMp){
    //     if(it.second>k){
    //         res.push_back(it.first);
    //     }
    // }
    // return res;


    //OPTIMAL APPROACH
    vector<int>res;
    int elem1=0;
    int count1 =0;
    int elem2=0;
    int count2=0;

    for(int i=0;i<nums.size();i++){
        if(count1==0 && nums[i]!=elem2){
            elem1=nums[i];
            count1=1;
        }
        else if(count2==0 && nums[i]!=elem1){
            elem2=nums[i];
            count2=1;
        }
        else if(nums[i]==elem1){count1++;}
        else if(nums[i]==elem2){count2++;}
        else{
            count1--;
            count2--;
        }
    }

    count1=0;
    count2=0;

    for(int i =0;i<nums.size();i++){
        if(elem1==nums[i]){count1++;}
        else if(elem2==nums[i]){count2++;}
    }
    if(count1>nums.size()/3){
        res.push_back(elem1);
    }
    if(count2>nums.size()/3){
        res.push_back(elem2);
    }

    return res;
    }
int main(){
    // int arr[10]={312,31,31,21,31,31,2,2,2,2};
    // auto it = greaterthanNby3(arr,10);
    // for(auto aa:it){
    //     cout<<aa<<" ";
    // }
    return 0;
}