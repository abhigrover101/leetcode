class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size()==0)
            return true;
        int i=0;
        int j=s.size()-1;

        while(i<j)
        {
            while((!(s[i]>='A' && s[i]<='Z') && !(s[i]>='a' && s[i]<='z') && !(s[i]>='0' && s[i]<='9')) && i<j)
                i++;
            while((!(s[j]>='A' && s[j]<='Z') && !(s[j]>='a' && s[j]<='z') && !(s[j]>='0' && s[j]<='9')) && i<j)
                j--;
            //if(i>=j)
            //    break;
            if(s[i]==s[j] || (s[i]-('a'-'A'))==s[j] || s[i]==(s[j]-('a'-'A')))
            {
                i++;
                j--;
            }
            else
                break;
        }
        if(i<j)
            return false;
        return true;
    }
};
