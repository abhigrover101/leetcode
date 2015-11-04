class Solution {
public:

    bool interleaving(string &s1,string &s2,string &s3,int i,int j,int k)
    {
        if(k>=s3.length() && i==s1.length() && j==s2.length())
            return true;
        if(i>=s1.length() && j>=s2.length())
            return false;

        if(s1[i]!=s3[k] && s2[j]!=s3[k])
        {
            return false;
        }
        else if(s1[i]==s3[k] && s2[j]!=s3[k])
        {
            return interleaving(s1,s2,s3,i+1,j,k+1);
        }
        else if(s1[i]!=s3[k] && s2[j]==s3[k])
        {
            return interleaving(s1,s2,s3,i,j+1,k+1);
        }
        else if(s1[i]==s3[k] && s2[j]==s3[k])
        {
            return interleaving(s1,s2,s3,i+1,j,k+1) || interleaving(s1,s2,s3,i,j+1,k+1);
        }

    }


    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int dp[1000][1000]={{0,0}};
        dp[0][0]=1;
        int i,j;
        for(i=0;i<s3.length();i++)
        {
            for(j=0;j<=i;j++)
            {
                if(j<s1.length() && s1[j]==s3[i] && dp[j][i-j]==1)
                    dp[j+1][i-j]=1;
                if(j<s2.length() && s2[j]==s3[i] && dp[i-j][j]==1)
                    dp[i-j][j+1]=1;
            }
        }
        if(dp[s1.length()][s2.length()]==1 && (s1.length()+s2.length())==s3.length())
            return true;
        else false;
    }
};


/* // alternate sol
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i=0,j=0,k=0;
        bool dp[1000][1000]={{0,0}};
        dp[0][0]=1;
        int len1=s1.length();
        int len2=s2.length();
        if(len1+len2 != s3.length())
            return false;

        for(i=0;i<=len1;i++)
        {
            for(j=0;j<=len2;j++)
            {
                k=i+j-1;
                if(i>0 && s3[k]==s1[i-1] && dp[i-1][j]==1)
                    dp[i][j]=1;
                if(j>0 && s3[k]==s2[j-1] && dp[i][j-1]==1)
                    dp[i][j]=1;
            }
        }

        if(dp[len1][len2]==1)
            return true;
        else
            return false;

    }
};
*/
