//CODE 
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void high_freq(vector<int>&v , int n){
    unordered_map<int,int>mpp;
    int result=0;
    int ans;
    for(int i = 0;i<v.size();i++){
        mpp[v[i]]++;
        if(mpp[v[i]]>result){
            result = mpp[v[i]];
            ans = v[i];
        }
        else if(mpp[v[i]]==result) {
            if(v[i]<ans)
            ans = v[i];
        }
        else{
            continue;
        }

    }

    cout << "Highest occurring element is " << ans
     << " repeated " << result << " times\n";

}
int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    high_freq(v,v.size());
    return 0;
}