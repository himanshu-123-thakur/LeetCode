//Code
//BRUTE FORCE
#include <iostream>
#include <unordered_map>
using namespace std;


// // TO USE THIS WE NEED TO SORT THE ARRAY FIRST USING nlogn
//THIS IS ACTUALLY THE OPTIMAL SOLUTION LMFAOOOOOOOO
// void brute2sum (int arr[],int size,int target){
//     sortquick(arr,0,size-1);
//     int i=0;
//     int j= size-1;
//     while(i<j){

//         if(arr[i]+arr[j]==target){
//             cout<<"NICE there exists at index : "<<i<<" and "<<j<<endl;
//             break;
//         }
//         else if(arr[i]+arr[j]>target){
//             j--;
//         }
//         else{
//             i++;
//         }


//     }
// }




//BETTER APPROACH 
//HASH
void better2sum(int arr[],int size,int target){
    unordered_map<int,int>mp;

    for(int i =0;i<size;i++){
        int rem=target-arr[i];
        if(mp.find(rem)!=mp.end()){
            cout<<"Exists at "<<mp[rem]<<" and "<<i<<endl;
            return;
        }
        else{
            mp[arr[i]]=i;
        }

    }
    cout<<"NO PAIR"<<endl;
}

int main(){
    int arr[5]={2,6,5,8,11};
    int target=0;
    cin>>target;
    //brute2sum(arr,5,target);
    better2sum(arr,5,target);
    return 0;
}
