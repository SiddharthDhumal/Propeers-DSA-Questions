#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
         int n = points.size();
         if(n==0) return 0;

         sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

         int arrows = 1;
         int arrowPos = points[0][1];

         for(int i=1;i<n;i++){
            if(points[i][0]>arrowPos){
                 arrows++;
                 arrowPos = points[i][1];
            }
         }

         return arrows;
    }
};