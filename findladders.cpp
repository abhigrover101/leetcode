#include<string>
#include<vector>
#include<map>
#include<set>
#include<iostream>
using namespace std;

   bool isDistanceOne(string first,string second){
        int count=0;
        if(first.length()==second.length()){
            for(int i = 0 ;i < first.length(); i++)
                if(first[i]!=second[i])
                    count++;
        }
        if(count==1)
            return true;
        else
            return false;
    }

    void dfs(string start,string end,map < string,vector<string> > &adjacency, map <string,int> visited,vector< vector<string> > &ans,vector<string> path){
        for(int i=0;i<adjacency[start].size();i++){
            if(visited[adjacency[start][i]]==0){
                visited[adjacency[start][i]]=1;
                path.push_back(adjacency[start][i]);
                dfs(adjacency[start][i],end,adjacency,visited,ans,path);

                if(adjacency[start][i]==end){
                    ans.push_back(path);
                }
                path.pop_back();
            }
        }
    }

    vector< vector<string> > findLadders(string start, string end, set<string> &dict) {

        map<string,vector<string> > adjacency;
        map<string,int> visited;
        vector<vector<string> > ans;
        dict.insert(start);
        dict.insert(end);

        set<string>::iterator it1 = dict.begin();
        for(;it1!=dict.end();++it1){
            for(set<string>::iterator it2=dict.begin();it2!=dict.end();++it2){
                if(isDistanceOne(*it1,*it2)){
                    adjacency[*it1].push_back(*it2);
                }
            }
            visited[*it1]=0;
        }

        //cout<<adjacency["hot"][1];
        vector<string> path;
        path.push_back(start);
        visited[start]=1;
        dfs(start,end,adjacency,visited,ans,path);
        //cout<<path[0];
        return ans;
    }
int main(){
    string arr[]={"hot","dot","dog","lot","log"};
    set<string> abc(arr,arr+5);
    vector<vector<string> > a = findLadders("hit","cog",abc);
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;

}
