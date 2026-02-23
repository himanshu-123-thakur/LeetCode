//SQRT using BS (logN)

#include <bits/stdc++.h>
using namespace std;

void sqrt(int n){
    //WILLL WRITE LATER 
    int low = 1;
    int high = n;
    int ans=0;
    while(low<=high){
        int mid = (low+high)/2;
        if(mid*mid > n){
            high = mid-1;
        }
        else if(mid*mid<n){
            ans = low;
            low = mid+1;
        }
        else{
            ans =  mid;
            break;
        }
    }
    cout<<"sqrt is = "<<ans<<endl;
    

}
int main (){
    int n;
    cout<<"Enter the no : ";
    cin>>n;
    // cout<<"Sqrt of "<<n<<" is "<<sqrt(n)<<endl;
    sqrt(n);
    return 0;
}