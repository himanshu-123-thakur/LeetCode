//Code
//OPTIMAL APPROACH 
//MAP --> XOR upto i | count

// x^k = XR
// we are searchinf for x in MAP

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int noofSubarrayXOR(vector<int> v,int k){
    unordered_map<int,int> mp;
    int xr =0;
    mp[0]=1;
    int res =0;
    for(int i=0;i<v.size();i++){
        xr = xr^v[i];
        int x = xr^k;
        if(mp.find(x)!= mp.end()){
            mp[xr]++;
            res +=mp[xr];
        }
        else{
            mp[xr]++;
        }
    }
    return res;

}
int main(){
    vector<int>v{4,2,2,6,4};
    int k = 6;
    cout<< noofSubarrayXOR(v,k)<<" ******** ";
    return 0;
}