//code
//UNTION say two sorted arrays 
// arr1[]={1,2,2,3,3,3,4,5,5,6} arr2[]={1,2,3,4,4,7}
// UNION WILLE BE ARR[]={1,2,3,4,4,6,7}
//INTERSECTION WILL BE RES[] ={1,2,3,4}


#include <iostream>
#include <set>
#include <vector>
using namespace std;


//BRUTE ---> O(n1+n2)-->SC
//      ---> O(2nlogn) -->TC

// void union_arr(int arr1[], int arr2[], int size1, int size2) {
//     set<int> uni;

//     for (int i = 0; i < size1; i++) uni.insert(arr1[i]); //O(nlogn)
//     for (int i = 0; i < size2; i++) uni.insert(arr2[i]);//O(nlogn)

//     for (int x : uni) cout << x << " ";
// }





//OPTIMAL --> 2 Pointers
//Comparing  both arrya element then comapring woth the last elemtn pushed in the vector if not same push
// o(n1+n2) 
//BEAUTIFUL

// void union_arr(int arr1[], int arr2[], int size1, int size2){
//     vector<int>v;
//     int i=0;
//     int j= 0;

//     while(i<size1 && j<size2){
//         if (arr1[i]<=arr2[j]){
//         if (v.size()==0 || v.back()!=arr1[i]){
//             v.push_back(arr1[i]);
//             }
//             i++;
//         }
    
//         else{
//             if(v.size()==0 || v.back()!=arr2[j]){
//                     v.push_back(arr2[j]);
//                 }
//                 j++;
//             }
//         }

//         while(j<size2){
//             if(v.size()==0 || v.back()!=arr2[j]){
//                 v.push_back(arr2[j]);
//             }
//             j++;
//         }

//         while(i<size1){
//             if(v.size()==0 || v.back()!=arr1[i]){
//                 v.push_back(arr1[i]);
//             }
//             i++;
//         }


//         for(auto &it:v){
//             cout<<it<<" ";
//         }

// }

//BRUTE ---> O(n1*n2)
//      ---> O(n2) //SPACE

// void inter_arr(int arr1[],int arr2[], int n1,int n2){
//     vector <int>v;
//     int arr[n2]={0};

//     int i=0;
//     while(i<n1){
//         for(int j =0;j<n2;j++){
//             if(arr1[i]==arr2[j] && arr[j]==0){
//                 v.push_back(arr1[i]);
//                 arr[j]=1;
//                 i++;
//                 break;
//             }
//             if(arr1[i]<arr2[j]){
//                 i++;
//                 break;
//             }
//         }
//     }

//     for(auto &it:v){
//         cout<<it<<" ";
//     }
// }

void inter_arr_optimal(int arr1[],int arr2[], int n1,int n2){
    int i=0;int j=0;
    vector<int>v;
    while(i<n1 && j<n2){
        if(arr1[i]==arr2[j]){
            v.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i]<arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }

        for(auto &it:v){
        cout<<it<<" ";
    }
}

int main(){
    int arr1[10]={1,2,2,3,3,3,4,5,5,6};
    int arr2[6]={1,2,3,4,4,7};

    //union_arr(arr1,arr2,10,6);
    // inter_arr(arr1,arr2,10,6);

    inter_arr_optimal(arr1,arr2,10,6);
    return 0;
}