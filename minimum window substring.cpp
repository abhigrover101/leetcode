class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max=INT_MAX,i=0,cursor=0,start=0;
        string ans=S;
        int chk[256]={0},temp[256]={0},count=0;


        for(i=0;i<T.length();i++)
            chk[T[i]]++;



        while(cursor<=S.length()-1)
        {
            if(chk[S[cursor]]>0)
                temp[S[cursor]]++;
            if(temp[S[cursor]]<=chk[S[cursor]] && chk[S[cursor]] > 0)
                count++;

            if(count==T.length() && temp[S[cursor]]>=chk[S[cursor]])
            {
                for(i=start;i<cursor;i++)
                {
                    if(temp[S[i]]>chk[S[i]])
                        temp[S[i]]--;
                    else if(chk[S[i]]!=0)
                    {
                        break;
                    }
                }
                start=i;
            }


            if(count==T.length())
            {
                if(S.substr(start,cursor-start+1).length()<ans.length())
                    ans=S.substr(start,cursor-start+1);
            }

            cursor++;

        }
        if(count<T.length())
            ans="";
        return ans;

    }
};
