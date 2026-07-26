#include <bits/stdc++.h>
using namespace std;


// Time Complexity
// First loop
// for(int candy : candies){
//     maxCandies = max(maxCandies, candy);
// }

// Finds the maximum element.

// Time: O(n)

// Second loop
// for(int candy : candies){
//     if(candy + extraCandies >= maxCandies)
//         ans.push_back(true);
//     else
//         ans.push_back(false);
// }

// Checks each child once.

// Time: O(n)

// Overall

// O(n) + O(n) = O(n)

// ✅ Time Complexity = O(n)

// Space Complexity

// You create

// vector<bool> ans;

// which stores one result for every child.

// So,

// Space = O(n)

// You cannot do better because the problem itself asks you to return n boolean values.

// So:

// Auxiliary Space: O(1) (apart from the output)
// Total Space: O(n) (including the returned vector)



class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        int maxCandies = 0;

        for(int candy:candies){
             maxCandies = max(maxCandies,candy);
        }

        for(int candy :candies){
            if(candy + extraCandies >= maxCandies){
                 ans.push_back(true);
            }else{
                 ans.push_back(false);
            }
        }

        return ans;
    }
};