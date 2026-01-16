//CODE 
#include <iostream>
#include <vector>
using namespace std;

//BRUTE --> Only Row change column is constant changes once
// void rotate(vector<vector<int>>& matrix) {
//     int row_col = matrix.size();
//     vector<vector<int>> vv(row_col, vector<int>(row_col, 0));
//     int i=0;
//     int j=0;
//     while(i<row_col){
//         while(j<row_col){
//             vv[j][row_col-1-i]=matrix[i][j];
//             j++;
//         }
//         i++;
//         j=0;
//     }
//     for(int i=0;i<row_col;i++){
//     for(int j=0;j<row_col;j++){
//         matrix[i][j]=vv[i][j];
//     }
// }

// }




//OPTIMAL --> NO space complexity
// MATRIX --> TRANSPOSE --> REVERSE EVERY ROW
//  [1,2,3]                                                [1,4,7]                 [7,4,1]
//  [4,5,6] -----> TRANSPOSE(column become row)   ---->    [2,5,8]     ---->       [8,5,2]
//  [7,8,9]                                                [3,6,9]                 [9,6,3]

void rotate(vector<vector<int>>& matrix) {
    int row_col = matrix.size();

    //TRANSPOSE
    //i+1 because loda lasan will understand when dry run
    for(int i=0;i<row_col;i++){
        for(int j=i+1;j<row_col;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    //REVERSE
    for(int i=0;i<row_col;i++){
        for(int j=0;j<row_col/2;j++){
            swap(matrix[i][j],matrix[i][row_col-1-j]);
        }
    }


}


int main(){
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    rotate(matrix);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}