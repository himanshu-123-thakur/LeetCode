//Code 
#include <iostream>
#include <map>
using namespace std;

//BRUTE FORCE  --> O(n square)
// int longestsubarraywithK(int arr[], int size, int k){
//     int maxLen = 0;

//     for(int i=0;i<size;i++){
//         int sum = 0;
//         for(int j=i;j<size;j++){
//             sum += arr[j];

//             if(sum == k){
//                 maxLen = max(maxLen, j-i+1);
//             }
//         }
//     }
//     return maxLen;
// }


//BETTER APPROACH  //DOES NOT WORK for 0's and -ve
void longestsubarraywithK(int arr[], int size, int k){
    map<long long,long long> mp;
    int sum=0;
    int length =0;
    for(int i =0;i<size;i++){
        sum +=arr[i];
        // mp[sum]=i;

        // Case 1: subarray from 0..i
        if(sum == k){
            length = max(length, i + 1);
        }
        

        int rem = sum -k;
        if(mp.find(rem)!=mp.end()){
            int l = i-mp[rem];
            length = max(length,l);
        }
        //TO cover case of 0 //VERY IMPORTANT
        if(mp.find(sum)==mp.end())
        {
            mp[sum]=i;
        } 
    }
    // for(auto &it:mp){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    cout<<length<<endl;
    //NOW 

}



int main(){
    int arr[10]={1,2,3,1,1,1,1,4,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum =3;
    cout<<"Longest subarray size with sum "<<sum<<" is = ";
    longestsubarraywithK(arr,10,sum);
    return 0;
}