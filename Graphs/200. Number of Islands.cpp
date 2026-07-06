#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    // void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>&
    // visited){

    //       int m = grid.size();
    //       int n = grid[0].size();

    //       if(i<0 || j<0 || i>=m || j>=n)
    //          return;

    //       if(grid[i][j]=='0')
    //          return;

    //       if(visited[i][j])
    //           return;

    //       visited[i][j] = true;

    //       dfs(i-1,j,grid,visited);
    //       dfs(i+1,j,grid,visited);
    //       dfs(i,j-1,grid,visited);
    //       dfs(i,j+1,grid,visited);
    // }
    // int numIslands(vector<vector<char>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();

    //     vector<vector<bool>>visited(m,vector<bool>(n,false));
    //     int isIsland = 0;

    //     for(int i=0;i<m;i++){
    //          for(int j=0;j<n;j++){
    //             if(grid[i][j]=='1' && !visited[i][j]){
    //                 isIsland++;
    //                 dfs(i,j,grid,visited);
    //             }
    //          }
    //     }

    //     return isIsland;

    // }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int isIsland = 0;

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && visited[i][j]==false) {
                    visited[i][j] = true;
                    q.push({i, j});
                    isIsland++;
                    while (!q.empty()) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int newRow = row + dr[k];
                            int newCol = col + dc[k];

                            if (newRow >= 0 && newRow < n && newCol >= 0 &&
                                newCol < m && grid[newRow][newCol] == '1') {
                                if (visited[newRow][newCol] == false) {
                                    visited[newRow][newCol] = true;
                                    q.push({newRow, newCol});
                                }
                            }
                        }
                    }
                }
            }
        }

        return isIsland;
    }
};