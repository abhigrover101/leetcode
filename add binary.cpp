class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string ans="",temp="";
        int it=0,carry=0;
        while(it<a.size() || it < b.size())
        {
            if(it<a.size() && it < b.size() )
            {
                temp=((a[it]-'0'+b[it]-'0') + carry)%2 + '0';
                carry=((a[it]-'0'+b[it]-'0') + carry)/2;
                ans=ans+ temp;
            }
            else if(it<a.size() && it >= b.size() )
            {
                temp=((a[it]-'0') + carry)%2 + '0';
                carry=((a[it]-'0') + carry)/2;
                ans=ans+ temp;
            }
            else if(it<b.size() && it >= a.size() )
            {
                temp=((b[it]-'0') + carry)%2 + '0';
                carry=((b[it]-'0') + carry)/2;
                ans=ans+ temp;
            }
            it++;
        }
        if(carry!=0)
            ans=ans+'1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
