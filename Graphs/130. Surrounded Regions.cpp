#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    void dfs(int row,int col,int n ,int m,vector<vector<bool>>& visited,vector<vector<char>>& board){
        if(row<0 || row>=n || col<0 || col>=m)
            return;
        
        
        if(board[row][col]!='O' || visited[row][col])
            return;
        
        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,-1,1};
        
        visited[row][col]=true;
        
        for(int k=0;k<4;k++){
            int nRow = row + dr[k];
            int nCol = col + dc[k];
            
            dfs(nRow,nCol,n,m,visited,board);  
        }

    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            if(!visited[i][0] && board[i][0]=='O'){
                dfs(i,0,n,m,visited,board);
            }
        }

        for(int i=0;i<n;i++){
            if(!visited[i][m-1]  && board[i][m-1]=='O'){
                dfs(i,m-1,n,m,visited,board);
            }
        }

        for(int j=0;j<m;j++){
            if(!visited[0][j] && board[0][j]=='O'){
                dfs(0,j,n,m,visited,board);
            }
        }

        for(int j=0;j<m;j++){
            if(!visited[n-1][j] && board[n-1][j]=='O'){
                dfs(n - 1, j, n, m, visited, board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && visited[i][j]==false){
                      board[i][j] = 'X';
                }
            }
        }
    }
};