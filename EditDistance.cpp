class Solution {
public:
int mini(string a , string b , int m , int n){

  int dp[m+1][n+1];
  for(int i=0;i<=m;i++){
      dp[i][0]=i;
  }
  for(int j=0;j<=n;j++){
      dp[0][j]=j;
  }
  
  for(int i=1;i<=m;i++){
      for(int j=1;j<=n;j++){
          if(a[i-1]==b[j-1])
          dp[i][j]=dp[i-1][j-1];

          else
          dp[i][j]=1+min(dp[i-1][j],
                         min(dp[i][j-1],
                             dp[i-1][j-1]));
      }
  }
  return dp[m][n];
}
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        return mini(word1,word2,n,m);
    }
};
