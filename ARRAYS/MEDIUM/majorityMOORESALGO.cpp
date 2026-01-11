//CODE
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    // USING HASMAPS --> BETTER
    // map<int,int> mp;
    // for(int i =0;i<nums.size();i++){
    //     mp[nums[i]]++;
    // }
    
    // for(auto &it : mp){
    //     if(it.second>(nums.size()/2)){
    //         return it.first;
    //     }
    // }

    // return -1;



    //MOORES ALGORITHM 
    //OPTIMAL APPROACH

    int element ;
    int count =0;


    for(int i=0;i<nums.size();i++){
        if(count==0){
            element = nums[i];
            count++;
        }
        else if(nums[i]==element){
            count++;
        }
        else{
            count--;
        }
    }
    int counter =0;
    for(int i =0;i<nums.size();i++){
        if(nums[i]==element){
            counter ++;
        }
    }
    if(counter > (nums.size()/2)){
        return element;
    }
    return -1;

}
int main(){
    vector<int> v = {2,2,1,1,1,2,2,1,1,1};
    majorityElement(v);
    cout<<"Majority Element is "<<majorityElement(v)<<endl;
    return 0;
}