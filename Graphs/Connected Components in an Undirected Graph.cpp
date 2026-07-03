#include "bits/stdc++.h"
using namespace std;

class Solution {
  public:
    void dfs(int node,vector<int>&visited,vector<vector<int>>&adjList,vector<int>&components){
       visited[node] = 1;
       components.push_back(node);
       
       for(int i=0;i<adjList[node].size();i++){
           int u = adjList[node][i];
           if(!visited[u]){
               dfs(u,visited,adjList,components);
           }
       }
    }
    
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adjList(V);
        vector<vector<int>>connectedComponents;
        
        int m = edges.size();
        
        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<int>visited(V);
        
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                vector<int>components;
                dfs(i,visited,adjList,components);
                connectedComponents.push_back(components);
            }

        }
        
        return connectedComponents;
        
    }
};





// Time Complexity

// Let's break it down.

// Step 1: Building the adjacency list
// for(int i = 0; i < m; i++) {
//     int u = edges[i][0];
//     int v = edges[i][1];

//     adjList[u].push_back(v);
//     adjList[v].push_back(u);
// }

// Here,

// m = edges.size() = E

// You process each edge exactly once.

// Since the graph is undirected, each edge is inserted twice:

// u -> v
// v -> u

// But that's still constant work per edge.

// Time
// O(E)
// Step 2: Outer loop
// for(int i=0;i<V;i++)

// Runs V times.

// But notice

// if(!visited[i])

// DFS is not called for every vertex.

// It is called only once for each connected component.

// Step 3: DFS

// People often think

// DFS is called many times, so complexity must be O(V²).

// That's incorrect.

// Here's why.

// Suppose

// 0 -- 1 -- 2 -- 3

// Start DFS from 0.

// Visits

// 0

// ↓

// 1

// ↓

// 2

// ↓

// 3

// Now

// visited

// 1 1 1 1

// When outer loop reaches

// 1

// 2

// 3

// DFS is skipped.

// Each vertex is visited exactly once.

// How many times is each edge explored?

// Consider

// 0 -----1

// Adjacency list

// 0 -> 1

// 1 -> 0

// DFS sees

// 0 →1

// 1 →0

// Each stored adjacency entry is processed once.

// Since there are

// 2E

// entries in an undirected graph,

// processing all adjacency lists costs

// O(E)
// Overall Time Complexity

// Building adjacency list

// O(E)

// DFS traversal

// O(V+E)

// Total

// O(V+E)

// because

// O(E) + O(V+E)

// =

// O(V+E)
// Space Complexity

// Let's count everything.

// 1. Adjacency List
// vector<vector<int>> adjList(V);

// Stores every edge twice.

// Memory

// O(V+E)
// 2. Visited Array
// vector<int> visited(V);

// Size

// O(V)
// 3. DFS Recursion Stack

// Worst case

// 0-1-2-3-4-5

// Depth

// V

// So recursion stack

// O(V)
// 4. Components Vector

// Suppose graph

// 0--1

// 2--3

// 4

// Eventually

// [
//  [0,1],
//  [2,3],
//  [4]
// ]

// How many integers are stored?

// Exactly

// V

// because every node belongs to exactly one component.

// Space

// O(V)
// Total Auxiliary Space

// Interviewers usually distinguish between:

// Auxiliary Space (excluding output)
// Adjacency list: O(V + E) (needed representation)
// Visited: O(V)
// Recursion stack: O(V)

// Overall:

// O(V+E)

// since O(V+E) dominates O(V).

// Including Output

// The returned answer stores all vertices exactly once.

// Additional output space:

// O(V)

// So total memory used by the algorithm plus its output is still

// O(V+E)