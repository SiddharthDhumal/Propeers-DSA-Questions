#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adjList(n);

        for(int i=0;i<edges.size();i++){
             int u = edges[i][0];
             int v = edges[i][1];
             double prob = succProb[i];

             adjList[u].push_back({v,prob});
             adjList[v].push_back({u,prob});
        }


        vector<double>dist(n,0.0);

        dist[start_node] = 1.0;

        priority_queue<pair<double,int>> maxHeap;

        maxHeap.push({1.0,start_node});

        while(!maxHeap.empty()){
            auto it = maxHeap.top();
            double prob = it.first;
            int node = it.second;
            maxHeap.pop();

            if(prob < dist[node])
                continue;

            for(auto& it:adjList[node]){
                 int adjNode = it.first;
                 double adjProb = it.second;

                 if(dist[adjNode] < (adjProb * prob)){
                       dist[adjNode] = (double)(adjProb * prob); 
                       maxHeap.push({dist[adjNode],adjNode});
                 }
            }
        }


      return dist[end_node];
    }
};


// Step 1: Number of vertices

// There are

// n

// nodes (cities).

// So,

// Vertices = V = n
// Step 2: Number of edges

// Suppose there are

// m

// edges.

// In the problem,

// edges.size()

// is the number of edges.

// Let's denote it by

// E = m
// Step 3: What happens in Dijkstra?

// For every node we process,

// we visit all its neighbours.

// That means over the whole algorithm,

// every edge is relaxed.

// Each relaxation may insert one entry into the priority queue.

// Step 4: Heap operations

// Every insertion into the heap takes

// O(log n)

// because the heap contains at most n nodes (or more entries due to duplicates, but asymptotically it's still analyzed as O(E log V)).

// Total Time Complexity

// Standard Dijkstra using a priority queue has

// O((V+E)logV)
// 	​


// Substitute

// V = n

// E = m

// So,

// O((n+m)logn)
// 	​


// Since in most graphs

// m > n

// we usually simplify it to

// O(mlogn)
// 	​

// Example

// Suppose

// 100 cities

// 300 roads

// Then

// Vertices = 100

// Edges = 300

// Complexity becomes

// (100+300) × log(100)

// ≈ 400 × 7
// Space Complexity

// Let's count each data structure.

// 1. Adjacency List

// Stores every edge.

// For an undirected graph,

// every edge is stored twice.

// u → v

// v → u

// Still

// O(E)
// 2. Distance Array
// vector<double> dist(n);

// Stores one value for every node.

// O(V)
// 3. Priority Queue

// Worst case,

// every relaxation inserts one element.

// So it can grow to

// O(E)
// Total Space
// Adjacency List

// ↓

// O(E)

// +

// Distance Array

// ↓

// O(V)

// +

// Priority Queue

// ↓

// O(E)

// Overall

// O(V+E)
// 	​


// or

// O(n+m)
// 	​

// Final Answer
// Complexity	Value
// Time Complexity	O((V + E) log V) = O((n + m) log n) ≈ O(m log n)
// Space Complexity	O(V + E) = O(n + m)
// A small pattern to remember

// For normal Dijkstra problems like:

// Network Delay Time
// Path With Maximum Probability
// Number of Ways to Arrive at Destination

// the complexity is almost always:

// Time: O((V + E) log V)
// Space: O(V + E)

// Only when you add extra state (such as (node, stops) or (node, timeSpent)) does the complexity grow based on the size of that additional state.