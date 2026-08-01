#include <bits/stdc++.h>
using namespace std;

// For Dijkstra Algorithm
// | Operation                   | Complexity      |
// | --------------------------- | --------------- |
// | Build Graph                 | O(E)            |
// | One Dijkstra                | O(E log V)      |
// | Run Dijkstra for every city | **O(VE log V)** |
// | Count reachable cities      | O(V²)           |
// | **Overall Time**            | **O(VE log V)** |
// | **Overall Space**           | **O(V + E)**    |


class Solution {
public:
    // Using DijKestra Algorithm TC - O(VE log V) and SC - O(V + E) where E  - Edges and V - nodes
    // int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    //     vector<vector<pair<int, int>>> adjList(n);

    //     for (auto& edge : edges) {
    //         int u = edge[0];
    //         int v = edge[1];
    //         int wt = edge[2];

    //         adjList[u].push_back({v, wt});
    //         adjList[v].push_back({u, wt});
    //     }


    //     vector<int> numCity(n, 0);

    //     for (int i = 0; i < n; i++) {
    //         vector<int> distance(n, INT_MAX);
    //         distance[i] = 0;
    //         priority_queue<pair<int, int>, vector<pair<int, int>>,
    //                    greater<pair<int, int>>>
    //         minHeap;

    //         minHeap.push({0, i});
    //         while (!minHeap.empty()) {
    //             int wt = minHeap.top().first;
    //             int node = minHeap.top().second;
    //             minHeap.pop();

    //             if(wt > distance[node])
    //                 continue;

    //             for (auto& it : adjList[node]) {
    //                 int adjNode = it.first;
    //                 int adjWt = it.second;

    //                 if (adjWt + wt < distance[adjNode]) {
    //                     distance[adjNode] = adjWt + wt;

    //                     minHeap.push({distance[adjNode], adjNode});
    //                 }
    //             }
    //         }

    //         int cnt = 0;
    //         for(int j=0;j<n;j++){
    //             if(i!=j && distance[j]<=distanceThreshold)
    //                cnt++;
    //         }

    //         numCity[i] = cnt;
    //     }

    //     int lowestReach = numCity[n - 1];
    //     for (int i = n - 1; i >= 0; i--) {
    //         lowestReach = min(lowestReach, numCity[i]);
    //     }

    //     for (int i = n - 1; i >= 0; i--) {
    //         if (numCity[i] == lowestReach)
    //             return i;
    //     }

    //     return -1;
    // }




    // Using Floyd Warshell Algorithm  TC - O(V3) and SC - O(V2)
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        	vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
		for (auto it : edges) {
			dist[it[0]][it[1]] = it[2];
			dist[it[1]][it[0]] = it[2];
		}
		for (int i = 0; i < n; i++) dist[i][i] = 0;
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
						continue;
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		int cntCity = n;
		int cityNo = -1;
		for (int city = 0; city < n; city++) {
			int cnt = 0;
			for (int adjCity = 0; adjCity < n; adjCity++) {
				if (dist[city][adjCity] <= distanceThreshold)
					cnt++;
			}

			if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = city;
			}
		}
		return cityNo;
    }
};