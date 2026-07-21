#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        vector<vector<pair<int,int>>>adjList(n);

        for(auto& highway:highways){
             int city1 = highway[0];
             int city2 = highway[1];
             int toll = highway[2];

             adjList[city1].push_back({city2,toll});
             adjList[city2].push_back({city1,toll});
        }
        
        /*
            dist[node][d] =
            Minimum cost to reach 'node'
            after using exactly 'd' discounts.
        */
        vector<vector<int>>dist(n,vector<int>(discounts + 1,INT_MAX));

        dist[0][0] = 0;
        
        /*
            Heap stores

            {cost, {node, discountsUsed}}

            We prioritize the minimum cost first.
        */
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>minHeap;
        
        minHeap.push({0,{0,0}});

        while(!minHeap.empty()){
            auto it = minHeap.top();
            int cost = it.first;
            int node = it.second.first;
            int used = it.second.second;

            minHeap.pop();

            if(cost>dist[node][used])
                continue;
            
            for(auto& edge:adjList[node]){
                 int adjNode = edge.first;
                 int adjToll = edge.second;

                 //-------------------------------------------------
                 // Option 1 : Don't use a discount
                 //-------------------------------------------------
                 if(adjToll + cost < dist[adjNode][used]){
                    dist[adjNode][used] = cost + adjToll;

                    minHeap.push({dist[adjNode][used],{adjNode, used}});
                 }


                 //-------------------------------------------------
                // Option 2 : Use a discount
                //-------------------------------------------------
                if(used<discounts && cost + adjToll/2 < dist[adjNode][used+1]){
                       dist[adjNode][used+1] = cost + adjToll/2;

                       minHeap.push({dist[adjNode][used+1],{adjNode,used+1}});
                }
            }
        }


        int ans = INT_MAX;
        
        // Destination can be reached using
        // 0,1,2,...discounts
        for(int d=0;d<=discounts;d++){
             ans = min(ans,dist[n-1][d]);
        }


        return ans==INT_MAX ? -1 : ans;

    }
};