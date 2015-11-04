#include<iostream>
#include<string>
#include<vector>
using namespace std;

    bool isPalindrome(string s,int i,int j){
        while(i<j && s[i]==s[j]){
            i++;
            j--;
            continue;
        }
        if(i>=j)
            return true;
        return false;
    }

    void palindromes(string s,int start,vector<string> &ans,vector<vector<string> > &all){
        if(start >= s.length()){
            all.push_back(ans);
            //ans.clear();
            return;
        }

        int i = start;
        for(i=start;i<s.length();i++){
            if(isPalindrome(s,start,i)){
                ans.push_back(s.substr(start,i-start+1));
                palindromes(s,i+1,ans,all);
                ans.pop_back();
            }
        }
        return;
    }

    vector<vector<string> > allpalindromes(string s){
        vector<string> ans;
        vector<vector<string> > all;
        palindromes(s,0,ans,all);
        return all;
    }

int main(){
    string s;
    cin>>s;
    vector<vector<string> > ans;
    ans = allpalindromes(s);
    int i=0,j;
    for(i=0;i<ans.size();i++){
        for(j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
