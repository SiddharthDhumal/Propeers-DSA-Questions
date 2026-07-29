#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(m), where n is the length of s and m is the length of t.
// Space Complexity: O(1).

class Solution {
public:
    bool isSubsequence(string s, string t) {
         int n = s.size();
         int m = t.size();
         

         int i=0, j =0;

         while(i<n && j<m){
             if(s[i]==t[j]){
                i++;
                j++;
             }else{
                j++;
             }
         }

         if(i<n) return false;

         return true;
    }
};