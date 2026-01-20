//CODE
//Pascal TRIANGLE
//         1
//       1   1
//     1   2   1
//   1   3   3    1
// 1   4   6   4     1
//


// (r-1) C (c-1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> vv;

            for(int i=0;i<numRows;i++){
                // vector<int>row;
                // for(int j=0;j<i+1;j++){
                //     row.push_back(colRow(i,j));
                // }
                // vv.push_back(row);
                vector<int>row;
                vv.push_back(printROW(i));

            }
            
            return vv;
        }

        // int colRow(int row,int col){
        //     //nCr
        //     int result=1;
        //     int k = min(col,(row-col));
        //     for(int i = 1;i<=k;i++){
        //         result = result*(row-k+i)/i;
        //     }
        //     return result;
        // }

        vector<int> printROW(int row){
            vector<int>vvv;
            // for(int i=0;i<=row;i++){
            //     vvv.push_back(colRow(row,i));
            // }

            int result=1;
            vvv.push_back(result);
            for(int i=1;i<=row;i++){
                result = result*(row-i+1)/i;
                vvv.push_back(result);
            }
            return vvv;
        }
};

int main(){
    int n;
    cout<<"Length of triangle : ";
    cin>>n;
    Solution ss;
    cout<<"Enter Row : ";
    int row=0;
    cin>>row;
    cout<<"Enter Col : ";
    int col=0;
    cin>>col;
    // int elem = ss.colRow(row-1,col-1); //DUE TO INDEXING
    // cout<<"Element at "<<row<<"R and "<<col<<"C is : "<<elem<<endl;
    // auto ll = ss.printROW(row-1);
    // for(auto it:ll){
    //     cout<<it<<" ";
    // }

    auto priint = ss.generate(n);

    cout<<endl;
    for(auto &rowVec : priint){
        for(auto val : rowVec){
            cout << val << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
