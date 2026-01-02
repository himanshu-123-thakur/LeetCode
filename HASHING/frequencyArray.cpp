//CODE
//MAPS ARE NOT index based
//auto it : map_name
// it.first and it.second

#include <iostream>
#include <map>
using namespace std;
class hash_map{
    public:
    void output(int arr[], int size){
        map<int,int> mpp;
        for(int i=0;i<size;i++){
            mpp[arr[i]]++;
        }

        for (auto &p : mpp){
        cout << "[" << p.first << "," << p.second << "]\n";
        }
    }
};
int main(){
    int size;
    cin>>size;
    int arr[size];
    //for (int i = 0; i < size; i++) cin >> arr[i];
    for(auto &it:arr){
        cin>>it;
    }
    
    hash_map hh;
    hh.output(arr,size);
    return 0;
}