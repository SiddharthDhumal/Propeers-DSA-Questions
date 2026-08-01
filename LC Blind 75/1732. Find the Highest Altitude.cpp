#include <bits/stdc++.h>
using namespace std;

// Tc - O(n) and SC - O(n)
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int>prefixSum(n);
        int highestAltitude =  gain[0];
        prefixSum[0] = gain[0];

        for(int i=1;i<n;i++){
            prefixSum[i] = gain[i] + prefixSum[i-1];
            highestAltitude = max(highestAltitude,prefixSum[i]);
        }

        return highestAltitude < 0 ? 0 : highestAltitude;
    }
};