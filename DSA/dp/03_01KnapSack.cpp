#include <bits/stdc++.h>
using namespace std;

int dfs(int W, vector<int>&wt, vector<int>&val, int n, vector<vector<int>>&dp) {
  // base case:
  if (n==0 || W==0) return 0;

  // if already solved:
  if (dp[n][W] != -1) return dp[n][W];

  // make a choice if given weight is valid
  if (wt[n-1] <= W) {
    return dp[n][W] = max(
      // either we take this item --> value gets added, weight capacity is reduced
      val[n-1] + dfs(W-wt[n-1], wt, val, n-1, dp),
      // or we skip this item
      dfs(W, wt, val, n-1, dp)
    );
  }

  // if item heavier than capacity, we skip the item.
  return dp[n][W] = dfs(W, wt, val, n-1, dp);
}

int knapsack(int W, vector<int>&wt, vector<int>&val) {
  vector<vector<int>>dp(val.size()+1, vector<int>(W+1, -1));
  return dfs(W, wt, val, val.size(), dp);
}
