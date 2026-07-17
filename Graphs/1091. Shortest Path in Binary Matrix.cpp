#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         int n = grid.size();
         int m =grid[0].size();

         if(grid[0][0]==1) return -1;

         if(grid[0][0]==0 && n==1 && m==1) return 1;
         
         queue<pair<pair<int,int>,int>>q;
         
     

         vector<vector<bool>>visited(n,vector<bool>(m,false));
         visited[0][0] = true;

         q.push({{0,0},1});

         vector<pair<int,int>> neighbours ={{0,1}, {0,-1}, {1,0}, {-1,0},{1,1}, {-1,-1}, {1,-1}, {-1,1}};

         while(!q.empty()){
            auto& it = q.front();
            pair<int,int> coOrdinates = it.first;
            int x = coOrdinates.first;
            int y = coOrdinates.second;
            int lengthOfPath = it.second;
            q.pop();

            for(pair<int,int>neighbour:neighbours){
                int newX = neighbour.first + x;
                int newY = neighbour.second + y;

                if(newX<n && newY<m && newX>=0 && newY>=0 && grid[newX][newY]==0 && !visited[newX][newY]){
                      q.push({{newX,newY},lengthOfPath+1});
                      visited[newX][newY] = true;
                      
                      if(newX==n-1 && newY==m-1) return lengthOfPath+1;
                }

                
            }

         }

         return -1;
    }
};