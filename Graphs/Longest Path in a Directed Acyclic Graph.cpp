#include "bits/stdc++.h"
using namespace std;

class Solution {
//   private:
//     void topoSort(int node, vector<int>& visited,
//                   stack<int>& st,
//                   vector<vector<pair<int,int>>>& adjList){
//          visited[node] = 1;
         
      
//         for (auto &it : adjList[node]) {
//             int adjNode = it.first;

//             if (!visited[adjNode]) {
//                 topoSort(adjNode, visited, st, adjList);
//             }
//         }

//         st.push(node);
//     }
//   public:
//     vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
//         // code here
//         vector<int>visited(V,0);
//         vector<vector<pair<int,int>>>adjList(V);
//         stack<int>st;
        
        
//         for(auto& edge:edges){
//             int u =  edge[0];
//             int v =  edge[1];
//             int wt = edge[2];
            
//             adjList[u].push_back({v,wt});
//         }
        
//         for(int i=0;i<V;i++){
//              if(!visited[i]){
//                  topoSort(i,visited,st,adjList);
//              }
//         }
        
//         vector<int>dist(V,INT_MIN);
        
//         dist[src] = 0;
        
//         while(!st.empty()){
//             int node = st.top();
//             st.pop();
            
//             if(dist[node]==INT_MIN)
//               continue;
            
//             for(auto& it:adjList[node]){
//                 int adjNode = it.first;
//                 int wt = it.second;
                
//                 dist[adjNode] = max(dist[adjNode],dist[node]+wt);
//             }
//         }
        
//         return dist;
//     }




  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
         vector<int>indegree(V,0);
         vector<vector<pair<int,int>>>adjList(V);
         
         for(auto& edge:edges){
              int u = edge[0];
              int v = edge[1];
              int wt = edge[2];
              
              adjList[u].push_back({v,wt});
              indegree[v]++;
         }
         
         queue<int>q;
         
         for(int i=0;i<V;i++){
             if(indegree[i]==0)
                  q.push(i);
         }
         
         vector<int>dist(V,INT_MIN);
         
         dist[src] = 0;
         
         while(!q.empty()){
             int node = q.front();
             q.pop();
             
          
             
             for(auto& it:adjList[node]){
                 int adjNode = it.first;
                 int wt = it.second;
                 
                 indegree[adjNode]--;
                 
                 if (dist[node] != INT_MIN){
                     dist[adjNode] = max(dist[adjNode],dist[node]+wt);
                 }
                   
                 if(indegree[adjNode]==0)
                    q.push(adjNode);
             }
         }
         
         return dist;
             
    }

};