#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    void dfs(int node,int n,vector<int>& visited,vector<vector<int>>& isConnected){
        visited[node] = 1;
        
        for(int i=0;i<n;i++){
            if(!visited[i] && isConnected[node][i]==1){
                dfs(i,n,visited,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        vector<int>visited(n);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                provinces++;
                dfs(i,n,visited,isConnected);
            }
           
        }
        
        return provinces;

    }
};