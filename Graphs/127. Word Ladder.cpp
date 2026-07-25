#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>st(wordList.begin(),wordList.end());
        
        st.erase(beginWord);
        queue<pair<string,int>>q;
        q.push({beginWord,1});

        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();

            if(word==endWord)
                 return level;
            
            string newWord = word;

            for(int i=0;i<word.size();i++){
                char originalChar = word[i];

                for(char ch='a';ch<='z';ch++){
                     newWord[i] = ch;

                     if(st.find(newWord)!=st.end()){
                         q.push({newWord,level+1});
                         st.erase(newWord);
                     }     
                }

                newWord[i] = originalChar;
            }
            
        }

        return 0;
    }
};




// Step 1: Number of words

// Suppose there are

// N = number of words in wordList
// L = length of each word

// For example,

// wordList = ["hot","dot","dog","lot","log","cog"]

// Here

// N = 6
// L = 3
// Step 2: How many times is each word processed?

// Notice this line:

// st.erase(newWord);

// Once a word is visited, it is removed from the set.

// Therefore,

// every word enters the queue at most once.

// So BFS processes at most

// N

// words.

// Step 3: Work done for one word

// Suppose the current word is

// "hit"

// You run

// for(int i = 0; i < word.size(); i++)

// This runs

// L

// times.

// For every position,

// you try

// for(char ch = 'a'; ch <= 'z'; ch++)

// which runs

// 26

// times.

// So for one word, you generate

// L × 26

// candidate words.

// Example:

// hit

// ↓

// ait
// bit
// cit
// ...
// zit

// ↓

// hat
// hbt
// ...
// hzt

// ↓

// hia
// hib
// ...
// hiz
// Step 4: Hash lookup

// Each generated word does

// st.find(newWord)

// Average complexity of unordered_set::find() is

// O(1)

// So each candidate word costs

// O(1)
// Total Time Complexity

// We process at most

// N

// words.

// For each word,

// we generate

// L × 26

// neighbors.

// So

// O(N × L × 26)

// Since 26 is a constant,

// O(N×L)
// 	​

// But wait...

// Some interviewers write the complexity as

// O(N×L×26)

// Both are correct.

// Since

// 26

// is constant,

// we usually simplify it to

// O(NL)
// 	​

// Space Complexity

// Let's count each data structure.

// 1. HashSet
// unordered_set<string> st;

// Stores

// N

// words.

// Space

// O(N)
// 2. Queue

// Worst case,

// every word is waiting in the queue.

// O(N)
// 3. Temporary string
// string newWord = word;

// Length

// L

// Space

// O(L)
// Total Space
// HashSet

// ↓

// O(N)

// +

// Queue

// ↓

// O(N)

// +

// Temporary String

// ↓

// O(L)

// Overall

// O(N+L)
// 	​


// Since usually

// N >> L

// people often write

// O(N)
// 	​

// Final Answer
// Complexity	Value
// Time Complexity	O(N × L × 26) = O(N × L)
// Space Complexity	O(N + L) ≈ O(N)

// where:

// N = number of words in wordList
// L = length of each word