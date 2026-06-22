// TC - O(n) and SC - O(k) where k is fixed size and for this problem it's 2

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
          int n = fruits.size();
          if(n==1) return 1;
          unordered_map<int,int>fruitsFreq;
          int left = 0;
          int right = 1;
          int maxLength = INT_MIN;
          fruitsFreq[fruits[left]]++;
         
          while(right<n){
              fruitsFreq[fruits[right]]++;
              while(fruitsFreq.size()>2){
                  fruitsFreq[fruits[left]]--;
                  if(fruitsFreq[fruits[left]]==0){
                      fruitsFreq.erase(fruits[left]);
                  }
                
                  left++;
              }
              maxLength = max(right-left+1,maxLength);
              right++;
          }

          return maxLength;
    }
};