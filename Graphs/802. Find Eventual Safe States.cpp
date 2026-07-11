#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    // bool checkSafe(int node,vector<int>& visited,vector<vector<int>>& graph){
    //      if(visited[node]== 1)
    //          return false;
         
    //      if(visited[node]==2)
    //          return true;

    //      visited[node] = 1;
        
    //      for(auto& it:graph[node]){
    //         if(!checkSafe(it,visited,graph)){
    //             return false;
    //         }
    //      }
         
    //      visited[node] = 2;

    //      return true;
    // }

    // vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    //     int V = graph.size();
    //     vector<int>safeNodes;
    //     vector<int> visited(V,0);


    //     for(int i=0;i<V;i++){
    //              if(checkSafe(i,visited,graph)){
    //                 safeNodes.push_back(i);
    //              }
    //     }

    //     return safeNodes;
    // }
    

    // for bfs TC - O(V+E+VlogV) and SC - O(V+E)
    // for bfs TC - O(V+E) and SC - O(V+E)
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>safeNodes;
        vector<int>outdegree(V,0);
        vector<vector<int>>reTraversal(V);
        queue<int>q;

        for(int i=0;i<V;i++){
            for(auto& it:graph[i]){
                 outdegree[i]++;
                 reTraversal[it].push_back(i);
            }
        }

        for(int i=0;i<V;i++){
             if(outdegree[i]==0){
                 q.push(i);
             }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            safeNodes.push_back(node);
            for(auto& it:reTraversal[node]){
                outdegree[it]--;

                if(outdegree[it]==0){
                    q.push(it);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }

};