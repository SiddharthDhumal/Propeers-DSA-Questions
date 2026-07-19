#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        return ((start[0]+start[1])%2  == (target[0]+target[1])%2);
    }
};


// This problem looks like a graph/BFS problem at first glance, but the intended insight is actually about chessboard coloring (parity).

// Let's build the intuition from scratch.

// Step 1: Color the chessboard

// Imagine the chessboard colored like a normal chessboard.

// B W B W B W B W
// W B W B W B W B
// B W B W B W B W
// W B W B W B W B
// ...

// The color of a square can be determined by:

// (x + y) % 2

// 0 -> Black
// 1 -> White

// For example,

// (0,0) -> Black
// (0,1) -> White
// (1,0) -> White
// (1,1) -> Black
// Step 2: What happens after one knight move?

// A knight always moves

// (+2,+1)
// (+2,-1)
// (-2,+1)
// (-2,-1)
// (+1,+2)
// (+1,-2)
// (-1,+2)
// (-1,-2)

// Let's see how the parity changes.

// Suppose we're at

// (x, y)

// After moving

// (x+2, y+1)

// New parity

// (x + 2 + y + 1)
// = (x + y + 3)

// Since

// 3 is odd,

// the parity flips.

// Similarly,

// 2 + (-1) = 1
// -2 + 1 = -1
// 1 + 2 = 3

// Every knight move changes

// x+y

// by an odd number.

// An odd change always flips parity.

// Therefore

// Every knight move changes

// Black ↔ White

// Always.

// Step 3: What happens after two moves?

// Move 1

// Black → White

// Move 2

// White → Black

// So after two moves you're back on the same color.

// Pattern
// 0 moves
// same color

// 1 move
// opposite color

// 2 moves
// same color

// 3 moves
// opposite color

// 4 moves
// same color

// So

// Even number of moves
// → Same color

// Odd number of moves
// → Opposite color

// This is the entire trick behind the problem.

// Example 1
// start = (1,1)

// 1+1 = 2
// even
// Black

// Target

// (2,2)

// 2+2=4
// even
// Black

// Same color

// ↓

// Need even moves

// Answer = true

// Example 2
// start = (4,5)

// 4+5=9
// odd
// White

// Target

// (6,6)

// 6+6=12
// even
// Black

// Different colors

// ↓

// Need odd moves

// Question asks for even moves

// Answer = false

// Why does this always work?

// Think of the chessboard as a graph.

// Every square is a node.
// Every knight move is an edge.

// Since every edge connects opposite colors, the graph is bipartite.

// A property of bipartite graphs:

// Paths of even length end in the same partition (same color).
// Paths of odd length end in the opposite partition.

// The knight graph on a chessboard is bipartite because every knight move flips the square color.

// So the solution becomes

// Just compare the parity of

// startX + startY

// and

// targetX + targetY

// If they're equal, the squares have the same color, so the knight can reach the target in an even number of moves.

// class Solution {
// public:
//     bool evenNumberOfMoves(vector<int>& start, vector<int>& target) {
//         return ((start[0] + start[1]) % 2) ==
//                ((target[0] + target[1]) % 2);
//     }
// };
// Time Complexity
// O(1)
// Space Complexity
// O(1)
// Interview takeaway

// Whenever you see a chessboard problem involving parity, reachability, or even/odd number of moves, one of the first things to check is whether the board can be viewed as a bipartite graph. Recognizing that a knight always alternates square colors turns what looks like a BFS problem into a constant-time parity check.

// Input: start = [4,5], target = [6,6]

// do dry run for this example

// Let's dry run it step by step.

// Input
// start = [4,5]
// target = [6,6]
// Step 1: Find the color of the start cell

// Coordinates:

// (4,5)

// Compute:

// x + y = 4 + 5 = 9

// Now check parity:

// 9 % 2 = 1 (Odd)

// Let's say:

// Odd  -> White
// Even -> Black

// So,

// (4,5) = White
// Step 2: Find the color of the target cell

// Coordinates:

// (6,6)

// Compute:

// 6 + 6 = 12

// Parity:

// 12 % 2 = 0 (Even)

// So,

// (6,6) = Black
// Step 3: Compare the colors
// Start  = White
// Target = Black

// Different colors.

// Step 4: What does that mean?

// Remember the rule:

// After 1 move:
// White → Black

// After 2 moves:
// White → Black → White

// After 3 moves:
// White → Black → White → Black

// Let's make a table.

// Number of Moves	Color
// 0	White
// 1	Black
// 2	White
// 3	Black
// 4	White
// 5	Black

// Notice the pattern:

// Even moves → Same color as start
// Odd moves → Opposite color

// Since the target is Black and the start is White, the knight can only reach it after an odd number of moves.

// Why is the answer false?

// The problem asks:

// Can the knight reach the target in an even number of moves?

// From our observation:

// Even moves  → White
// Target       → Black

// Impossible.

// Therefore,

// return false;
// If you still don't believe it...

// Let's actually perform a few knight moves from (4,5).

// Move 0
// (4,5)   White
// One move

// Possible positions include:

// (6,6)
// (6,4)
// (2,6)
// (2,4)
// (5,7)
// (5,3)
// (3,7)
// (3,3)

// Notice something interesting:

// The target (6,6) is reached immediately in one move.

// Let's verify:

// (4,5) → (6,6)

// Δx = +2
// Δy = +1

// That's a valid knight move.

// So the shortest path is:

// (4,5) → (6,6)

// Number of moves:

// 1

// which is odd.

// Could there also be a path with 3, 5, or 7 moves? Yes, by wandering around before reaching the target. But all such paths will still have odd length because every move flips the square color. There cannot be any even-length path from a White square to a Black square.

// This is exactly why simply comparing the parity of (x + y) is sufficient.