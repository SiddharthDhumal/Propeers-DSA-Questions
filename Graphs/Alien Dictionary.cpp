#include "bits/stdc++.h"
using namespace std;

class Solution {
//   private:
//     bool checkCycle(int node,vector<vector<int>>& adjList,vector<int>& visited){
//          if(visited[node]==1)
//             return true;
         
//          if(visited[node]==2)
//             return false;
         
//          visited[node] = 1;
         
//          for(auto& it:adjList[node]){
//               if(checkCycle(it,adjList,visited))
//                   return true;
//          }
         
//          visited[node] = 2;
         
//          return false;
//     }
    
//     void dfs(int node,vector<vector<int>>& adjList,vector<int>& topoVisited,stack<int>&st){
//         if(topoVisited[node])
//             return;
        
//         topoVisited[node] = 1;
        
//         for(auto& it:adjList[node]){
//              if(!topoVisited[it]){
//                  dfs(it,adjList,topoVisited,st);
//              }
//         }
        
//         st.push(node);
//     }
//   public:
//     string findOrder(vector<string> &words) {
//         // code here
//         vector<int>visited(26,0);
        
//         vector<vector<int>>adjList(26);
//         vector<int>present(26,0);
        
//         for(auto& word:words){
//             for(char ch:word){
//                  present[ch-'a'] = 1;
//             }
//         }
        
//         for(int i=0;i<words.size()-1;i++){
//             string currWord = words[i];
//             string nextWord = words[i+1];
            
           
//             int size = min(currWord.size(), nextWord.size());

//             bool foundDifference = false;
            
//             for(int j=0;j<size;j++){
//                 if(currWord[j]!=nextWord[j]){
//                     adjList[currWord[j] - 'a'].push_back(nextWord[j] - 'a');
//                     foundDifference = true;
//                     break;
//                 }
                
//             }
            
//             // Invalid case:
//             // Example:
//             // "abcd"
//             // "ab" 
//             if (!foundDifference && currWord.size() > nextWord.size()) {
//                  return "";
//             }
//         }
        
        
//         for(int i=0;i<26;i++){
//             if(!visited[i] && present[i]){
//                 if(checkCycle(i,adjList,visited)){
//                      return ""; 
//                 }
//             }
//         }
        
        
//         vector<int>topoVisited(26,0);
        
//         stack<int>st;
        
//         for(int i=0;i<26;i++){
//             if(present[i] && !topoVisited[i]){
//                 dfs(i,adjList,topoVisited,st);
//             }
//         }
        
        
//         string answer = "";
        
//         while(!st.empty()){
//             answer += char(st.top() + 'a');
            
//             st.pop();
//         }
        
//         return answer;
//     }



  public:
    string findOrder(vector<string> &words) {
        
        vector<vector<int>>adjList(26);
        
        vector<int>present(26,0);
        vector<int>indegree(26,0);
        queue<int>q;
        int wordCnt = 0;
        
        for(auto& word:words){
             for(char ch:word){
                  if(present[ch-'a']==0) wordCnt++;
                  present[ch-'a'] = 1;
             }
        }
        
        
        for(int i=0;i<words.size()-1;i++){
            string currWord = words[i];
            string nextWord = words[i+1];
            
            int size = min(currWord.size(),nextWord.size());
            
            bool foundDifference = false;
            
            for(int j=0;j<size;j++){
                if(currWord[j]!=nextWord[j]){
                    adjList[currWord[j]-'a'].push_back(nextWord[j]-'a');
                    foundDifference = true;
                    indegree[nextWord[j]-'a']++;
                    break;
                }
            }
            
            if(foundDifference==false && currWord.size() > nextWord.size()){
                return "";
            }
            
        }
        
        
        for(int i=0;i<indegree.size();i++){
            if(present[i] && indegree[i]==0){
                q.push(i);
            }
        }
        
        string answer = "";
        
        int cycleCheck = 0;
        
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            cycleCheck++;
            
            for(auto& it:adjList[node]){
                 indegree[it]--;
                 
                 if(present[it] && indegree[it]==0){
                     q.push(it);
                 }
            }
            
            answer += char(node + 'a');
        }
        
        if(cycleCheck!=wordCnt) return "";
        
        return answer;
    
  }
 


// Complexity

// Let:

// N = number of words
// L = total number of characters in all words
// V = number of distinct characters (≤ 26)
// E = number of ordering constraints

// Time Complexity

// Mark characters: O(L)
// Build graph: O(L) (each adjacent pair is compared up to the shorter word)
// Cycle detection: O(V + E)
// Topological sort: O(V + E)

// Overall:

// O(L+V+E)
// 	​


// Since V≤26, this is effectively dominated by processing the input words.

// Auxiliary Space

// Adjacency list: O(V + E)
// Two visited arrays: O(V)
// Stack: O(V)

// Overall:

// O(V+E)
// 	​


// This is the standard DFS solution for the Alien Dictionary problem.


};