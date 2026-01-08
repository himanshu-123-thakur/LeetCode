//code
//LEFT rotate by D.
//BRUTE - create array of size d store first d element in array,shift remaining and append the remaining at end of existing array
//BETTER


#include <iostream>
using namespace std;


void leftrotatebyD_BRUTE_FORCE(int arr[],int size, int D){
    int arr_temp[D];
    for(int i=0;i<D;i++){
        arr_temp[i]=arr[i];
    }

    for(int i=0;i<size-D;i++){
        arr[i]=arr[i+D];
        cout<<arr[i]<<" ";
    }
    int j =0;
    for(int i = (size-D);i<size;i++){
        //arr[i]=arr_temp[j];
        arr[i]=arr_temp[i-(size-D)];
        j++;
    }

cout<<endl;
cout<<"Left shifted by : "<<D<<" array is : ";
for(int i =0;i<size;i++){
    cout<<arr[i]<<" ";
}
}

int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int leftRotateby ;
    cout<<"Left rotate by : ";
    cin >>leftRotateby;
    leftrotatebyD_BRUTE_FORCE(arr,10,leftRotateby);
    return 0;
}