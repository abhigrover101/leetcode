class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.length()==0)
            return 0;
        int dp[10000]={0};

        if(s[0]=='0')
            return 0;
        else
            dp[0]=1;

        if(atoi(s.substr(0,2).c_str())<=26 && s[1]!='0')
            dp[1]=2;
        else if(atoi(s.substr(0,2).c_str())<=26)
            dp[1]=1;
        else if(s[1]!='0')
            dp[1]=1;
        else return 0;

        for(int i=2;i<s.length();i++)
        {
            if(atoi(s.substr(i-1,2).c_str())<=26 && s[i-1]!='0')
                dp[i]+=dp[i-2];
            if(s[i]!='0')
                dp[i]+=dp[i-1];
            if(dp[i]==0)
                return 0;
        }
        return dp[s.length()-1];

    }
};
