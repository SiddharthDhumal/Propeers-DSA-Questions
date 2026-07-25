#include "bits/stdc++.h"
using namespace std;


class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        //prim's Algorithm
        
        vector<pair<int,int>>mst;
        int Sum = 0;
        vector<vector<pair<int,int>>>adjList(V);
        
        for(auto& edge:edges){
             int u = edge[0];
             int v = edge[1];
             int wt = edge[2];
             
             adjList[u].push_back({v,wt});
             adjList[v].push_back({u,wt});
        }
        
        vector<int>visited(V,0);
        priority_queue<
        pair<int,pair<int,int>>, 
        vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>>minHeap;
        
        minHeap.push({0,{0,-1}});
        
        while(!minHeap.empty()){
            auto it = minHeap.top();
            int wt = it.first;
            int node = it.second.first;
            int parent = it.second.second;
            
            minHeap.pop();
            
            if(visited[node])
               continue;
            
            visited[node] = 1;
            Sum += wt;
            
            if(parent != -1)
                  mst.push_back({parent,node});
            
            for(auto it:adjList[node]){
                int adjNode = it.first;
                int adjWt = it.second;
                
                if(!visited[adjNode]){
                    minHeap.push({adjWt,{adjNode,node}});
                }
            }
            
        }
        
        return Sum;
    }
};



// Time Complexity

// Let's derive it.

// Step 1: Build adjacency list

// We visit every edge once.

// O(E)
// Step 2: Heap operations

// Every edge can be pushed into the heap.

// In an undirected graph,

// Total pushes ≤ 2E

// Each push takes

// O(log E)

// or equivalently O(log V) in asymptotic analysis.

// Step 3: Pop operations

// Every heap element is popped once.

// Again,

// O(E log V)
// Total Time Complexity
// O(E + E log V)

// Since

// E log V > E

// we write

// O(ElogV)
// 	​

// Space Complexity
// Adjacency List
// O(E)
// Visited Array
// O(V)
// Priority Queue

// In the worst case,

// many candidate edges are in the heap simultaneously.

// O(E)
// MST Vector

// Stores

// V-1

// edges.

// O(V)
// Total
// O(V+E)