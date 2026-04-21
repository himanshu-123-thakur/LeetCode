#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// You will implement this
vector<int> singleNumber(vector<int>& nums);

vector <int> singleNumber (vector<int> & nums){

    // vector<int> res;

    // unordered_map <int,int> unM;

    // for(auto it : nums){
    //     unM[it]++;
    // }

    // for(auto &p : unM){
    //     if(p.second == 1){
    //         res.push_back(p.first);
    //     }
    // }

    // return res;

    

}

int main() {
    vector<int> nums = {1, 2, 1, 3, 2, 5};

    vector<int> result = singleNumber(nums);

    cout << "Two unique numbers are: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}