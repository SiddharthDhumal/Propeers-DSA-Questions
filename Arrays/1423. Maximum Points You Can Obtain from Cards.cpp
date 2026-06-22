// TC - O(k) and SC - O(1)

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
          int n = cardPoints.size();
          if(n==1) return cardPoints[0];
          int sum = 0;
          int right =  n - 1;
          int left = 0;

          while(right>=n-k){
             sum += cardPoints[right];
             right--;
          }

          int maxScore = sum;
          right = n - k;

          while(left<k){
             sum -= cardPoints[right];
             right++;
             sum += cardPoints[left];
             left++;
             maxScore = max(sum,maxScore);
          }

          return maxScore;
    }
};