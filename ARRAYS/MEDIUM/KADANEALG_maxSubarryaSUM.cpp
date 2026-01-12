//Code
//BRUTE ---> O(n cube)
//BETTER ---> O(n square)
//OPTIMAL --> Kadane Algorithm



#include <iostream>
#include <climits>
using namespace std;

// int brutesubarray(int arr[],int size){
//     int maxi =INT8_MIN;
//     for(int i=0;i<size;i++){
//         for(int j =i;j<size;j++){
//             int sum = 0;
//             for(int k =i;k<=j;k++){
//                 sum+=arr[k];
//                 maxi = max(sum,maxi);
//             }
//         }
//     }

//     return maxi;
// }



// int bettersubarray(int arr[],int size){
//     int maxi =INT_MIN;
//     for(int i=0;i<size;i++){
//         int sum =arr[i];
//         for(int j =i+1;j<size;j++){
//             sum+=arr[j];
//             maxi=max(sum,maxi);
//         }
//     }

//     return maxi;
// }


int KADANEsubarray(int arr[],int size){

    int sum=0;
    int maxi=INT_MIN;
    for(int i=0;i<size;i++){

        //TO KEEP TRACK OF SUNARRAY
        //int start,ansSTART,ansEND;
        // if (sum==0) start =i;
        

        sum+=arr[i];
        if(sum<0){
            sum=0;
        }
        else{
            //ansSTART = start, ansEND =i;
            maxi = max(sum,maxi);
        }
    }
    return maxi;



    //ALL NEGATIVE CODE 
    // int maxi =nums[0];
    // int sum=0;
    // int i=0;
    // while(i<nums.size()){
    //     sum+=nums[i];
    //     maxi = max(sum,maxi); /// THIS SOLVES FOR all -ve because maximum negative number is always a individual number

    //     if(sum<0){
    //         sum=0;
    //     }
    //     i++;
    // }
    // return maxi;
}

int main(){
    int arr[]={-2,-3,4,-1,-2,1,5,-3};
    int size = sizeof(arr)/sizeof(arr[0]);
    // cout<<"MAX SUM IS "<<brutesubarray(arr,size);
    // cout<<"MAX SUM IS "<<bettersubarray(arr,size);
    cout<<"MAX SUM IS "<<KADANEsubarray(arr,size);
    return 0;
}

//PRINT POSITION
// int possubarray(int arr[],inst size){
//     int sum=0;
//     int start=0;
//     int ANSend=0;
//     int ANSstart=0;
//     int maxi = INT_MIN;
//     for(int i =0;i<size;i++){
//         sum+=arr[i];
//         if (sum<0){
//             sum=0;
//             start=i;
//         }
//         else{
//             maxi = max(maxi,sum);
//            ANSstart = start, ANDend =i;
//         }
//     }
// }