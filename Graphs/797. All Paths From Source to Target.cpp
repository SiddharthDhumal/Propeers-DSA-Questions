// Time Complexity

// Suppose

// V = number of vertices
// P = number of valid paths
// L = average length of a path

// DFS visits every valid path once.

// Time Complexity:

// O(P×L)
// 	​


// In the worst case, the number of paths can be exponential (for example, a DAG where every node branches to many others), so the runtime is exponential in the size of the graph.

// Space Complexity
// DFS recursion stack: O(V)
// Current path vector: O(V)
// Output storage: proportional to the total size of all returned paths.

// Ignoring the output:

// O(V)
// 	​


// Including the output, the space is dominated by the number and length of all paths stored.

#include "bits/stdc++.h"
using namespace std;

class Solution {
private:
    void dfs(int node,int destination,vector<int>& path,vector<vector<int>>& graph,vector<vector<int>>& sourceToTarget){

        if(node==destination){
             sourceToTarget.push_back(path);
             return;
        }

        for(auto& it:graph[node]){
             path.push_back(it);
             dfs(it,destination,path,graph,sourceToTarget);
             path.pop_back();
        }
          
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>sourceToTarget;

        int destination = graph.size() -1;

        vector<int>path;

        path.push_back(0);

        dfs(0,destination,path,graph,sourceToTarget);

        return sourceToTarget;
    }
};