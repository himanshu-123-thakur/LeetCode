//CODE
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//BRUTE FORCE --> maintain count two array count maximum vallue return O(n square)


//BETTER APPROACH --> SORT USING quick/MergeSort O(nlog n) + then a loop to count shit and all
// void longestconsecutive(vector<int>v){
//     sort(v.begin(),v.end());
//     if(v.size()==0){
//         cout<<"No Consecutive"<<endl;
//     }

//     int longest=1;
//     int last_smaller=INT_MIN;
//     int count =1;

//     for(int i =0;i<v.size();i++){
//         if(v[i]-1 == last_smaller){
//             count++;
//             last_smaller=v[i];
//         }
//         else if(last_smaller!=v[i]){
//             count = 1;
//             last_smaller=v[i];
//         }
//          else{
//            continue;
//        }
//         longest = max(longest,count);
//     }

//     cout<<"Longest is "<<longest;

// }



//OPTIMAL APPROACH //O(3N)
void longestconsecutive(vector<int>v){

}



int main(){
    vector <int> v {100,102,100,101,4,3,2,3,1,1,1,2,5,5,425,245,245,234,5};
    longestconsecutive(v);
    return 0;
}