#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    // int maxAreaOfIsland(vector<vector<int>>& grid) {
    //       int m = grid.size();
    //       int n = grid[0].size();

    //       vector<vector<bool>>visited(m,vector<bool>(n,false));
    //       int maxArea = 0;
    //       queue<pair<int,int>>q;
          
    //       vector<int>dr = {-1,1,0,0};
    //       vector<int>dc = {0,0,-1,1};

    //       for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             if(!visited[i][j] && grid[i][j]==1){
    //                 q.push({i,j});
    //                 visited[i][j] = true;
    //                 int area = 1;
    //                 while(!q.empty()){
    //                     int row = q.front().first;
    //                     int col = q.front().second;
    //                     q.pop();
                        
    //                     for(int k=0;k<4;k++){
    //                         int newRow = row + dr[k];
    //                         int newCol = col + dc[k];
    //                         if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && !visited[newRow][newCol] && grid[newRow][newCol]==1){
    //                              visited[newRow][newCol] = true;
    //                              q.push({newRow,newCol});
    //                              area++;
                           
    //                         }
    //                     }
    //                 }
                    
    //                 maxArea = max(maxArea,area);
    //             }
    //         }
    //       }


    //     return  maxArea;
    // }

        void dfs(int i,int j,int m,int n,int& area, int& maxArea,vector<vector<bool>>& visited,vector<vector<int>>& grid){

            if(i<0 || j<0 || i>=m || j>=n)
                return;

            if(grid[i][j]==0)
                return;

            if(visited[i][j])
                return;


            area++;

             visited[i][j] = true;

           
            
        
            dfs(i+1,j,m,n,area,maxArea,visited,grid);
            dfs(i-1,j,m,n,area,maxArea,visited,grid);
            dfs(i,j+1,m,n,area,maxArea,visited,grid);
            dfs(i,j-1,m,n,area,maxArea,visited,grid);  
             
        }

        int maxAreaOfIsland(vector<vector<int>>& grid) {
          int m = grid.size();
          int n = grid[0].size();

          vector<vector<bool>>visited(m,vector<bool>(n,false));
          int maxArea = 0;


          for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 if(!visited[i][j] && grid[i][j]==1){
                     int area = 0;
                    dfs(i,j,m,n,area,maxArea,visited,grid);
                    maxArea = max(maxArea,area);
                 }
            }
          }

          return maxArea;
          
        }
};