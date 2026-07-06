#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    // void dfs(int node,int n,vector<int>& visited,vector<vector<int>>& isConnected){
    //      visited[node] = 1;

    //      for(int i=0;i<n;i++){
    //         if(!visited[i] && isConnected[node][i]==1){
    //              dfs(i,n,visited,isConnected);
    //         }
    //      }
    // }
    // int findCircleNum(vector<vector<int>>& isConnected) {
    //      int n = isConnected.size();
         
    //      vector<int>visited(n,0);
    //      int provinces = 0;

    //      for(int i=0;i<n;i++){
    //         if(!visited[i]){
    //             provinces++;
    //             dfs(i,n,visited,isConnected);
    //         }
    //      }
         
    //      return provinces;
    // }



     int findCircleNum(vector<vector<int>>& isConnected) {
         int n = isConnected.size();
         
         vector<bool>visited(n,false);
         int provinces = 0;
         queue<int>q;

         for(int i=0;i<n;i++){
            if(!visited[i] && isConnected[i][i]==1){
                 q.push(i);
                 visited[i] = true;
                 provinces++;
                 while(!q.empty()){
                    int city = q.front();
                    q.pop();

                    for(int i=0;i<n;i++){
                        
                        if(!visited[i] && isConnected[city][i]==1){
                             visited[i] = true;
                             q.push(i);
                        }
                    }
                 }
            }
         }
         
         return provinces;
    }
};