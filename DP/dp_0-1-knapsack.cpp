#include <bits/stdc++.h>
using namespace std;

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