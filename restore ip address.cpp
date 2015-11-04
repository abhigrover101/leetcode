class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string s1,s2,s3,s4;
        int i1,i2,i3,i4;
        set <string> ans;
        vector<string> a;
        int i,j,k,size=s.length();
        stringstream ss;
        for(i=0;i<3;i++)
        {
            for(j=i+1;j<i+4;j++)
            {
                for(k=j+1;k<j+4;k++)
                {
                    if(i<size && j<size && k+1<size)
                    {

                        i1=atoi((s.substr(0,i+1)).c_str());
                        i2=atoi((s.substr(i+1,j-i)).c_str());
                        i3=atoi((s.substr(j+1,k-j)).c_str());
                        i4=atoi((s.substr(k+1,size-k-1)).c_str());

                        ss.clear();
                        ss.str("");
                        ss << i1 << "." << i2 << "." << i3 << "." << i4;
                        ss >> s1;
                        if(i1>=0 && i1<=255 && i2>=0 && i2<=255 && i3>=0 && i3<=255 && i4>=0 && i4<=255 && ans.find(s1)==ans.end() && (s1.length()-3)==(s.length()))
                        {
                            ans.insert(s1);
                            a.push_back(s1);
                        }
                    }


                }

            }
        }
        return a;

    }
};
