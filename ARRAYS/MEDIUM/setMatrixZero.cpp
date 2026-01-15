//Code
#include<iostream>
#include <vector>
using namespace std;

//BRUTE FORCE SOLUTION
//ALL CORRESPONDING ROW AND Column element which equals 1 are replaced by -1
//AT end all -1 are replaced by 0 and done
//o(n cube + n square)

// void markROW(vector<vector<int>> &vv,int markROW){
//     for(int i =0;i<vv[0].size();i++){
//         if(vv[markROW][i]!=0){
//             vv[markROW][i]=-1;
//         }
//     }
// }

// void markCOL(vector<vector<int>>&vv,int markCOL){
//     for(int i =0;i<vv.size();i++){
//         if(vv[i][markCOL]!=0){
//             vv[i][markCOL]=-1;
//         }
//     }
// }

// void bruteSetZeroes(vector<vector<int>>&vv){
//     int rows=vv.size();
//     int cols= vv[0].size();

//     for(int i =0;i<rows;i++){
//         for(int j=0;j<cols;j++){
//             if(vv[i][j]==0){
//                 markROW(vv,i);//Marks them -1
//                 markCOL(vv,j);// MArk them -1;
//             }
//         }
//     }
//     for(int i =0;i<rows;i++){
//         for(int j =0;j<cols;j++){
//             if(vv[i][j]==-1){
//                 vv[i][j]=0;
//             }
//         }
//         cout<<endl;
//     }

//     for(int i =0;i<rows;i++){
//         for(int j =0;j<cols;j++){

//             cout<<vv[i][j]<<"     ,     ";
//         }
//         cout<<endl;
//     }

// }





//ONE MORE WAY TO DO BRUTE FORCE 
//WE TAKE NOTE OF ROW AND COLUMN WITH 0 in it 
//for tha we use row[size]={0},col[size]={0}, now when traversin ggif arr[i][j]==0 we mark col[j]=1 and row[i]=1; 
//after done, we again travese and if row[i]||col[j]==1 if true then arr[i][j]=0;

// void setZeroes(vector<vector<int>>& matrix) {
//     int n = matrix.size();
//     int m = matrix[0].size();

//     vector<int> row(n, 0);
//     vector<int> col(m, 0);

//     // Step 1: mark rows and columns
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             if(matrix[i][j] == 0){
//                 row[i] = 1;
//                 col[j] = 1;
//             }
//         }
//     }

//     // Step 2: update matrix
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             if(row[i] == 1 || col[j] == 1){
//                 matrix[i][j] = 0;
//             }
//         }
//     }


//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<matrix[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }


//OPTIMAL APPROACH
//the extra row[m],col[n] we took to mark anmnd then later change is done in the matrix itself
//except [0][0]is to be taken care seperately

void setZeroes(vector<vector<int>> &vv){
    int n = vv.size();
    int m =vv[0].size();

    //row =[0][..]
    //col = [..][0]
    int col0=1;


    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            if(vv[i][j]==0){
                vv[i][0]=0;
                if(j!=0){
                    vv[0][j]=0;
                }else{
                    col0=0;
                }
            }
        }
    }

    for(int i =1;i<n;i++){
        for(int j=1;j<m;j++){
            if(vv[i][j]!=0){
                //check our marked shit
                if(vv[0][j]==0 || vv[i][0]==0){
                    vv[i][j]=0;
                }
            }
        }
    }

    if(vv[0][0]==0){
        for(int i=0;i<m;i++){
            vv[0][i]=0;
        }
    }
    if(col0==0){
        for(int i=0;i<n;i++){
            vv[i][0]=0;
        }
    }

        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<vv[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    vector<vector<int>>vv{{2,3,0,23},{312,321,3012,3},{432,3211,0,2},{123,1323,132,1}};
    setZeroes(vv);
    return 0;
}