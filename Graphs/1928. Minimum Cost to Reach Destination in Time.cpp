#include "bits/stdc++.h"
using namespace std;


// Complexity

// There are

// n cities

// For every city

// there can be

// maxTime+1

// different states.

// So

// States

// =

// n × maxTime

// Each edge can relax from each time state.

// Time complexity is approximately

// O((n×maxTime+E×maxTime)log(n×maxTime))

// With the given constraints (n ≤ 1000, maxTime ≤ 1000, E ≤ 1000), this is acceptable.

// Space complexity is O(n×maxTime) for the distance array and the priority queue.

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges,
                vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int, int>>> adjList(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int time = edge[2];

            adjList[u].push_back({v, time});
            adjList[v].push_back({u, time});
        }

        vector<vector<int>> dist(n, vector<int>(maxTime + 1, INT_MAX));

        dist[0][0] = passingFees[0];

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            minHeap;

        minHeap.push({passingFees[0], {0, 0}});

        while (!minHeap.empty()) {
            auto it = minHeap.top();
            int cost = it.first;
            int time = it.second.first;
            int node = it.second.second;

            minHeap.pop();

            if (time > maxTime)
                continue;

            if (cost > dist[node][time])
                continue;

            for (auto& it : adjList[node]) {
                int adjNode = it.first;
                int adjTime = it.second;
                if (adjTime + time <= maxTime) {
                    if (dist[adjNode][adjTime + time] >
                        cost + passingFees[adjNode]) {
                        dist[adjNode][adjTime + time] =
                            cost + passingFees[adjNode];
                        minHeap.push({dist[adjNode][adjTime + time],
                                      {adjTime + time, adjNode}});
                    }
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i <= maxTime; i++) {
            ans = min(ans, dist[n - 1][i]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};