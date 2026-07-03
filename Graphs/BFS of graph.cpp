#include "bits/stdc++.h"
using namespace std;

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int>visited(n);
        vector<int> answer;
        
        queue<int>q;
        
        q.push(0);
        visited[0] = 1;
        
        while(!q.empty()){
             int node = q.front();
                 
             answer.push_back(node);         
             
             q.pop();
             
             for(int i =0;i<adj[node].size();i++){
                 int u = adj[node][i];
                 if(!visited[u]){
                      visited[u] = 1;
                      q.push(u);
                 }
             }
        }
        
        return answer;
        
    }
};




// Time Complexity

// Let

// V = Number of vertices
// E = Number of edges
// Every vertex

// is pushed

// Exactly once

// and popped

// Exactly once

// Cost

// O(V)
// Every edge

// is examined

// For an undirected graph

// 2E

// adjacency entries

// Still

// O(E)
// Overall
// O(V + E)

// This is optimal.

// Space Complexity

// Visited array

// O(V)

// Queue

// Worst case

// O(V)

// Answer

// O(V)

// Auxiliary Space

// O(V)

// Total including returned answer

// O(V)