#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    // bool dfs(int node,vector<int>& visited,vector<vector<int>>& adjList){

    //      if(visited[node]==1)
    //          return true;
         
    //      if(visited[node]==2)
    //          return false;

    //      visited[node] = 1;
        
    //     for(auto& it:adjList[node]){
    //          if(dfs(it,visited,adjList))
    //              return true;
    
    //     }

    //     visited[node] = 2;

    //     return false;
    // }

    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //      vector<vector<int>>adjList(numCourses);

    //      for(int i=0;i<prerequisites.size();i++){
    //         int u = prerequisites[i][0];
    //         int v = prerequisites[i][1];

    //         adjList[v].push_back(u);
    //      }

    //      vector<int>visited(numCourses,0);

    //      for(int i= 0; i<numCourses;i++){
    //         if(dfs(i,visited,adjList))
    //             return false;
    //      }


    //      return true;
    // }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int>indegree(numCourses);

       vector<vector<int>>adjList(numCourses);
       queue<int>q;

       for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[v].push_back(u);
            indegree[u]++;
       }

       for(int i=0;i<indegree.size();i++){
           if(indegree[i]==0)
              q.push(i);
       }

       int processedCourses = 0;


       while(!q.empty()){
           int node = q.front();
           q.pop();
           
           processedCourses++;
         
           for(auto& it:adjList[node]){
                indegree[it]--;

                if(indegree[it]==0)
                   q.push(it);
           }
       }


       return processedCourses == numCourses; 



    }
};