#include "bits/stdc++.h"
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>distance(V,1e8);
        
        distance[src] = 0;
        
        for(int i=0;i<V-1;i++){
            for(auto& edge:edges){
                 int u = edge[0];
                 int v = edge[1];
                 int wt = edge[2];
                 
                 
                 if(distance[u]!=1e8 && distance[u]+wt < distance[v]){
                       distance[v] = distance[u]+wt;
                 }
            }
        }
        
        for(auto it:edges){
                 int u=it[0];
                 int v= it[1];
                 int wt = it[2];
                 
                 if(distance[u]!=1e8 && distance[u]+wt < distance[v]){
                      return {-1};
                 }
        }
        
        return distance;
    }
};
