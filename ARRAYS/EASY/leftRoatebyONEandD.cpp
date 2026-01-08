//code
//LEFT rotate by D.
//BRUTE - create array of size d store first d element in array,shift remaining and append the remaining at end of existing array ---> O(size+D) --->O(n) SC

//BETTER -NONE

//OPTIMAL - SOO we first reverse the first D elemtns of array and then reverse the n-d elements of array, now  at the end whatever our array is we revere it again to get the resultant
// SC--->o(1)


#include <iostream>
using namespace std;


// void leftrotatebyD_BRUTE_FORCE(int arr[],int size, int D){
//     int arr_temp[D];
//     for(int i=0;i<D;i++){
//         arr_temp[i]=arr[i];
//     }

//     for(int i=0;i<size-D;i++){
//         arr[i]=arr[i+D];
//         cout<<arr[i]<<" ";
//     }
//     int j =0;
//     for(int i = (size-D);i<size;i++){
//         //arr[i]=arr_temp[j];
//         arr[i]=arr_temp[i-(size-D)];
//         j++;
//     }

// cout<<endl;
// cout<<"Left shifted by : "<<D<<" array is : ";
// for(int i =0;i<size;i++){
//     cout<<arr[i]<<" ";
// }
// }




void leftrotatebyD_OPTIMAL(int arr[],int size,int D){
    for(int i =0;i<D/2;i++){
        swap(arr[i],arr[(D-1)-i]);
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int j=1;
    for(int i = D;i<=size/2;i++){
        swap(arr[i],arr[size-j]);
        j++;
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i =0;i<size/2;i++){
        swap(arr[i],arr[(size-1)-i]);
    }
    cout<<endl;

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[7]={1,2,3,4,5,6,7};
    int leftRotateby ;
    cout<<"Left rotate by : ";
    cin >>leftRotateby;
  //leftrotatebyD_BRUTE_FORCE(arr,10,leftRotateby);
    leftrotatebyD_OPTIMAL(arr,7,leftRotateby);
    return 0;
}