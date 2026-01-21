//CODE
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int longestsubarraywithSUM0(vector<int>v){
    int prefixSUM=0;
    int best=0;
    unordered_map<int,int>mp;
    for(int i=0;i<v.size();i++){
        prefixSUM+=v[i];
        if(prefixSUM==0){
            best = max(best,i+1);
        }
        int rem = 0-prefixSUM;
        if(mp.find(rem)!
        =mp.end()){
            best = max(best,i-mp[rem]);
        }
        if(mp.find(rem)==mp.end()){
            mp[prefixSUM]=i;
        }
    }

    return best;
}
int main(){
    vector<int>v{1,0,-1,0,-2,2};
    cout<<longestsubarraywithSUM0(v)<<endl;
    return 0;
}