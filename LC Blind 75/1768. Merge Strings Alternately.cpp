#include <bits/stdc++.h>
using namespace std;


// tc - O(n + m) and sc - O(n + m)


// Time Complexity: ✅ O(n + m)

// Let:

// n = word1.size()
// m = word2.size()

// Your loops are:

// while(i < n && j < m)

// Runs min(n, m) times.

// while(i < n)

// Runs at most n times.

// while(j < m)

// Runs at most m times.

// Each character from both strings is processed exactly once.

// So,

// O(min(n,m))+O(n−min(n,m))+O(m−min(n,m))=O(n+m)

// ✅ Time Complexity = O(n + m)


// Space Complexity: ✅ O(n + m)
// Suppose

// word1 = "abc"
// word2 = "pqrs"

// Then

// ans = "apbqcrs"

// Its length is

// 3 + 4 = 7

// In general,

// ans.size() = n + m

// So the extra memory used is proportional to the input size.

// Space Complexity = O(n + m)

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
          int n = word1.size();
          int m = word2.size();
          int i = 0, j = 0;
          string ans = "";

          while(i<n && j <m){
              ans += word1[i];
              ans += word2[j];
              i++;
              j++;
          }

          while(i<n){
             ans += word1[i];
             i++;
          }

          while(j<m){
             ans += word2[j];
             j++;
          }

          return ans;
    }
};