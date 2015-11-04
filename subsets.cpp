#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

    vector<vector<int> > subsets(vector<int> &S) {

        int num = 1<<(S.size());

        int i = 0;
        sort(S.begin(),S.end());
        int c,j;
        vector<int> subset;
        vector<vector<int> > ans;
        for(i=0;i<num;i++){
            j = i;
            c=0;
            subset.clear();
            while(j>0){
                if((j & 1))
                    subset.push_back(S[c]);
                c++;
                j=j>>1;
            }
            ans.push_back(subset);

        }
        return ans;
    }

int main(){
    vector<int> S;
    S.push_back(0);
    subsets(S);
    return 0;
}
