#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int modulo = 1e9 + 7;
        vector<vector<pair<int,int>>>adjList(n+1);

        for(auto& road:roads){
            int u = road[0];
            int v = road[1];
            int wt = road[2];

            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }

        vector<long long>dist(n+1,LLONG_MAX);
        vector<int>ways(n+1,0);
        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> minHeap;
        
        minHeap.push({0,0});

        while(!minHeap.empty()){
            long long dis = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();

            if(dis>dist[node])
                continue;

            for(auto& it:adjList[node]){
                int adjNode = it.first;
                int adjDist = it.second;

                if(adjDist+dis<=dist[adjNode]){
                   
                   if(dist[adjNode]==adjDist+dis){
                    //    ways[adjNode] += ways[node]%modulo;  this is wrong and can overflow
                    ways[adjNode] = (ways[adjNode] + ways[node]) % modulo;
                   }else{
                        ways[adjNode] = ways[node];
                        dist[adjNode] = adjDist + dis;
                        minHeap.push({dist[adjNode],adjNode}); 
                   }
                }
            }
        }

        return ways[n-1]%modulo;
    }
};