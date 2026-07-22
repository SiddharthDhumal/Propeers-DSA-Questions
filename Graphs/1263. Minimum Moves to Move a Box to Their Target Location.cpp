#include "bits/stdc++.h"
using namespace std;



// Time Complexity

// Let's derive it simply.

// Outer BFS states

// Player can be at any cell.

// Box can be at any cell.

// Maximum states

// (m × n) × (m × n)

// =

// O((mn)²)
// Inner BFS

// Every outer state may run one BFS for the player.

// Player BFS visits at most

// m × n

// cells.

// So

// O(mn)
// Total
// Outer States × Inner BFS

// =

// O((mn)² × mn)

// =

// O((mn)³)

// Since m, n ≤ 20, there are at most 400 cells, making this approach practical for the problem constraints.

// Interview Summary

// The entire solution boils down to these three ideas:

// Outer BFS explores states by number of pushes because every push costs exactly 1.
// Inner BFS checks whether the player can walk to the correct side of the box before a push, treating the box as an obstacle.
// State = (box position, player position) because both positions determine what pushes are possible next.



class Solution {
public:
    int m, n;
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

    // Check if player can reach (tr, tc) without crossing the box.
    bool canReach(vector<vector<char>>& grid,
                  int sr, int sc,
                  int tr, int tc,
                  int boxR, int boxC) {

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        q.push({sr, sc});
        vis[sr][sc] = true;

        while(!q.empty()) {

            auto [r,c] = q.front();
            q.pop();

            if(r == tr && c == tc)
                return true;

            for(auto [dr,dc] : dir){

                int nr = r + dr;
                int nc = c + dc;

                if(nr<0 || nr>=m || nc<0 || nc>=n)
                    continue;

                if(vis[nr][nc])
                    continue;

                if(grid[nr][nc] == '#')
                    continue;

                // Player cannot walk through the box.
                if(nr == boxR && nc == boxC)
                    continue;

                vis[nr][nc] = true;
                q.push({nr,nc});
            }
        }

        return false;
    }

    int minPushBox(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        int playerR, playerC;
        int boxR, boxC;
        int targetR, targetC;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]=='S'){
                    playerR=i;
                    playerC=j;
                }

                if(grid[i][j]=='B'){
                    boxR=i;
                    boxC=j;
                }

                if(grid[i][j]=='T'){
                    targetR=i;
                    targetC=j;
                }
            }
        }

        queue<vector<int>> q;

        set<vector<int>> vis;

        q.push({boxR, boxC, playerR, playerC, 0});

        vis.insert({boxR, boxC, playerR, playerC});

        while(!q.empty()){

            auto cur = q.front();
            q.pop();

            int bR = cur[0];
            int bC = cur[1];
            int pR = cur[2];
            int pC = cur[3];
            int pushes = cur[4];

            if(bR==targetR && bC==targetC)
                return pushes;

            // Try pushing in all 4 directions
            for(auto [dr,dc] : dir){

                int newBoxR = bR + dr;
                int newBoxC = bC + dc;

                // Player must stand opposite side.
                int needPlayerR = bR - dr;
                int needPlayerC = bC - dc;

                if(newBoxR<0 || newBoxR>=m ||
                   newBoxC<0 || newBoxC>=n)
                    continue;

                if(needPlayerR<0 || needPlayerR>=m ||
                   needPlayerC<0 || needPlayerC>=n)
                    continue;

                if(grid[newBoxR][newBoxC]=='#')
                    continue;

                if(grid[needPlayerR][needPlayerC]=='#')
                    continue;

                // Can player reach required pushing position?
                if(!canReach(grid,
                             pR,pC,
                             needPlayerR,needPlayerC,
                             bR,bC))
                    continue;

                vector<int> state = {
                    newBoxR,
                    newBoxC,
                    bR,
                    bC
                };

                if(vis.count(state))
                    continue;

                vis.insert(state);

                q.push({
                    newBoxR,
                    newBoxC,
                    bR,
                    bC,
                    pushes+1
                });
            }
        }

        return -1;
    }
};