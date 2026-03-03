//code

#include <bits/stdc++.h>
using namespace std;

class Solution{
    minmaxGasDist(vector<int> &stations, int k){
        int d1=0;
        int d2=0;
        while(k!=0){
            int findLD =0;
            for(int i=1;i<stations.size();i++){
                    findLD = max(findLD,stations[i]-stations[i-1]);
                    if(findLD== stations[i]-stations[i-1]){
                        d1=i;
                        d2=i-1;
                    }
            }
            //NOW WE GOTTA PUSH one instance of k between d1 nad d2 and decrement k

        }
    }
};

int main() {

    int n;
    int k;
    cin >> n >> k;

    vector<int> stations(n);
    for (int i = 0; i < n; i++) {
        cin >> stations[i];
    }

    Solution obj;
    cout << fixed << setprecision(6)
         << obj.minmaxGasDist(stations, k);

    return 0;
}