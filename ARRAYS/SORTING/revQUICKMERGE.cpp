//CODE
//QUICK  - PIVOT 
//WRITE ALL SORITNG ALGORITHMS AGAIN


//QUICk

#include <bits/stdc++.h>
using namespace std;

int positionPivot(vector <int> &v,int low,int high){
    swap(v[low],v[low+1]);
    int pivot = v[low];
    int i = low;
    int j = high;

    while(i<j){
        while(v[i]<=pivot && i<=high -1){
            i++;
        }
        while(v[j]>=pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(v[i],v[j]);
        }
    }
    swap(v[low],v[j]);
    return j;
}

void quicksort(vector<int> &v,int low,int high){
    if(low<high){
        int pp = positionPivot(v,low,high);
        quicksort(v,low,pp-1);
        quicksort(v,pp+1,high);
    }
}


int main(){
    vector <int>v={8,3,4,16,9,10};
    quicksort(v,0,v.size()-1);
    for(auto &it :v){
        cout<<it<<" ";
    }
    return 0;
}
