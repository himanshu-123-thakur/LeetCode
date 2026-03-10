#include <bits/stdc++.h>
using namespace std;
int longestSS(string s){

    //BRUTEE EE EE EE 
    //   int ans = 0;

    //     for (int i = 0; i < s.size(); i++) {
    //         unordered_set<char> st;

    //         for (int j = i; j < s.size(); j++) {
    //             if (st.find(s[j]) != st.end()) {
    //                 break;
    //             }

    //             st.insert(s[j]);
    //             ans = max(ans, j - i + 1);
    //         }
    //     }

    //     return ans;


    //OPTIMAL
    // we will use hasmap

    unordered_map<char,int> mp;
    int left = 0;
    int right = 0;
    int ans = 0;

    while(right < s.size()){

        if(mp.find(s[right]) != mp.end() && mp[s[right]] >= left){
            left = mp[s[right]] + 1;
        }

        mp[s[right]] = right;

        int length = right - left + 1;
        ans = max(ans, length);

        right++;
    }

    return ans;

}
int main(){
    string s = "sdf32e2rcewcfbrtbujn";
    cout<<"Longest substring No repetition is "<<longestSS(s)<<endl;
    return 0;
}