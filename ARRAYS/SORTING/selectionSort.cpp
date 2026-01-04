//CODE 
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// int main(){
//     vector <int> v {21,3124,43,245,25,245,42,5,345,34,55};
//     sort(v.begin(),v.end() ,greater<int>());
//     for(auto &i:v){
//         cout<<i<<" ";
//     }
//     return 0;
// }

class selectionSort{
    private:
    public:
    void sort(int arr[], int size){
        int min=arr[0];
        int temp;
        for(int i =0;i<size;i++){
            int min = i;
            for(int j = i+1;j<size;j++){
                if(arr[j]<arr[min])
                min = j;
        }
        swap(arr[i],arr[min]);
    }
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
};
int main(){
    int size ;
    cin>>size;
    int arr[size];
    cout<<"Enter Array of size "<<size<<" : ";
    for(int i =0; i <size;i++){
        cin>>arr[i];
    }

    selectionSort s;
    s.sort(arr,size);
    return 0;
}
