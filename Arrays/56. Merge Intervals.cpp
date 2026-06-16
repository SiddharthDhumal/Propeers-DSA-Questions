#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    static void compare(vector<vector<int>>& intervals){
         sort(intervals.begin(),intervals.end(),
          [](const vector<int>& a, const vector<int>& b){
                return a[0] < b[0];
          });
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        compare(intervals);

        vector<vector<int>> ans;

        ans.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++){
            vector<int>& last = ans.back();

            if(intervals[i][0]<=last[1]){
                // Overlap exists
                last[1] = max(last[1], intervals[i][1]);
            }else{
                // No overlap
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};