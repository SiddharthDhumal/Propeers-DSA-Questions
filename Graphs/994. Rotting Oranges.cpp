#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        
        if(fresh==0)
           return 0;
        
        int minutes = 0;

        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,-1,1};

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int row = q.front().first;
                int col = q.front().second;

                q.pop();

                for(int k=0;k<4;k++){
                    int newRow = row + dr[k];
                    int newCol = col + dc[k];

                    if(newRow>=0 && newRow<n && newCol >=0 && newCol<m && grid[newRow][newCol]==1){
                            grid[newRow][newCol] = 2;
                            fresh--;
                            q.push({newRow,newCol});
                    }
                }

            }

            minutes++;
        }

        if(fresh!=0)
           return -1;
        
        return minutes - 1;

    }
};



// Time Complexity

// Let

// N = rows
// M = columns

// Each cell enters the queue at most once.

// Each cell is processed once.

// Each cell checks 4 neighbours.

// So

// O(N×M)
// Space Complexity

// Queue

// Worst case

// Every orange enters the queue.

// O(N×M)