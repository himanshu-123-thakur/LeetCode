//CODE 
//3 SUM

#include<iostream>
#include <vector>
#include<set>
#include <algorithm>
#include <cmath>

using namespace std;
//BRUTE --> Ncube
// vector<vector<int>> threeSum(vector<int>& nums) {
//     vector<int>v;
//     set<vector<int>> st;
//     for(int i=0;i<nums.size();i++){
//         for(int j =i+1;j<nums.size();j++){
//             for(int k = j+1;k<nums.size();k++){
//                 if(nums[i]+nums[j]+nums[k]==0){
//                     v = {nums[i],nums[j],nums[k]};
//                     sort(v.begin(),v.end());
//                     st.insert(v);
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(),st.end());

//     return ans;
// }



//BETTER ---> we will remove third loop use map
// betwen i and j what elemtns is there we put in map
// vector<vector<int>> threeSum(vector<int>& nums) {
//     set<vector<int>> st;
//     for(int i=0;i<nums.size();i++){
//         set<int> hashmap ;
//         for(int j =i+1;j<nums.size();j++){
//             int k = -(nums[i]+nums[j]);
//             if(hashmap.find(k)!=hashmap.end()){
//                 vector<int> temp = {nums[i],nums[j],k};
//                 sort(temp.begin(),temp.end());
//                 st.insert(temp);
//             }
//             hashmap.insert(nums[j]);

//         }
//     }
//     vector<vector<int>> ans(st.begin(),st.end());

//     return ans;
// }


vector<vector<int>> threeSum(vector<int>& nums) {
//OPTIMAL SOLUTION 
//2 POINTER APPROACH

int i=0;

sort(nums.begin(),nums.end());

vector<int>v;
set<vector<int>>st;
while(i<nums.size()-2){
int j=i+1;
int k =nums.size()-1;
    while(j<k){
        if(nums[i]+nums[j]+nums[k]>0){
            k--;
            while(j<k && nums[k]==nums[k+1]){
                k--;
            }
        }
        else if(nums[i]+nums[j]+nums[k]<0){
            j++;
            while(j<k && nums[j]==nums[j-1]){
                j++;
            }
        }
        else{
            v={nums[i],nums[j],nums[k]};
            st.insert(v);
            j++;
            k--;
            while(j<k && nums[k]==nums[k+1]){
            k--;
            }
            while(j<k && nums[j]==nums[j-1]){
            j++;
            }
        }
    }
    i++;
     while (i < nums.size() - 2 && nums[i] == nums[i - 1]) i++;
}
   vector<vector<int>> vv(st.begin(),st.end());
   return vv;
}


int main(){
    vector<int>v ={-1,0,1,2,-1,-4};
    auto it = threeSum(v);

    for(auto t:it){
        for(auto ttt: t){
        cout<<ttt<<",";
        }
        cout<<endl;
    }
    return 0;
}