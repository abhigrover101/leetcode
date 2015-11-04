class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector <int> ans;
        int size=1<<n;
        for(int i=0;i<size;i++)
        {
            ans.push_back((i>>1) ^ i);
        }
        return ans;

    }
};
