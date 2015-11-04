class Solution {
public:
    int dp[1000][1000];

    int minDistance(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if(s1=="" && s2=="")
            return 0;
        if(s1=="")
            return s2.length();
        if(s2=="")
            return s1.length();

        int i,j;
        int same;

        for(i=0;i<=s1.length();i++)
            dp[i][0]=i;
        for(i=0;i<=s2.length();i++)
            dp[0][i]=i;

        for(i=1;i<=s1.length();i++)
            for(j=1;j<=s2.length();j++)
            {
                if(s1[i-1]==s2[j-1])
                    same=dp[i-1][j-1];
                else
                    same=dp[i-1][j-1]+1;
                dp[i][j]=min(same,min(dp[i][j-1]+1,dp[i-1][j]+1));

                //dp[i][j]=min(same,notsame);
            }

        return dp[s1.length()][s2.length()];

    }
};
