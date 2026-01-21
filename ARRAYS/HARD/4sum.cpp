//BRUTE FORCE ---> O(n^4)
//4 loops

//BETTER solution ---> O(n^3)
//3 loops 
//i,j,k everything between j and k in hashset and if exists store result in vec or move 


//OPTIMAL APPROACH
//i,j = 0,1
//k = j+1 and l = size -1
//k and l 2 pointers

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
    int size = nums.size();
    int i = 0;
     set<vector<int>>st;
    sort(nums.begin(), nums.end());
    while(i<size-3){
        if(i>0 && nums[i]==nums[i-1]){i++;continue;}
        int j=i+1;
        while(j<size-2){
            if(j!=i+1 && nums[j]==nums[j-1]){j++;continue;}
            int k =j+1;
            int l=size-1;

            while(k<l){
                long long sum = 1LL *nums[i]+nums[j]+nums[k]+nums[l];
                if(sum<target){
                    k++;
                    while(k<l && nums[k]==nums[k-1]){k++;}
                }
                else if(sum>target){
                    l--;
                    while(k<l && nums[l]==nums[l+1]){l--;}
                }
                else{
                    
                    st.insert({nums[i],nums[j],nums[k],nums[l]});
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1]){k++;}
                    while(k<l && nums[l]==nums[l+1]){l--;}

                }
            }
            j++;
        }
        i++;

        

    }

    vector<vector<int>> vv (st.begin(),st.end());

    return vv;
}
