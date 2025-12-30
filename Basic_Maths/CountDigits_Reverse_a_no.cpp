//Code 
#include <bits/stdc++.h>
using namespace std;

class basic_math_1{
    public:
    void fun1(int a){
        string s = to_string(a);
        for(int i=0;i<s.size()/2;i++){
            swap(s[i],s[s.size()-i-1]);
        }

        cout <<s<<endl;
    }

    void fun2(int a){
        int i=0;
        int n=a;
        while(a>0){
            a = a/10;
            i++;
            
        }
        cout<< i<<endl;

    }
};

int main(){
    // int arr[5];
    // cout<<"Enter the array elements : ";

    // for (auto &i : arr) {
    //     cin >> i; // it is element not the index
    // }

    
    // for(auto i: arr){
    //     cin>>i; //it is element not the index
    // }


    int a =0;
    cin >>a;

    basic_math_1 reversedigit, countdigit;
    reversedigit.fun1(a);
    countdigit.fun2(a);

    return 0;
}