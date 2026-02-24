//SQRT using BS (logN)

#include <bits/stdc++.h>
using namespace std;

void sqrt(int n,int a){
    //WILLL WRITE LATER 
    int low = 1;
    int high = n;
    int ans=0;
    while(low<=high){
        int mid = (low+high)/2;
        if(pow(mid,a) > n){
            high = mid-1;
        }
        else if(pow(mid,a)<n){
            ans = low;
            low = mid+1;
        }
        else{
            ans =  mid;
            break;
        }
    }
    cout<<"nTH is = "<<ans<<endl;
    

}
int main (){
    int n;
    int aa=0;
    cout<<"Enter the no : ";
    cin>>n;
    cout<<"Nt root you want so write the value of n : ";
    
    cin>>aa;
    // cout<<"Sqrt of "<<n<<" is "<<sqrt(n)<<endl;
    sqrt(n,aa);
    return 0;
}