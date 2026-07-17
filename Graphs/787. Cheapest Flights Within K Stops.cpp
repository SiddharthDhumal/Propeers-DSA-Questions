#include "bits/stdc++.h"
using namespace std;



// Time Complexity

// Building the adjacency list:

// O(E)
// Processing the priority queue:
// In the worst case, each edge can cause an insertion into the priority queue.
// Each push/pop operation takes O(log M), where M is the number of elements in the heap.
// In the worst case, the heap size can grow to O(E).

// Therefore:

// O(ElogE)
// 	​


// Since in a graph E≥V, you'll also commonly see this written as:

// O(ElogV)
// 	​


// because logE and logV differ only by a constant factor for sparse graphs. For interview purposes, O(E log V) is the standard way to express the complexity.

// Space Complexity

// You are storing:

// Adjacency list:

// O(E)

// Distance array:

// O(V)
// Priority queue:
// In the worst case, it can contain up to O(E) states.

// So the total space complexity is:

// O(V+E)
// ​


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adjList(n);

        for(auto& flight:flights){
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];

            adjList[from].push_back({to,price});
        }

        vector<int>dist(n+1,INT_MAX);

        dist[src] = 0;
        priority_queue<
           pair<int,pair<int,int>>,
           vector<pair<int,pair<int,int>>>,
           greater<pair<int,pair<int,int>>>
        > minHeap;



        minHeap.push({0,{0,src}});

        while(!minHeap.empty()){
            auto flight = minHeap.top();

            int stop = flight.first;
            int price = flight.second.first;
            int node = flight.second.second;
            minHeap.pop();

            if(stop>k)
               continue;


            for(auto& it:adjList[node]){
                 int adjNode = it.first;
                 int adjPrice = it.second;
                 int newStop = stop + 1;
                 if(adjPrice + price < dist[adjNode] && stop<=k){
                      dist[adjNode] = adjPrice + price;

                      minHeap.push({newStop,{dist[adjNode],adjNode}});
                 } 
            }
        }


        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};


// Correct Solution given by chatgpt

// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

//         vector<vector<pair<int,int>>> adjList(n);

//         for(auto &flight : flights){
//             int from = flight[0];
//             int to = flight[1];
//             int price = flight[2];

//             adjList[from].push_back({to, price});
//         }

//         // dist[node][stops] = minimum cost to reach node using 'stops' edges
//         vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

//         priority_queue<
//             pair<pair<int,int>, int>,
//             vector<pair<pair<int,int>, int>>,
//             greater<pair<pair<int,int>, int>>
//         > minHeap;

//         dist[src][0] = 0;

//         minHeap.push({{0, src}, 0});

//         while(!minHeap.empty()){

//             auto flight = minHeap.top();
//             minHeap.pop();

//             int price = flight.first.first;
//             int node = flight.first.second;
//             int stops = flight.second;

//             if(node == dst)
//                 return price;

//             if(stops == k + 1)
//                 continue;

//             for(auto &it : adjList[node]){

//                 int adjNode = it.first;
//                 int adjPrice = it.second;

//                 int newCost = price + adjPrice;

//                 if(newCost < dist[adjNode][stops + 1]){

//                     dist[adjNode][stops + 1] = newCost;

//                     minHeap.push({{newCost, adjNode}, stops + 1});
//                 }
//             }
//         }

//         return -1;
//     }
// };

