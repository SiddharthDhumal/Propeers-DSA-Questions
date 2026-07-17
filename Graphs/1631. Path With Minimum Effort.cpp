#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>> minHeap;
        
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

        dist[0][0] = 0;


        minHeap.push({0,{0,0}});

        vector<pair<int,int>>neighbourCells = {{-1,0},{1,0},{0,1},{0,-1}};

        while(!minHeap.empty()){
            auto& it = minHeap.top();
            pair<int,int>cell = it.second;
            int x = cell.first;
            int y = cell.second;
            int absDiff = it.first;
            minHeap.pop();

            if(x==n-1 && y==m-1) 
               return absDiff;

            if(absDiff > dist[x][y])
               continue;

            for(pair<int,int>neighbour:neighbourCells){ 
                 int newX = neighbour.first + x;
                 int newY = neighbour.second + y;
                
                if(newX>=0 && newX<n && newY>=0 && newY<m){
                     int maxAbsDiff = max(absDiff,abs(heights[newX][newY] - heights[x][y]));
                     
                     if(maxAbsDiff < dist[newX][newY]){
                        dist[newX][newY] = maxAbsDiff;
                        minHeap.push({maxAbsDiff,{newX,newY}});
                     }
                }
                 
            }

        }

        return 0; 
    }
};