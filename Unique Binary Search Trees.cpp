class Solution {
public:

    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int dp[1000]={0},i,j;
        dp[0]=1;
        for(i=1;i<=n;i++)
            for(j=1;j<=i;j++)
                dp[i]+=dp[j-1]*dp[i-j];
        return dp[n];
    }
};
