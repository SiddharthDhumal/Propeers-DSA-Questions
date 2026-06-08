#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    // TC - O(2n + nlog(n)) and SC - O(k) where k is number of pairs returned
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
         int n = arr.size();
         vector<vector<int>> answer;
         sort(arr.begin(),arr.end());
         int minDiff = INT_MAX;

         for(int i=0;i<n-1;i++){
            minDiff = min((arr[i+1]-arr[i]),minDiff);    
         }

         for(int i=0;i<n-1;i++){
             if((arr[i+1]-arr[i])==minDiff){
                 answer.push_back({arr[i],arr[i+1]});
             }
         }

         return answer;      
    }
};