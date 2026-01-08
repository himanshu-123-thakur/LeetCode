//code 
#include <iostream>
#include <map>

using namespace std;
int main(){
    int n =5;
    int arr[n]={1,2,4,5};


    //BRUTE SOLUTION
    //start from make two loops compare and so on


    //BETTER APPROACH 
    // map <int,int>mp;
    // for(int i=0;i<6;i++){
    //     mp[arr[i]]=1;
    // }
    // for(auto &it:mp){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    // int result;
    // for(int i=1;i<5;i++){
    //     if (mp[i]==0){
    //         result=i;
    //     }
    // }





    //OPTIMAL SOLUTION ==> 2 TYPES 
    //SUM 
    int sum = (n*(n+1))/2;
    int actsum;
    for(int i =0;i<5;i++){
        actsum+=arr[i];
    }
    int result= sum - actsum;



    //XOR
    //striver siolution easy only 

    cout<<"The number missing is : "<<result;
    return 0;
}