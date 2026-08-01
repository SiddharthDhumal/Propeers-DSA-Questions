#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC - O(n) and SC - O(n)
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>freq;
        
        for(int num:arr){
            freq[num]++;
        }
        
        unordered_set<int>seen;

        for(auto& it:freq){
            if(seen.count(it.second)) return false;
            seen.insert(it.second);
        }

        return true;
    }
};