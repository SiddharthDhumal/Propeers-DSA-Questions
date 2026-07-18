#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adjList(n+1);
        
        for(auto& time:times){
             int u = time[0];
             int v = time[1];
             int wt = time[2];
             
             adjList[u].push_back({v,wt});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        vector<int>efforts(n+1,INT_MAX);

        efforts[k] = 0;

        minHeap.push({0,k});

        while(!minHeap.empty()){
            int wt = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();

            if(wt>efforts[node])
               continue;

            for(auto& it:adjList[node]){
                 int adjNode = it.first;
                 int adjWt = it.second;

                 if(adjWt + wt < efforts[adjNode]){
                     efforts[adjNode] = adjWt + wt;
                     minHeap.push({efforts[adjNode],adjNode});
                 }
            }
        }

        int answer = 0;

        for(int i=1;i<efforts.size();i++){
             if(efforts[i]==INT_MAX) return -1;
             
             answer = max(answer,efforts[i]);
        }

        return answer;
    }
};