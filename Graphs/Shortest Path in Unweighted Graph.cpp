#include "bits/stdc++.h"
using namespace std;

class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        
        int N = edges.size();
        
        vector<int>dist(V,INT_MAX);
        
        vector<vector<int>>adjList(V);
        
        queue<int>q;
        
        for(int i=0;i<N;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        
        dist[src] = 0;
        
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto& it:adjList[node]){
                if(dist[it] == INT_MAX){
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
                
                
            }
            
        }
        
        
         return (dist[dest] == INT_MAX) ? -1 : dist[dest];
        
        
        
    }
};
