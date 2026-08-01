#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // brute force approach TC - O(n3) and SC - O(1)
    // int equalPairs(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     int cnt = 0;

    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             bool same = true;
    //             for(int k=0;k<n;k++){
    //                  if(grid[i][k]!=grid[k][j]){
    //                      same = false;
    //                      break;
    //                  }
    //             }
                
    //             if(same)
    //               cnt++;
    //         }
    //     }

    //     return cnt;
    // }

    
    // Better Approach  TC - O(n2 log n) and SC - O(n2)
    int equalPairs(vector<vector<int>>& grid) {
          int n = grid.size();

          map<vector<int>, int> mp;

          for(int i=0;i<n;i++){
              mp[grid[i]]++;
          }

          int answer = 0;

          for(int j=0;j<n;j++){
              vector<int>column;
              for(int i=0;i<n;i++){
                 column.push_back(grid[i][j]);
              }

            answer += mp[column];
          }

          return answer;
    }
};