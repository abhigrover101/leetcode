#include<iostream>
#include<string>
#include<stdlib.h>
#include<string.h>
using namespace std;
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        int chmap[256];
        memset(chmap,-1,sizeof(chmap));
        int start=0;
        int i;
        int length=1;
        chmap[s[0]]=0;
        for(i=1;i<s.size();i++){
            if(chmap[s[i]]==-1){
                chmap[s[i]]=i;
                if(i-start+1 > length){
                    length=i-start+1;
                    cout<<length<<s[i]<<endl;
                }
            }
            else{
                if(chmap[s[i]]>=start){
                    start= chmap[s[i]]+1;
                }
                if(i-start+1 > length)
                        length=i-start+1;
                chmap[s[i]]=i;
                cout<<length<<start<<endl;
            }
        }
        return length;
    }

    int main(){
        cout<<lengthOfLongestSubstring("hchzvfrkmlnozjk");
        return 0;
    }
