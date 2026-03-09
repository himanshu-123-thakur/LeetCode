//code

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    long double minmaxGasDist(vector<int> &stations, int k){
        
        int size = stations.size();


        /*
         *  how_many[i] = number of NEW stations inserted
         *                inside gap i (between stations[i]
         *                and stations[i+1])
         *
         *  Initialized to 0 — no new stations placed yet.
         *
         *  EXAMPLE:
         *    gaps      = [12,  4,  6]   (distances)
         *    how_many  = [ 0,  0,  0]   (initially)
         *    After k=5:
         *    how_many  = [ 3,  1,  1]
         *                  ↑   ↑   ↑
         *                Gap0 Gap1 Gap2
         */

        vector<int> how_many(size-1,0);

        /*
         * --------------------------------------------------------
         *  PHASE 1: Greedily place k stations one by one
         * --------------------------------------------------------
         *  Each iteration places ONE station into the gap
         *  that currently has the LARGEST section length.
         *
         *  Section length of gap i = (gap distance) / (how_many[i] + 1)
         *  → "+1" because 'p' stations divide a gap into (p+1) sections
         *
         *  EXAMPLE TRACE:
         *
         *   Iter 1: sections=[12.0, 4.0, 6.0] → max=12.0 at i=0
         *           how_many = [1, 0, 0]
         *
         *   Iter 2: sections=[6.0, 4.0, 6.0]  → max=6.0  at i=0 (tie→first)
         *           how_many = [2, 0, 0]
         *
         *   Iter 3: sections=[4.0, 4.0, 6.0]  → max=6.0  at i=2
         *           how_many = [2, 0, 1]
         *
         *   Iter 4: sections=[4.0, 4.0, 3.0]  → max=4.0  at i=0 (tie→first)
         *           how_many = [3, 0, 1]
         *
         *   Iter 5: sections=[3.0, 4.0, 3.0]  → max=4.0  at i=1
         *           how_many = [3, 1, 1]
         * --------------------------------------------------------
         */

        for(int gasStation = 1 ;gasStation<=k;gasStation++){
        long double maxSection = -1;
        int maxInd = -1;
        for(int i=0;i<size-1;i++){
            long double diff = stations[i+1]-stations[i];
                /*
                 *  If how_many[i] stations are already placed in gap i,
                 *  it is divided into (how_many[i] + 1) equal sections.
                 *
                 *  EXAMPLE (gap 0, diff=12):
                 *    how_many[0]=0 → 12/1 = 12.0
                 *    how_many[0]=1 → 12/2 =  6.0
                 *    how_many[0]=2 → 12/3 =  4.0
                 *    how_many[0]=3 → 12/4 =  3.0  ✅ final
                 */
            long double sectionLength = diff/(long double)(how_many[i]+1);



                /*
                 *  Strictly greater (>) means ties go to the
                 *  FIRST gap found — consistent greedy behavior.
                 *
                 *  EXAMPLE: At Iter 2, gaps 0 and 2 both = 6.0
                 *           → gap 0 wins because it's seen first
                 */

            if(sectionLength > maxSection){
                maxSection=sectionLength;
                maxInd=i;
            }
        }
        how_many[maxInd]++;
        }


         /*
         * --------------------------------------------------------
         *  PHASE 2: Compute the final maximum section length
         * --------------------------------------------------------
         *  After all k stations are placed, scan all gaps one
         *  more time to find the worst-case (maximum) section.
         *
         *  EXAMPLE (final how_many = [3, 1, 1]):
         *
         *    Gap 0: diff=12, how_many=3 → 12/4 = 3.0
         *    Gap 1: diff= 4, how_many=1 →  4/2 = 2.0
         *    Gap 2: diff= 6, how_many=1 →  6/2 = 3.0
         *
         *    maxAns = 3.0
         *
         *  Visual layout after placement:
         *    [1]--3--[4]--3--[7]--3--[10]--3--[13]-2-[15]-2-[17]--3--[20]--3--[23]
         *     |<-------- gap0 (3 added) ------->|  gap1  |  |<-- gap2 (1 added) -->|
         * --------------------------------------------------------
         */

        long double maxAns=-1;
        for(int i = 0;i<size-1;i++){
            long double diff = stations[i+1]-stations[i];
            long double sectionLength = diff/(long double)(how_many[i]+1);
            maxAns=max(maxAns,sectionLength);
        }

        return maxAns;


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