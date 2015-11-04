#include<string>
#include<vector>
#include<map>
#include<set>
#include<iostream>
using namespace std;

    int numDecodings(string s) {
        if(s.length()==0 || stoi(s)<0)
            return 0;
        int dp[s.length()];
        dp[0]=1;
        if(s.length()>1 && stoi(s.substr(0,2))<=26)
            dp[1]=1;

        for(int i=2;i<s.length();i++){
            dp[i]=dp[i-1];
            if(stoi(s.substr(i-1,2))<=26)
                dp[i]+=dp[i-2];
        }
        return dp[s.length()-1];
    }

int main(){
    cout<<numDecodings("6065812287883668764831544958683283296479682877898293612168136334983851946827579555449329483852397155");
    return 0;
}
