#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool possibleCandiesPile(vector<int>& candies, long long k,int possiblePile){
          long long child = 0;

          for(int i=0;i<candies.size();i++){
              if(candies[i]>= possiblePile){
                  int rem = candies[i] / possiblePile;
                  child += rem;
              }

              if(child>=k) return true;
          }

          return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        int high = *max_element(candies.begin(),candies.end());
        int maxCandies = 0;

        long long possibleCandies = accumulate(candies.begin(),candies.end(),0LL);

        if(possibleCandies<k) return maxCandies;
        
        while(low<=high){
            int mid = low + (high-low)/2;

            if(possibleCandiesPile(candies,k,mid)){
                  maxCandies = mid;
                  low = mid + 1;
            }else{
                  high = mid - 1;
                  
            }
        }

        return maxCandies;
    }
};