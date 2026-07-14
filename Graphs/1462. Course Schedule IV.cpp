#include "bits/stdc++.h"
using namespace std;

class Solution {
//DFS
private:
    bool checkPrerequisite(int node,int preCourse,vector<vector<int>>& adjList,vector<vector<int>>& queries){
       
          if(preCourse==node)
               return true;
          
          for(auto& it:adjList[node]){
               if(checkPrerequisite(it,preCourse,adjList,queries)){
                  return true; 
               }
          }

          return false;   
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
         vector<vector<int>>adjList(numCourses);
         vector<int>visited(numCourses,0);

         for(auto& course:prerequisites){
             int u = course[0];
             int v = course[1];

             adjList[v].push_back(u);
         }

         vector<bool>answer;

         for(int i=0;i<queries.size();i++){
              if(!visited[i]){
                if(checkPrerequisite(queries[i][1],queries[i][0],adjList,queries)){
                      answer.push_back(true);
                }else{
                    answer.push_back(false);
                }
              }
         }

         return answer;
    }


// BFS

// public:
//     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
//         vector<vector<int>>adjList(numCourses);

//         for(auto& course:prerequisites){
//               int u = course[0];
//               int v = course[1];

//               adjList[u].push_back(v);
//         }


//         vector<vector<bool>>reachable(numCourses,vector<bool>(numCourses,false));

//         for(int start=0;start<numCourses;start++){
//             queue<int>q;
//             vector<bool>visited(numCourses,false);
            
//             q.push(start);
//             visited[start] = true;

//             while(!q.empty()){
//                  int node = q.front();
//                  q.pop();
                 
//                  for(auto& it:adjList[node]){
//                      if(!visited[it]){
//                         visited[it] = true;
//                         reachable[start][it] = true;
//                         q.push(it);
//                      }
//                  }
//             }
//         }

//         vector<bool>answer;
        
//         for(auto& query:queries){
//              int u = query[0];
//              int v = query[1];

//              answer.push_back(reachable[u][v]);
//         }

//         return answer;
//     }
};