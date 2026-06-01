#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int daysNeeded(vector<int>& weights, int capacity){
         int day = 1;
         int currentLoad = 0;

         for(int w:weights){
            if(currentLoad + w > capacity){
                 day++;
                 currentLoad = 0;
            }

            currentLoad += w;
         }

         return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
          int n = weights.size();
          int low = *max_element(weights.begin(), weights.end()); // min capacity must fit largest package
          int high = accumulate(weights.begin(), weights.end(), 0); // max capacity is sum of all packages
          int answer = 0;
          int cntDays = 0;

          while(low<=high){
             int mid = low + (high-low)/2;

             int requiredDays = daysNeeded(weights,mid);
             
             if (requiredDays <= days) {
                // capacity is enough, try smaller
                answer = mid;
                high = mid - 1;
            } else {
                // capacity too small, try bigger
                low = mid + 1;
            }
          }

          return answer;
    }
};