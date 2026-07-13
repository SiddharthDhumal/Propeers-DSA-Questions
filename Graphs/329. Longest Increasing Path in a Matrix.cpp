#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>indegree(n,vector<int>(m,0));

        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,-1,1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<4;k++){
                     int nr = i + dr[k];
                     int nc = j + dc[k];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && matrix[nr][nc] > matrix[i][j]){
                        indegree[nr][nc]++;
                    }
                }
            }
        }


        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                  if(indegree[i][j]==0){
                      q.push({i,j});
                  }
             }
        }


        int level = 0;

        while(!q.empty()){
            int size = q.size();

            level++;

            while(size--){
                auto [row,col] = q.front();
                q.pop();

                for(int k=0;k<4;k++){
                    int nr = row + dr[k];
                    int nc = col + dc[k];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && matrix[nr][nc]>matrix[row][col]){
                          indegree[nr][nc]--;

                          if(indegree[nr][nc]==0)
                                q.push({nr,nc});
                    }
                }
            } 
        }

        return level;
    }
};