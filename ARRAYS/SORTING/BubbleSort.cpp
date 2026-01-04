#include <iostream>
using namespace std;
int main(){
    int arr[7]={12,34,653,1,2,45,80};

    for(int i =6;i>=0;i++){
        int max = i;
        for(int j=i-1;j>=0;j--){
            if(arr[j]>arr[max])
            max = j;
        }
        swap(arr[max],arr[i]);
    }

    for(int i =0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}