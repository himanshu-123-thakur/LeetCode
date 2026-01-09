//code 
//brute
#include <iostream>
#include<vector>
#include<math.h>
using namespace std;


//BRUTE FORCE -> O(n square)
// int maxconsec1(vector <int> v, int size)
// {
//     int result=0;
//     for(int i =0;i<v.size();i++){
//         int count=0;
//         if (v[i]==1){
//             count =1;
//         for(int j = i+1;j<v.size();j++){
//             if(v[j]==1){
//                 count ++;
//                 cout<<count<<endl;
//                 if(count>result){
//                     result=count;
//                 }
//                 cout<<result<<endl;
//             }
//             else{
//                 count++;
//                 break;
//             }
//         }
//     }
//     else{
//         continue;
//     }
//     }
//     return result;
// }


//BETTER APPROACH
//one loop only easy only;







int main(){
    vector <int> v={1,1,0,1,1,1,0,1,1};
    int n = maxconsec1(v,v.size());

    cout<<"Max consecutive of 1's is "<<n<<endl;
    return 0;
}