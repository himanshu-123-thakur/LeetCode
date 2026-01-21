//CODE
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// vector<vector<int>> mergeINTERVAL(vv){
//     vector<vector<int>> res;
//     int row = vv.size();
//     int col = vv[0].size();

    
//     return res;
// }


//BRUTE FORCE
//SORT

// vector<vector<int>> merge(vector<vector<int>>& intervals) {
//             vector<vector<int>> res;
//             sort(intervals.begin(),intervals.end());
    
//             for(int i=0;i<intervals.size();i++){
//                 int start = intervals[i][0];
//                 int end = intervals [i][1];
//                 if(!res.empty() && end<=res.back()[1]){continue;}
//                 else{
//                     for(int j=i+1;j<intervals.size();j++){
//                         if(intervals[j][0]<=end){
//                             end = max(end,intervals[j][1]);
//                         }
//                         else{
//                             break;
//                     }
//                 }
//             }
//             res.push_back({start,end});
    
//             }
//             return res;
// }



//OPTIMAL 
vector<vector<int>> merge(vector<vector<int>> &intervals){
    sort(intervals.begin(),intervals.end());

    vector<vector<int>> res;
    for(int i=0;i<intervals.size();i++){
        if(res.empty() || intervals[i][0]>res.back()[1]){
            res.push_back(intervals[i]);
        }
        else{
            res.back()[1]=max(res.back()[1],intervals[i][1]);
        }
    }
    return res;
}


int main(){
    vector<vector<int>> vv = {{1,3},
    {2,6},
    {8,9},
    {9,11},
    {8,10},
    {2,4},
    {15,18},
    {16,17}
};

    vector<vector<int>> vvv = merge(vv);
    for(auto it:vvv){
        for(auto tt:it){
            cout<<tt<<" ";
        }
        cout<<endl;
    }



    return 0;
}