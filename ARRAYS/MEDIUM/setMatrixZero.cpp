//Code
#include<iostream>
#include <vector>
using namespace std;

//BRUTE FORCE SOLUTION
//ALL CORRESPONDING ROW AND Column element which equals 1 are replaced by -1
//AT end all -1 are replaced by 0 and done
//o(n cube + n square)

void markROW(vector<vector<int>> &vv,int markROW){
    for(int i =0;i<vv[0].size();i++){
        if(vv[markROW][i]!=0){
            vv[markROW][i]=-1;
        }
    }
}

void markCOL(vector<vector<int>>&vv,int markCOL){
    for(int i =0;i<vv.size();i++){
        if(vv[i][markCOL]!=0){
            vv[i][markCOL]=-1;
        }
    }
}

void bruteSetZeroes(vector<vector<int>>&vv){
    int rows=vv.size();
    int cols= vv[0].size();

    for(int i =0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(vv[i][j]==0){
                markROW(vv,i);//Marks them -1
                markCOL(vv,j);// MArk them -1;
            }
        }
    }
    for(int i =0;i<rows;i++){
        for(int j =0;j<cols;j++){
            if(vv[i][j]==-1){
                vv[i][j]=0;
            }
        }
        cout<<endl;
    }

    for(int i =0;i<rows;i++){
        for(int j =0;j<cols;j++){

            cout<<vv[i][j]<<"     ,     ";
        }
        cout<<endl;
    }

}

int main(){

    vector<vector<int>>vv{{2,3,0,23},{312,321,3012,3},{432,3211,0,2},{123,1323,132,1}};
    bruteSetZeroes(vv);
    return 0;
}