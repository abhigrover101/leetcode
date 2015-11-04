class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int cursor=0;
        string temp;
        list <string> st;

        while(cursor<path.length())
        {
            if(st.empty()==true && path[cursor]=='/')
                st.push_back("/");
            //else if(path[cursor]=='/' && st.back()=="/")
            //{
            //    cursor++;
            //    continue;
            //}
            else if(path[cursor]=='/')
            {
                if(temp==".")
                {
                    cursor++;
                    temp="";
                    continue;
                }
                else
                {
                    if(temp!="")
                        st.push_back(temp);
                    if(st.back()!="/")
                        st.push_back("/");
                    temp="";
                }
            }
            else if(path[cursor]=='.')
            {
                if(temp=="." && st.empty()==false)
                {
                    st.pop_back();
                    if(!st.empty())
                    st.pop_back();
                    temp="";
                }
                else
                    temp=temp+path[cursor];
            }
            else
                temp=temp+path[cursor];
            cursor++;
        }

        if(temp!="" && temp!=".")
        {
            st.push_back(temp);
            temp="";
        }
        temp="";
        if(st.back()=="/")
            st.pop_back();
        while(!st.empty())
        {
            temp=temp+st.front();
            st.pop_front();
        }
        if(temp=="")
            return "/";
        return temp;

    }
};
