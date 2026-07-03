#include "bits/stdc++.h"
using namespace std;

class Solution {
  public:
    void dfs(int node,vector<int>& visited,vector<int>& answer,vector<vector<int>>& adj){
        visited[node] = 1;
        answer.push_back(node);
        
        for(int i=0;i<adj[node].size();i++){
            
            int u = adj[node][i];
            
            if(!visited[u]){
                dfs(u,visited,answer,adj);
            }   
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int>visited(n);
        vector<int>answer;
        
        
        dfs(0,visited,answer,adj);
        
        return answer;
        
    }
};