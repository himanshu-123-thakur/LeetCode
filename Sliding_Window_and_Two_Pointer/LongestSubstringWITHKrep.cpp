//CODE
// frequency map to track count of each character in current window
// unordered_map <int,int> mpp;

// int maxFreq = 0;   // stores the highest frequency of any character in current substring
// int changes = 0;   // number of replacements needed to make substring same character
// int ans = 0;       // stores maximum valid substring length found

// // BRUTE FORCE: check every possible substring
// for(int i = 0; i < s.size(); i++){

//     // reset frequency map for new starting index i
//     for(int i = 0; i <= 25; i++){
//         mpp[i] = 0;
//     }

//     // expand substring from starting index i
//     for(int j = i; j < s.size(); j++){

//         // increase count of current character
//         mpp[s[j] - 'A']++;

//         // update the maximum occurring character frequency
//         maxFreq = max(maxFreq, mpp[s[j] - 'A']);

//         // number of characters we must replace to make substring uniform
//         changes = (j - i) + 1 - maxFreq;

//         // if replacements needed are within allowed limit k
//         if(changes <= k){

//             // update maximum valid substring length
//             ans = max(ans, j - i + 1);
//         }
//         else{

//             // if replacements exceed k, no need to expand further
//             break;
//         }
//     }
// }

// return ans;



// VERY BRUTE COMPUTE ALL THE Substrings and in each substring check the highest freq element and and the changes that we can make 
// if changes > k that means it is shit, therefore we come out else we update our ans