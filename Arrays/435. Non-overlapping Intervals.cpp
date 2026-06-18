#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
          
          int n = intervals.size();

          if(n==1) return 0;

          sort(intervals.begin(),intervals.end());

          int removals = 0;
          vector<int> last = intervals[0];

          for(int i=1;i<n;i++){
              if(intervals[i][0]<last[1]){
                  removals++;
                  if(intervals[i][1] < last[1]){
                     last = intervals[i];
                  }
              }else{
                  last = intervals[i];
              }
          }
          
          return removals;
    }
};