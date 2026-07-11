#include "bits/stdc++.h"
using namespace std;

// TC - O(V+E) and SC - O(V+E) where V is the number of vertices and E is the number of edges

class Solution {
public:
    // bool dfs(int node,vector<int>& visited,stack<int>& st,vector<vector<int>>& adjList){
    //     if(visited[node]==1)
    //       return true;
        
    //     if(visited[node]==2)
    //        return false;
        
    //     visited[node] = 1;

    //     for(auto& it:adjList[node]){
    //         if(dfs(it,visited,st,adjList)){
    //              return true;
    //         }
    //     }

    //     visited[node] = 2;

    //     st.push(node);

    //     return false;
    // }

    // vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    //     vector<vector<int>>adjList(numCourses);
    //     vector<int>answer;
    //     stack<int>st;
    //     vector<int>visited(numCourses,0);

    //     for(int i=0;i<prerequisites.size();i++){
    //          int u = prerequisites[i][0];
    //          int v = prerequisites[i][1];

    //          adjList[v].push_back(u);
    //     }

    //     for(int i=0;i<numCourses;i++){
    //         if(!visited[i]){
    //           if(dfs(i,visited,st,adjList)){
    //             return answer;
    //           }
    //         }
            
    //     }

    //     while(!st.empty()){
    //         int top = st.top();
    //         st.pop();
    //         answer.push_back(top);
    //     }

    //     return answer;
    // }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>>adjList(numCourses);
        vector<int>indegree(numCourses,0);
        vector<int>answer;
        queue<int>q;

        for(int i=0;i<prerequisites.size();i++){
             int u = prerequisites[i][0];
             int v = prerequisites[i][1];

             adjList[v].push_back(u);
             indegree[u]++;

        }

        for(int i=0;i<indegree.size();i++){
             if(indegree[i]==0){
                 q.push(i);
             }
        }

        int processedCourses = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            processedCourses++;

            for(auto& it:adjList[node]){
                indegree[it]--;

                if(indegree[it]==0){
                    q.push(it);
                }
            }

            answer.push_back(node);

        }

        if(processedCourses!=numCourses) return {};
        else return answer;
    }
};