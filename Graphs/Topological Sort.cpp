#include "bits/stdc++.h"
using namespace std;

class Solution {
//   private:
//     void dfs(int node,vector<int>& visited,stack<int>& st,vector<vector<int>>& adjList){
//              visited[node] = 1;
             
//              for(auto& it:adjList[node]){
//                  if(!visited[it]){
                     
//                      dfs(it,visited,st,adjList);
//                  }
//              }
             
//              st.push(node);
//     }
    
//   public:
//     vector<int> topoSort(int V, vector<vector<int>>& edges) {
//         // code here
//         vector<vector<int>>adjList(V);
//         vector<int>visited(V,0);
//         vector<int>answer;
//         stack<int>st;
        
//         for(int i=0;i<edges.size();i++){
//             int u = edges[i][0];
//             int v = edges[i][1];
            
//             adjList[u].push_back(v);
//         }
        
//         for(int i=0;i<V;i++){
//             if(!visited[i]){
//                 dfs(i,visited,st,adjList);
//             }
//         }
        
        
//         while(!st.empty()){
//             answer.push_back(st.top());
//             st.pop();
//         }
        
//         return answer;
//     }



    public:
      vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adjList(V);
        vector<int>indegree(V,0);
        vector<int>topoSort;
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
        }
        
        queue<int>q;
        
        
        for(int i=0;i<V;i++){
            for(auto& it:adjList[i]){
                indegree[it]++;
            }
        }
        
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            topoSort.push_back(node);
            
            for(auto& it:adjList[node]){
                indegree[it]--;
                
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        
        return topoSort;

      }
   
};