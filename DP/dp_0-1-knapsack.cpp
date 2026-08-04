#include <bits/stdc++.h>
using namespace std;

// Sample Input:
// 1 
// 4
// 1 2 4 5
// 5 4 8 6
// 5
// Sample Output:
// 13

// dfs(4,5)
// │
// ├── Take Item4 (value=6)
// │      │
// │      └── dfs(3,0)
// │              │
// │              └── return 0
// │
// │      Total = 6
// │
// └── Don't Item4
//        │
//        └── dfs(3,5)
//              │
//              ├── Take Item3 (value=8)
//              │      │
//              │      └── dfs(2,1)
//              │              │
//              │              └── dfs(1,1)
//              │                     │
//              │                     ├── Take
//              │                     │      └── dfs(0,0)=0
//              │                     │
//              │                     └── Don't
//              │                            └── dfs(0,1)=0
//              │
//              │      Total = 8+5=13
//              │
//              └── Don't Item3
//                     │
//                     └── dfs(2,5)
//                            │
//                            ├── Take Item2 (value=4)
//                            │      │
//                            │      └── dfs(1,3)
//                            │             │
//                            │             ├── Take
//                            │             │      └── dfs(0,2)=0
//                            │             │
//                            │             └── Don't
//                            │                    └── dfs(0,3)=0
//                            │
//                            │      Total=9
//                            │
//                            └── Don't Item2
//                                   │
//                                   └── dfs(1,5)
//                                          │
//                                          ├── Take
//                                          │      └── dfs(0,4)=0
//                                          │
//                                          └── Don't
//                                                 └── dfs(0,5)=0

int dfs(int index,int remainingWeight,const vector<int>& weight,
const vector<int>& value,vector<vector<int>>& dp){
   if(index==0 || remainingWeight==0)
      return 0;
   
   if(dp[index][remainingWeight]!=-1)
      return dp[index][remainingWeight];
   
   int notTake = dfs(index-1,remainingWeight,weight,value,dp);

   int take = 0;

   if(weight[index-1]<=remainingWeight){
	   take = value[index-1] + 
	   dfs(index-1,remainingWeight-weight[index-1],weight,value,dp);  
   }

   return dp[index][remainingWeight] =  max(take,notTake);

}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n+1,vector<int>(maxWeight+1,-1));
	
	return dfs(n,maxWeight,weight,value,dp);
}