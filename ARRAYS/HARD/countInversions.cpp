#include <iostream>
#include <vector>
using namespace std;
int count =0;

void sort(vector<int>&v , int left, int mid , int end){
    vector<int>temp;
    int right = mid+1;

    int start = left; 
    while(left<=mid && right<=end){
        if(v[left]<=v[right]){
            temp.push_back(v[left]);
            left++;
        }
        else{
            temp.push_back(v[right]);
            count+=(mid-left+1);
            right++;
        }
    }


        // Copy remaining elements from left half
        while (left <= mid) {
            temp.push_back(v[left]);
            left++;
        }
        
        // Copy remaining elements from right half
        while (right <=  end) {
            temp.push_back(v[right]);
            right++;
        }

    // copy back to v[start..end]
    for (int i = 0; i < (int)temp.size(); i++) {
        v[start + i] = temp[i];
    }
}

void countInversionsMERGE(vector<int> &v,int start,int end){

    int mid = (start+end)/2;

    if(start>=end){
        return;
    }
    
        countInversionsMERGE(v,start,mid);
        countInversionsMERGE(v,mid+1,end);

        //MERGE
        sort(v,start,mid,end);

}

int inversions(vector<int> &v){
    countInversionsMERGE(v,0,v.size()-1);
    return count;
}

int main(){
    vector<int> vv ={5,3,4,2,1};

    // //NAIVE
    // int count = 0;
    // for(int i=0;i<vv.size();i++){
    //     for(int j=i+1;j<vv.size();j++){
    //         if(vv[j]<vv[i]){
    //             count++;
    //         }
    //         else{
    //             continue;
    //         }
    //     }
    // }


    //OPTIMAL 
    int result = inversions(vv);
    cout<<"Total Inversions are = "<<result<<endl;
}