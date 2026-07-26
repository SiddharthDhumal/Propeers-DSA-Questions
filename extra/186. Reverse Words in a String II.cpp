#include "bits/stdc++.h"
using namespace std;

// Complexity
// Time: O(n)
// Reverse entire array: O(n)
// Reverse each word: total O(n) (each character is part of exactly one word reversal)
// Space: O(1)
// Everything is done in place.

class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(),s.end());
        
        int start = 0;

        for(int end=0;end<=s.size();end++){
            if(end==s.size() || s[end]==' '){
                 reverse(s.begin()+start,s.begin()+end);
                 start = end + 1;
            }
        }
    } 
};