//CODE
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        //WE START AND ONCE we get first with all abc we count = 1+number of elemnt after the pattern
        //then we increment our left++ and again count same way and so on
        // int ans = 0;
        // for(int i =0;i<s.size();i++){
        //     vector<int> cc(3,0);
        //     for(int j = i ;j<s.size();j++){
        //         cc[s[j]-'a']++;
        //         if(cc[0]>0 && cc[1]>0 && cc[2]>0){
        //             ans +=s.size()-j;
        //             break;
        //         }
        //     }
        // }
        // return ans;

        //OPTIMAL LINEAR ---> MINE // APPROACH IS 
        // FIND first substring ans +=n-right , then in vector<s[i]>-- and move left ++ if all three you see again 
        //ans += and so on
        //  int n = s.size();
        // int left = 0;
        // int ans = 0;

        // vector<int> count(3,0);

        // for(int right = 0; right < n; right++) {

        //     count[s[right] - 'a']++;

        //     while(count[0] > 0 && count[1] > 0 && count[2] > 0) {

        //         ans += n - right;

        //         count[s[left] - 'a']--;
        //         left++;
        //     }
        // }

        // return ans;




        ///FAANG level --> Striver
        //LAST SEEN
        int ans =0;
        unordered_map<int,int> ss ;
                // initialize
        ss[0] = -1;
        ss[1] = -1;
        ss[2] = -1;
        for(int i=0;i<s.size();i++){
            ss[s[i]-'a']=i;//WHEN SEEN
            if(ss[0]>=0&&ss[1]>=0&&ss[2]>=0){
                ans+= min(ss[0],min(ss[1],ss[2]))+1;
            }
        }
        return ans;

        
    }
};

int main() {

    Solution obj;

    string s = "abcabc";

    int result = obj.numberOfSubstrings(s);

    cout << "Number of substrings containing a,b,c: " << result << endl;

    return 0;
}