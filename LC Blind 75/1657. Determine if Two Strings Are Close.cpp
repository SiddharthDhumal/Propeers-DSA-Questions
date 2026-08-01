#include <bits/stdc++.h>
using namespace std;


// Time Complexity: O(n)

// Why?

// Count frequencies of word1 → O(n)
// Count frequencies of word2 → O(n)
// Check 26 characters → O(26) = O(1)
// Sort 26 elements twice → O(26 log 26) = O(1)

// So,

// O(n) + O(n) + O(1) + O(1)

// = O(n)

// Here, n is the length of the strings.

// Space Complexity: O(1)

// Why?

// We create only two arrays:

// vector<int> freq1(26);
// vector<int> freq2(26);

// Their size is always 26, no matter whether the string length is:

// 10
// 1000
// 100000

// Since the memory used does not grow with the input size, it is considered constant space.

// Easy Interview Answer

// Time Complexity: O(n) because we traverse both strings once, and sorting/checking 26 letters takes constant time.

// Space Complexity: O(1) because we use only two frequency arrays of fixed size 26, irrespective of the input size.

// This is exactly the explanation interviewers expect.

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) 
            return false;
        
        vector<int>freq1(26,0),freq2(26,0);

        for(char ch:word1)
            freq1[ch -'a']++;
        
        for(char ch:word2)
            freq2[ch - 'a']++;
        
        for(int i=0;i<26;i++){
            if((freq1[i]==0) != (freq2[i]==0)) 
                return false; 
        }

        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());

        return freq1 == freq2;
    }
};