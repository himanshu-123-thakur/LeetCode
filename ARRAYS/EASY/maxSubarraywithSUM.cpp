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


//BETTER APPROACH  //DOES NOT WORK for 0's and -ve // for that we have added a little one down 
// THis is the optimal solution for -ve and arrays 
// for +ves we can do better
// void longestsubarraywithK(int arr[], int size, int k){
//     map<long long,long long> mp;
//     int sum=0;
//     int length =0;
//     for(int i =0;i<size;i++){
//         sum +=arr[i];
//         // mp[sum]=i;

//         // Case 1: subarray from 0..i
//         if(sum == k){
//             length = max(length, i + 1);
//         }
        

//         int rem = sum -k;
//         if(mp.find(rem)!=mp.end()){ ///MEANS IF THE remainder is PRESENT then do this
//             int l = i-mp[rem];
//             length = max(length,l);
//         }
//         //TO cover case of 0 //VERY IMPORTANT
//         if(mp.find(sum)==mp.end())  ///MEANS IF THE sum is NOT PRESENT BEFORE then do this
//         {
//             mp[sum]=i;
//         } 
//     }
//     // for(auto &it:mp){
//     //     cout<<it.first<<" "<<it.second<<endl;
//     // }

//     cout<<length<<endl;
//     //NOW 

// }


//OPTIMAL - 2 POINTER , sliding window only for +ve and 0
//TC ----> O(2n)
//SC ----> O(1)

void longestsubarraywithK(int arr[], int n, int k){
    // int i = 0;
    // long long sum = 0;
    // int best = 0;

    // for(int j = 0; j < n; j++){
    //     sum += arr[j];                 // expand window by including arr[j]

    //     while(i <= j && sum > k){      // shrink from left until sum <= k
    //         sum -= arr[i];
    //         i++;
    //     }

    //     if(sum == k){
    //         best = max(best, j - i + 1);
    //     }
    // }
    // cout<<best;


    int j = 0;
    long long sum = 0;
    int best = 0;

    for(int i =0;i<n;i++){  //i goes forwars in sum 
        sum+=arr[i];
        for(;j<=i && sum>k ;j++){ //start to shrink from left if sum>k ,
            if(sum>k){
                sum -=arr[j];
            }
        }
        if(sum==k){
            best = max(best,i-j+1);
        }
    }
    cout<<best;
}


int main(){
    int arr[10]={1,2,3,1,1,1,1,4,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum =3;
    cout<<"Longest subarray size with sum "<<sum<<" is = ";
    longestsubarraywithK(arr,10,sum);
    return 0;
}