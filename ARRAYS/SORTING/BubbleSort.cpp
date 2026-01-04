//CODE - ADJACENT SWAPS
//for(int j=0;j<=i-1;j++) --------------------- i-1 is i then last element has nothing to compare too and will throw runtime error
//RUNTIME ERROR - accessing something thatt tis not present

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    cout << "RUNNING: BUBBLE-sort-v3\n";

    int arr[7]={12,34,653,1,2,45,80};

    // for(int i=6;i>0;i--){
    //     int maxI = i;
    //     for(int j=i-1;j>=0;j--){
    //         if(arr[j]>arr[maxI])
    //         maxI = j;
    //     }
    //     swap(arr[maxI],arr[i]);
    // }

    // for(int i =0;i<7;i++){
    //     cout<<arr[i]<<" "<<endl;
    // }
    // cout<<endl;


    for(int i =sizeof(arr)/sizeof(arr[0])-1;i>=0;i--){{
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }
    }

    }

    for(int i =0;i<7;i++){
         cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}