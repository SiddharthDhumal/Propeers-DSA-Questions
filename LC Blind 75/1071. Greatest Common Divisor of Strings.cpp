#include <bits/stdc++.h>
using namespace std;

// Complexity
// Time: O(n + m)
// Comparing str1 + str2 with str2 + str1 takes O(n + m).
// Computing the GCD of two lengths is O(log(min(n, m))), which is negligible compared to the string operations.
// Extracting the substring of length gcd(len1, len2) is at most O(min(n, m)).
// Overall complexity is O(n + m).
// Space: O(n + m)
// The concatenated strings str1 + str2 and str2 + str1 require additional space proportional to their combined lengths.
// If you ignore the space used by temporary concatenations created by the language runtime, the algorithm itself uses only O(1) auxiliary variables. However, in C++, these concatenations allocate memory, so the practical space complexity is O(n + m).


class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
          
          // If they don't share the same repeating pattern
          if(str1 + str2 != str2 + str1)
             return "";
          
          // Greatest common divisor of lengths
          int length = gcd(str1.size(),str2.size());
          
          // First 'len' characters form the answer
          return str1.substr(0,length);

    }
};