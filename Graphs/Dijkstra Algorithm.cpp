#include "bits/stdc++.h"
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adjList(V);
        
        for(int i=0;i<edges.size();i++){
             int u = edges[i][0];
             int v = edges[i][1];
             int wt = edges[i][2];
             
             adjList[u].push_back({v,wt});
             adjList[v].push_back({u,wt});
        }
        
        vector<int>dist(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[src] = 0;
        
        pq.push({0,src});
        
        while(!pq.empty()){
             int dis = pq.top().first;
             int node = pq.top().second;
             
             pq.pop();
             
             // Skip outdated entries
             if(dis > dist[node])
                continue;
             
             for(auto& it:adjList[node]){
                 int adjNode = it.first;
                 int edgeWeight = it.second;
                 
                 if(dis + edgeWeight < dist[adjNode]){
                       dist[adjNode] = dis + edgeWeight;
                       
                       pq.push({dist[adjNode],adjNode});
                 }
             }
        }
        
        return dist;
    }
};