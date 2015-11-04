class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int dp[100000]={0},prev[100000]={0};

        int i,j;
        for(j=0;j<=S.length();j++)
            prev[j]=1;

        for(i=1;i<=T.length();i++)
        {
            for(j=1;j<=S.length();j++)
            {
                if(S[j-1]==T[i-1])
                {
                    dp[j]=prev[j-1]+dp[j-1];
                }
                else
                    dp[j]=dp[j-1];

            }
            for(j=0;j<=S.length();j++)
                prev[j]=dp[j];;
        }

        return prev[S.length()];

    }
};
