#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    //we can solve this question using dp very easily and that's the optimal solution for this but I tried using dijkestra algorithm here.
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();
        int START = n;
        int TOP = n + 1;
        // Total nodes = n stairs + START + TOP
        vector<vector<pair<int,int>>>adjList(n+2);

         // START -> 0 and START -> 1
        adjList[START].push_back({0, cost[0]});
        adjList[START].push_back({1, cost[1]});
        
        // Stair edges
        for(int i =0;i<n-2;i++){
            adjList[i].push_back({i+1,cost[i+1]});
            adjList[i].push_back({i+2,cost[i+2]});
        }
        
        // Last two stairs can reach TOP for free
        adjList[n - 2].push_back({TOP, 0});
        adjList[n - 1].push_back({TOP, 0});


        vector<int>dist(n+2,INT_MAX);

        dist[START] = 0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;

        minHeap.push({0,START});

        while(!minHeap.empty()){
            auto it = minHeap.top();
            int currCost = it.first;
            int step = it.second;
            minHeap.pop();

            if(dist[step]<currCost)
               continue;
            
            for(auto& it:adjList[step]){
                int adjStep = it.first;
                int adjCost = it.second;

                if(dist[adjStep]> adjCost + currCost){
                     dist[adjStep] = adjCost + currCost;
                     minHeap.push({dist[adjStep],adjStep});
                }
            }
        }


        return dist[TOP];
    }
};

// Time Complexity
// Building graph: O(n)
// Dijkstra: O((V + E) log V)

// Here,

// V = n + 2
// E ≈ 2n

// So,

// O(nlogn)
// Space Complexity
// Adjacency List: O(n)
// Distance Array: O(n)
// Priority Queue: O(n)

// Overall,

// O(n)
// Interview Perspective

// If you write this solution in an interview, it is correct, but most interviewers will ask:

// "Can you do better?"

// The expected solution is DP because:

// DP: O(n) time, O(1) space (after optimization).
// Dijkstra: O(n log n) time, O(n) space.

// A strong interviewer at companies like Google or Atlassian would appreciate that you recognized it as a graph, but they would expect you to further observe that the graph is just a linear DAG, making DP the more natural and optimal solution.

// do a dry run for this code and it's tc and sc explain

// Let's dry run the Dijkstra solution step by step using the first example.

// Example
// cost = [10, 15, 20]

// There are 3 stairs.

// We create two extra nodes:

// Stairs:
// 0
// 1
// 2

// START = 3
// TOP   = 4
// Step 1: Build the graph

// The graph becomes

//           (10)
// START ----------> 0
//    \
//     \(15)
//       \
//        ---> 1

// 0 --15--> 1
// 0 --20--> 2

// 1 --------> TOP (0)

// 2 --------> TOP (0)

// Notice:

// From START you can choose step 0 or step 1.
// Last two stairs connect to TOP with cost 0.
// Step 2: Initialize

// Distance array

// Node

// 0 : INF
// 1 : INF
// 2 : INF
// START : 0
// TOP : INF

// Priority Queue

// (0, START)
// Step 3

// Pop

// (0, START)

// Current node

// START

// Neighbours

// 0 (cost 10)

// 1 (cost 15)

// Update

// dist[0]=10

// dist[1]=15

// Heap

// (10,0)

// (15,1)
// Step 4

// Pop

// (10,0)

// Current Cost

// 10

// Neighbours

// 1

// 2
// Move to 1

// New Cost

// 10+15

// =

// 25

// Current

// dist[1]=15

// 25 is worse.

// Ignore.

// Move to 2

// New Cost

// 10+20

// =

// 30

// Update

// dist[2]=30

// Heap

// (15,1)

// (30,2)
// Step 5

// Pop

// (15,1)

// Neighbour

// TOP

// Cost

// 15+0

// =

// 15

// Update

// dist[TOP]=15

// Heap

// (15,TOP)

// (30,2)
// Step 6

// Pop

// TOP

// Done.

// Answer

// 15

// Which matches the expected answer.

// Why does this work?

// Think of

// START

// as

// "I haven't stepped on any stair yet."

// It gives you two choices

// START

// ↓

// 0

// or

// ↓

// 1

// because the problem allows you to start from either stair.

// Similarly,

// TOP

// is

// "I've crossed all the stairs."

// Once you're on either of the last two stairs,

// you can climb to the floor for free.

// That's why

// Last Stair

// ↓

// TOP

// cost = 0
// Time Complexity

// Let's derive it.

// Step 1

// Vertices

// We have

// n stairs

// +

// START

// +

// TOP

// Total

// V=n+2

// Ignore constants.

// V=n
// Step 2

// Edges

// Every stair has at most

// 2 outgoing edges

// Example

// i

// ↓

// i+1

// ↓

// i+2

// Last two stairs

// ↓

// TOP

// START

// ↓

// 0

// ↓

// 1

// Total edges are approximately

// 2n

// Therefore

// E=O(n)
// Step 3

// Dijkstra Complexity

// Standard formula

// O((V+E)logV)

// Substitute

// V=n

// E=n
// O((n+n)logn)
// O(2nlogn)

// Ignore constants

// O(nlogn)
// 	​

// Space Complexity
// Adjacency List

// Stores

// 2 edges per stair

// Total

// O(n)
// Distance Array

// One value per node

// O(n)
// Priority Queue

// Worst case

// Every node enters heap

// O(n)

// Overall

// O(n)
// 	​

// But why is DP better?

// Notice something in the graph:

// 0

// ↓

// 1

// ↓

// 2

// ↓

// TOP

// There are no cycles.

// Every edge only goes forward.

// Also, to reach stair i, you only need information from:

// i-1

// and

// i-2

// So instead of running Dijkstra, you can directly write the recurrence:

// dp[i] = cost[i] + min(dp[i-1], dp[i-2])

// This gives:

// Time Complexity: O(n)
// Space Complexity: O(1) (after optimization)

// That's why interviewers expect the DP solution even though the Dijkstra solution is correct. The graph has a very simple linear structure, so DP exploits that structure more efficiently.

// how start becomes 0 all of sudden we declared it as n right ? 

// Excellent catch! This is exactly the kind of question you should ask. The confusion comes from mixing up the node number with the distance/cost.

// Let's look at the code carefully.

// We declared

// int START = n;
// int TOP = n + 1;

// Suppose

// cost = [10, 15, 20]

// Then

// n = 3

// Node 0 = Stair 0
// Node 1 = Stair 1
// Node 2 = Stair 2

// Node 3 = START
// Node 4 = TOP

// So the graph looks like

//            START (3)
//           /         \
//       cost=10     cost=15
//         /             \
//       (0)            (1)
//        |\             |
//        | \            |
//     15 | 20           |20
//        |   \          |
//       (1)  (2)--------|
//         \      \
//         0       0
//          \      \
//           \     TOP (4)

// Notice that START is node 3, not node 0.

// Now look at Dijkstra initialization

// We wrote

// dist[START] = 0;

// This means

// dist[3] = 0;

// It does not mean

// dist[0] = 0;

// The distance array becomes

// Node	Meaning	Distance
// 0	Stair 0	INF
// 1	Stair 1	INF
// 2	Stair 2	INF
// 3	START	0
// 4	TOP	INF
// Then we push
// minHeap.push({0, START});

// which is

// minHeap.push({0, 3});

// The heap contains

// (cost = 0, node = 3)

// We are standing at the START node, not at stair 0.

// First iteration

// We pop

// (cost = 0, node = 3)

// Now we explore all neighbours of node 3.

// Who are they?

// adjList[START].push_back({0, cost[0]});
// adjList[START].push_back({1, cost[1]});

// So START has two outgoing edges:

// 3 --10--> 0

// 3 --15--> 1

// We relax them.

// Going to stair 0
// New Cost

// 0 + 10 = 10

// Update

// dist[0] = 10;

// Push

// (10,0)
// Going to stair 1
// New Cost

// 0 + 15 = 15

// Update

// dist[1] = 15;

// Push

// (15,1)

// Now the heap becomes

// (10,0)

// (15,1)

// Only after processing START do we reach stair 0 or stair 1.

// Why did we create START?

// Without START, we'd have two possible starting positions:

// Start at 0

// or

// Start at 1

// Dijkstra normally assumes one source node.

// So we create a fake node:

// START

// that connects to both valid starting stairs.

// Instead of writing

// Run Dijkstra from 0

// Run Dijkstra from 1

// Take minimum

// we write

// Run Dijkstra once

// from START

// This is a common graph modeling trick.

// Think of START as a railway station

// Imagine you're at a railway station.

// You have two trains:

// START

//    |

//    +------> Stair 0 (ticket costs $10)

//    |

//    +------> Stair 1 (ticket costs $15)

// Initially, you're not on either stair.

// You're at the station (START).

// The first move is choosing which train (starting stair) to take.

// So:

// START is node n (3 in this example).
// Its distance is 0 because you're already there.
// Only after leaving START do you pay the cost of stair 0 or stair 1.

// That's why we initialize:

// dist[START] = 0;

// and not

// dist[0] = 0;

// because node 0 is not the source anymore. The source is the virtual START node.

// then what is the purpose of TOP ? and why START starts with n only can't we give it value of something else ?

// Excellent question. This is actually a graph modeling concept. Once you understand this, you'll be able to convert many DP problems into graph problems.

// Let's answer both questions.

// Question 1: What is the purpose of TOP?

// The purpose of TOP is to represent the destination.

// Look at the problem statement carefully:

// Return the minimum cost to reach the top of the floor.

// Notice it doesn't say:

// Reach the last stair.

// These are different.

// Example

// Suppose

// cost = [10,15,20]

// There are only 3 stairs.

// Index

// 0

// 1

// 2

// Where is the top?

// It is after stair 2.

// 0 ---- 1 ---- 2 ---- TOP

// TOP is not an actual stair.

// Why can't we stop at stair 2?

// Imagine you're standing here:

//           TOP
//            ▲
//            |
// 0 ---- 1 ---- 2

// You're still on stair 2.

// The problem says

// Reach the floor.

// You still need one final climb.

// That last climb costs

// 0

// because the floor itself has no fee.

// So we create

// 2 ----0----> TOP
// What about stair 1?

// From stair 1 you can climb two steps.

// So

// 1 ----0----> TOP

// also exists.

// The graph becomes

//              TOP
//             ▲   ▲
//            /     \
//           0       0
//          /         \
// 0 ---- 1 --------- 2
// Why not simply return min(dist[n-1], dist[n-2])?

// Actually...

// You can.

// Because

// Last stair

// ↓

// TOP

// costs

// 0

// So

// distance(TOP)

// =

// min(distance(last stair),

// distance(second last stair))

// Adding a TOP node is simply a cleaner graph model.

// Question 2: Why START = n?

// Suppose

// n = 3

// Current nodes are

// 0

// 1

// 2

// Can we make START equal to

// 0

// No.

// Because

// 0

// already represents

// First stair

// Every node number must be unique.

// So we need a new node.

// The next unused number is

// 3

// which is

// START = n;

// Similarly,

// 4

// is unused.

// So

// TOP = n+1;
// Can I use START = 100?

// Absolutely.

// You could write

// START = 100;
// TOP = 101;

// if you also create

// vector<vector<pair<int,int>>> adj(102);

// because node 100 must exist.

// Why don't we do that?

// Suppose

// n = 5

// Nodes already used are

// 0

// 1

// 2

// 3

// 4

// The next free number is

// 5

// No space is wasted.

// If we use

// 100

// then we'd need an adjacency list of size at least 101, even though we only need 7 nodes.

// Using

// START = n;
// TOP = n+1;

// is simply the most memory-efficient and natural numbering.

// Think of START and TOP as "fake" nodes

// Imagine the real problem looks like this:

//             Floor
//               ▲
//               |
//         0      0
//          \    /
//           \  /
// 0 ---- 1 ---- 2

// ^

// |

// Start

// The graph doesn't have a single source or a single destination.

// So we introduce two imaginary nodes.

//           TOP
//            ▲
//           / \
//          /   \
//         1     2
//        ▲
//       /
// START
//  /  \
// 0    1

// Now the graph has

// Exactly one source (START)
// Exactly one destination (TOP)

// That makes Dijkstra straightforward.

// This is a common interview trick

// Many graph problems use virtual nodes.

// Examples:

// Multi-source BFS

// Instead of starting BFS from 10 different sources,

// create one fake node:

// FAKE SOURCE

//  / |  \

// A B C
// Multi-destination problems

// Instead of checking

// Can I reach A?

// Can I reach B?

// Can I reach C?

// create

// A

//  \

//   DESTINATION

//  /

// B

// /

// C
// This problem
// START

//  / \

// 0   1

// ...

// n-2   n-1

//  \     /

//    TOP
// The key takeaway

// Whenever a problem has:

// Multiple valid starting points, think about adding a virtual START node.
// Multiple valid ending points, think about adding a virtual TOP/DESTINATION node.

// This is a very common graph-modeling technique in interviews. Once you start recognizing it, many seemingly awkward graph problems become much cleaner to solve.